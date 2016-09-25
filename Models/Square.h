#ifndef INTRO_SQUARE_H
#define INTRO_SQUARE_H

#include <iostream>

using namespace std;

class Square {

public:
	Square(bool is_bomb);

	bool get_is_bomb();
	bool get_is_flagged();

	void set_close_bombs(int number);
	void add_close_bomb();
	void toggle_flagged();
	void set_checked();
	bool get_checked();

	char get_identifier(bool cheat);

protected:
	bool is_checked = false;
	bool is_bomb = false;
	bool is_flagged = false;
	int no_bombs_around = 0;

};

#endif //INTRO_SQUARE_H
