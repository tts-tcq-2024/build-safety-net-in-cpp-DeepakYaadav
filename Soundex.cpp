#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

// Function to get the Soundex code for a character
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

// Appends a code to the Soundex string if it's unique and not a repeat
void appendIfUnique(std::string& soundex, char code, char& lastCode) {
    if (code != '\0' && code != lastCode) {
        soundex.push_back(code);
        lastCode = code;
    }
}

// Pads the Soundex string to ensure a length of 4
std::string padWithZeros(const std::string& soundex) {
    return soundex + std::string(4 - soundex.size(), '0');
}

// Builds the Soundex code for a given name
std::string buildSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char lastCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        appendIfUnique(soundex, code, lastCode);
    }

    return padWithZeros(soundex);
}

// Generates the Soundex code for the given name
std::string generateSoundex(const std::string& name) {
    return buildSoundex(name);
}

