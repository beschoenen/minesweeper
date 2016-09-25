#ifndef HELPERS
#define HELPERS

#include <iostream>
#include <sstream>

using namespace std;

namespace helpers {

	static char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	static char int_to_char(int index) {
		return alphabet[index];
	}

	static int char_to_int(char character) {
		for (int i = 0; i < 26; ++i) {
			if(alphabet[i] == character) {
				return i;
			}
		}

		return -1;
	}

	static string get_identifier(char x, int y) {
		ostringstream o;
		o << x << y;

		return o.str();
	}

	static string get_identifier(int x, int y) {
		return get_identifier(int_to_char(x), y);
	}
}

#endif