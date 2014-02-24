#include "gmock/gmock.h"

class Soundex {

public:
	std::string encode(const std::string& word) const {
		return zeroPad(word);
	}

	std::string zeroPad(const std::string &word) const {
		return word + "000";
	}

};

using testing::Eq;

class SoundexEncoding: public testing::Test {

public:
	Soundex soundex;

};

TEST_F(SoundexEncoding, retains_sole_letter_of_one_letter_word) {
	auto encoded = soundex.encode("A");
	ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, pads_with_zeros_to_ensure_three_digits) {
	auto encoded = soundex.encode("I");
	ASSERT_THAT(encoded, Eq("I000"));
}
