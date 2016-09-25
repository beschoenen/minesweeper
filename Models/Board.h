#ifndef INTRO_BOARD_H
#define INTRO_BOARD_H

#include "Square.h"
#include <iostream>
#include "map"
#include "../helpers.cpp"

using namespace std;

class Board {

public:
	Board(int size, int bomb_chance);

	void print_board(bool cheat);
	void hit_field(char x, int y);
	void flag_field(char x, int y);
	void check_input(string input);

	bool operator <(const Square& rhs) const
	{
		return true;
	}

	bool is_playing = true;

private:
	int check_no_bombs(int x, int y);

	map<string, Square> fields;

	int board_size = 10;
	bool cheat = true;

	int no_bombs = 0;
	int no_bombs_selected = 0;

};

#endif //INTRO_BOARD_H