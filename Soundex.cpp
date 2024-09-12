#include <string>
#include <cctype>
#include <unordered_map>

class Soundex {
public:
    // Public interface to generate the Soundex code
    std::string generateSoundex(const std::string& name) const {
        if (name.empty()) return "";  
        return buildSoundex(name);
    }

private:
    // Maps characters to Soundex codes
    char mapToSoundexCode(char c) const {
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

    // Appends Soundex code while avoiding duplicates
    void appendSoundex(std::string& soundex, char code, char& prevCode) const {
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    // Pads the Soundex code to a length of 4
    std::string paddingSoundex(const std::string& soundex) const {
        std::string paddedSoundex = soundex;
        paddedSoundex.resize(4, '0');
        return paddedSoundex;
    }

    // Builds the Soundex code based on the name
    std::string buildSoundex(const std::string& name) const {
        std::string soundex(1, toupper(name[0]));
        char prevCode = mapToSoundexCode(name[0]);

        for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
            char code = mapToSoundexCode(name[i]);
            appendSoundex(soundex, code, prevCode);
        }

        return paddingSoundex(soundex);
    }
};
