#include <string>
#include <cctype>
#include <unordered_map>

char mapToSoundexCode(char c) {
    static const std::unordered_map<char, char> soundexMap = {
        {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
        {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, 
        {'Q', '2'}, {'S', '2'}, {'X', '2'}, {'Z', '2'},
        {'D', '3'}, {'T', '3'}, {'L', '4'}, {'M', '5'}, 
        {'N', '5'}, {'R', '6'}
    };
    
    c = toupper(c);
    auto it = soundexMap.find(c);
    return (it != soundexMap.end()) ? it->second : '0';
}

void appendSoundex(std::string& soundex, char code, char& prevCode) {
    if (code != '0' && code != prevCode) {
        soundex += code;
        prevCode = code;
    }
    
}

std::string paddingSoundex(const std::string& soundex) {
    std::string paddedSoundex = soundex;
    paddedSoundex.resize(4, '0');
    return paddedSoundex;
}

std::string buildSoundex(const std::string& name) {
    std::string soundex(1, toupper(name[0]));
    char prevCode = mapToSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = mapToSoundexCode(name[i]);
        appendSoundex(soundex, code, prevCode);
    }

    return paddingSoundex(soundex);
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";  // Handle empty input
    return buildSoundex(name);
}
