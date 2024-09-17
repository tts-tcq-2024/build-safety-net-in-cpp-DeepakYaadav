#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

// Function to map characters to Soundex codes
char mapToSoundexCode(char c) {
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

// Function to append a Soundex code if it's unique and not '0'
void appendSoundex(std::string& soundex, char code, char& prevCode) {
    if (code != '\0' && code != '0' && code != prevCode) {
        soundex.push_back(code);
        prevCode = code;
    }
}

// Function to pad the Soundex code to a length of 4
std::string paddingSoundex(const std::string& soundex) {
    return soundex + std::string(4 - soundex.size(), '0');
}

// Function to build the Soundex code from a name
std::string buildSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    char prevCode = mapToSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = mapToSoundexCode(name[i]);
        appendSoundex(soundex, code, prevCode);
    }

    return paddingSoundex(soundex);
}

// Function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    return buildSoundex(name);
}
