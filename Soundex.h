#ifndef SOUNDEX_H_
#define SOUNDEX_H_

#include <string>
#include <unordered_map>

using namespace std;

class Soundex {

	static const size_t MaxCodeLength{4};
	const string NotADigit{"*"};

public:
	string encode(const string &word) const {
		return zeroPad(upperFront(head(word)) + tail(encodedDigits(word)));
	}

private:
	string head(const string &word) const {
		return word.substr(0,1);
	}

	string tail(const string &word) const {
		return word.substr(1);
	}

	string upperFront(const string &word) const {
		return string(1, toupper(static_cast<unsigned char>(word.front())));
	}

	string encodedDigits(const string &word) const {
		string encoding;
		encodedHead(encoding, word);
		encodedTail(encoding, word);
		return encoding;
	}

	void encodedHead(string &encoding, const string &word) const {
		encoding += encodedDigit(word.front());
	}

	void encodedTail(string &encoding, const string &word) const {
		for (auto letter : tail(word)) {
			if (!isComplete(encoding))
				encodedLetter(encoding, letter);
		}
	}

	void encodedLetter(string &encoding, char letter) const {
		auto digit = encodedDigit(letter);
		if (digit != NotADigit && digit != lastDigit(encoding))
			encoding += digit;
	}

	bool isComplete(const string &word) const {
		return word.length() == MaxCodeLength;
	}

	string encodedDigit(char letter) const {
		const unordered_map<char, string> encodings {
			{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
			{'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"},
			{'d', "3"}, {'t', "3"},
			{'l', "4"},
			{'m', "5"}, {'n', "5"},
			{'r', "6"}
		};

		auto it = encodings.find(lower(letter));
		return (it == encodings.end()) ? NotADigit : it->second;
	}

	char lower(char letter) const {
		return tolower(static_cast<unsigned char>(letter));
	}

	string lastDigit(const string &encoding) const {
		if (encoding.empty()) return NotADigit;
		return string(1, encoding.back());
	}

	string zeroPad(const string &word) const {
		auto zerosNeeded = MaxCodeLength - word.length();
		return word + string(zerosNeeded, '0');
	}
};

#endif /* SOUNDEX_H_ */
