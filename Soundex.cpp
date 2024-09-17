#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

// Maps letters to Soundex codes.
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

// Appends a Soundex code to the result if it's unique.
void appendIfUnique(std::string& soundex, char code, char& lastCode) {
    if (code != '\0' && code != lastCode) {
        soundex.push_back(code);
        lastCode = code;
    }
}

// Pads the Soundex code with zeros to ensure it's 4 characters long.
std::string padWithZeros(const std::string& soundex) {
    return soundex + std::string(4 - soundex.size(), '0');
}

// Builds the Soundex code for a given name.
std::string buildSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, std::toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length(); ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '\0' && code != prevCode && soundex.length() < 4) {
            soundex.push_back(code);
            prevCode = code;
        }
    }

    return padWithZeros(soundex);
}

// Generates the Soundex code for a given name.
std::string generateSoundex(const std::string& name) {
    return buildSoundex(name);
}
