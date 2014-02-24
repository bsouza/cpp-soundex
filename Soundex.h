#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>

using namespace std;

class Soundex {

public:
	string encode(const string &word) const {
		return zeroPad(word);
	}

private:
	string zeroPad(const string &word) const {
		return word + "000";
	}
};

#endif /* SOUNDEX_H_ */
