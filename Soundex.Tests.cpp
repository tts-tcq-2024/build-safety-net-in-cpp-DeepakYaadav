#include <gtest/gtest.h>
#include "Soundex.h"

// Test for empty string input
TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

// Test for single character name
TEST(SoundexTest, HandlesSingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
    EXPECT_EQ(generateSoundex("Z"), "Z000");
}

// Test for name with all vowels, where Soundex should be padded with zeros
TEST(SoundexTest, HandlesAllVowels) {
    EXPECT_EQ(generateSoundex("AeIoU"), "A000");
}

// Test for name with distinct Soundex codes for letters
TEST(SoundexTest, HandlesNameWithDifferentSoundexCodes) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
    EXPECT_EQ(generateSoundex("Pfister"), "P236");
}

// Test for names that require padding to ensure the Soundex is 4 characters
TEST(SoundexTest, PadsSoundexToFourCharacters) {
    EXPECT_EQ(generateSoundex("Ray"), "R000");
    EXPECT_EQ(generateSoundex("Bob"), "B100");
}

// Test for mixed case names, ensuring case-insensitivity
TEST(SoundexTest, HandlesNameWithMixedCases) {
    EXPECT_EQ(generateSoundex("aShCrAfT"), "A261");
}

// Test for names with hyphens and spaces, where they should be ignored
TEST(SoundexTest, HandlesNameWithHyphenAndSpaces) {
    EXPECT_EQ(generateSoundex("Smith-Jones"), "S532");
}

// Test for names with silent letters, like "Knuth"
TEST(SoundexTest, HandlesNameWithSilentLetters) {
    EXPECT_EQ(generateSoundex("Knuth"), "K530");
}

// Test for names with consecutive letters that map to the same Soundex code
TEST(SoundexTest, HandlesConsecutiveLettersWithSameCode) {
    EXPECT_EQ(generateSoundex("Bobby"), "B100");
    EXPECT_EQ(generateSoundex("Jackson"), "J250");
}

// Test for different letters mapping to the same Soundex code
TEST(SoundexTest, HandlesDifferentLettersWithSameCode) {
    EXPECT_EQ(generateSoundex("Tymczak"), "T522");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
