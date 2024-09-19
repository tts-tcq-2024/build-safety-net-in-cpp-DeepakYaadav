#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, HandlesEmptyString) {
    EXPECT_EQ(generateSoundex(""), "");
}

TEST(SoundexTest, HandlesSingleCharacterName) {
    EXPECT_EQ(generateSoundex("A"), "A000");
}

TEST(SoundexTest, HandlesAllVowels) {
    EXPECT_EQ(generateSoundex("AeIoU"), "A000");
}

TEST(SoundexTest, HandlesNameWithDifferentSoundexCodes) {
    EXPECT_EQ(generateSoundex("Robert"), "R163");
}

TEST(SoundexTest, PadsSoundexToFourCharacters) {
    EXPECT_EQ(generateSoundex("Ray"), "R000");
}

TEST(SoundexTest, HandlesNameWithMixedCases) {
    EXPECT_EQ(generateSoundex("aShCrAfT"), "A261");
}

TEST(SoundexTest, HandlesNameWithHyphenAndSpaces) {
    EXPECT_EQ(generateSoundex("Smith-Jones"), "S532");
}

TEST(SoundexTest, HandlesNameWithSilentLetters) {
    EXPECT_EQ(generateSoundex("Knuth"), "K530");
}
