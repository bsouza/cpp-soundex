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

TEST_F(SoundexEncoding, replaces_b_with_digit_1) {
	ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
}
