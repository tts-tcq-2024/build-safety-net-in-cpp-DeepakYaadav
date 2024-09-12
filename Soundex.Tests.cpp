#include <gtest/gtest.h>
#include "Soundex.h"

// Test for empty string input
TEST(SoundexTest, HandlesEmptyString) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex(""), "");
}

// Test for single character input
TEST(SoundexTest, HandlesSingleCharacter) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("Z"), "Z000");
}

// Test for multi-character name with no repeating Soundex codes
TEST(SoundexTest, HandlesSimpleNames) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Bob"), "B100");
    EXPECT_EQ(soundex.generateSoundex("Sam"), "S500");
    EXPECT_EQ(soundex.generateSoundex("Rubin"), "R150");
}

// Test for names with consecutive characters having the same Soundex code
TEST(SoundexTest, HandlesConsecutiveLettersWithSameCode) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Bobby"), "B100");
    EXPECT_EQ(soundex.generateSoundex("Jackson"), "J250");
}

// Test for handling different characters with the same Soundex code
TEST(SoundexTest, HandlesDifferentLettersWithSameCode) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Pfister"), "P236");
    EXPECT_EQ(soundex.generateSoundex("Tymczak"), "T522");
}

// Test for padding Soundex code with zeros if less than 4 characters
TEST(SoundexTest, HandlesPaddingWithZeros) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("B"), "B000");
}
