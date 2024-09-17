#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

// Get the Soundex code for a given character
char getSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, 
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'}, {'L', '4'}, {'M', '5'}, 
        {'N', '5'}, {'R', '6'}
    };

    c = std::toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '\0';
}

// Appends the code to the Soundex string if it's unique and not a repeat
void appendIfUnique(std::string& soundex, char code, char& lastCode) {
    if (code != '\0' && code != lastCode) {
        soundex.push_back(code);
        lastCode = code;
    }
}

// Pads the Soundex code with zeros to ensure a length of 4
std::string padWithZeros(const std::string& soundex) {
    return soundex + std::string(4 - soundex.size(), '0');
}

// Simplified function to handle the Soundex building process
std::string buildSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    // Helper lambda to process each character in the name
    auto processCharacter = [&](char ch) {
        char currentCode = getSoundexCode(ch);
        appendIfUnique(soundex, currentCode, prevCode);
    };

    // Iterate through the name starting from the second character
    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        processCharacter(name[i]);
    }

    return padWithZeros(soundex);
}

// Generates the Soundex code for the given name
std::string generateSoundex(const std::string& name) {
    return buildSoundex(name);
}
