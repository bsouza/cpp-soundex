#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {

public:
	Soundex soundex;

};

TEST_F(SoundexEncoding, retains_sole_letter_of_one_letter_word) {
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, pads_with_zeros_to_ensure_three_digits) {
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, replaces_consonants_with_appropriate_digits) {
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, ignores_non_alphabetics) {
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, replaces_multiple_consonants_with_digits) {
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, limits_length_to_four_characters) {
	ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u));
}

TEST_F(SoundexEncoding, ignores_vowel_like_letters) {
	ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, combines_duplicate_encoding) {
	ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, uppercases_first_letter) {
	ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, ignores_case_when_encoding_consonants) {
	ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, combines_duplicate_codes_when_2nd_letter_duplicates_1st) {
	ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, does_not_combine_duplicate_encodings_separated_by_vowels) {
	ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}
