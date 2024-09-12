#include <gtest/gtest.h>
#include "Soundex.h"

// Test for basic functionality (empty string, single character, padding with zeros)
TEST(SoundexTest, HandlesBasicCases) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex(""), "");
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("Z"), "Z000");
    EXPECT_EQ(soundex.generateSoundex("Bob"), "B100");
}

// Test for multi-character names with simple Soundex codes
TEST(SoundexTest, HandlesSimpleNames) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Sam"), "S500");
    EXPECT_EQ(soundex.generateSoundex("Rubin"), "R150");
    EXPECT_EQ(soundex.generateSoundex("Pfister"), "P236");
}

// Test for names with consecutive letters having the same Soundex code
TEST(SoundexTest, HandlesConsecutiveLettersWithSameCode) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Bobby"), "B100");
    EXPECT_EQ(soundex.generateSoundex("Jackson"), "J250");
}

// Test for ensuring Soundex code is padded with zeros
TEST(SoundexTest, HandlesPaddingWithZeros) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("A"), "A000");
    EXPECT_EQ(soundex.generateSoundex("B"), "B000");
}

// Test for handling different letters with the same Soundex code
TEST(SoundexTest, HandlesDifferentLettersWithSameCode) {
    Soundex soundex;
    EXPECT_EQ(soundex.generateSoundex("Tymczak"), "T522");
}
