#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {

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
