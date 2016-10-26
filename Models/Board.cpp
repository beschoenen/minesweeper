#include <cstdlib>
#include "Board.h"
#include "../helpers.cpp"

Board::Board(int size, int bomb_chance) {
	this->board_size = size;

	for(int y = 0; y < board_size; y++) {
		for(int x = 0; x < board_size; x++) {
			// Check if bomb
			bool is_bomb = false;
			if((rand()%(100) + 1) <= bomb_chance) {
				is_bomb = true;
				no_bombs += 1;
			}

			this->fields.insert(pair<string, Square>(
				helpers::get_identifier(x, y + 1),
				*new Square(is_bomb)
			));
		}
	}

	//////
	this->cheat = true;
}

void Board::print_board(bool cheat = false) {
	for(int y = board_size; y > 0; --y) {
		if(y < 10) cout << " ";
		cout << y << " ";

		for(int x = 0; x < board_size; x++) {
			cout << fields.at(helpers::get_identifier(x, y)).get_identifier(cheat);
		}

		cout << endl;
	}

	cout << "   ";
	for(int i = 0; i < this->board_size; i++) {
		cout << helpers::alphabet[i];
	}
	cout << endl;

	if(this->cheat && !cheat) {
		this->print_board(true);
	}
}

void Board::hit_field(char x, int y) {
	Square& square = fields.at(helpers::get_identifier(x, y));

	if(square.get_is_bomb()) {
		this->is_playing = false;
		cout << "Boom! You lost!" << endl;
	}

	int close_bombs = check_no_bombs(helpers::char_to_int(x), y);

	square.set_close_bombs(close_bombs);
	square.set_checked();
}

int Board::check_no_bombs(int x, int y) {
	int no_bombs = 0;

	for(int i = -1; i < 2; i++) {
		if(x + i < 0 || x + i >= board_size) continue;

		for(int j = -1; j < 2; j++) {
			if(y + j < 1 || y + j >= board_size) continue;

			if(!(i + i == x && y + j == y)) {
				Square& square = fields.at(helpers::get_identifier(x + i, y + j));
				
				if(square.get_is_bomb()) {
					no_bombs += 1;
				} else if(!square.get_checked()) {
					square.set_checked();
					int number = check_no_bombs(x + i, y + j);
					square.set_close_bombs(number);
				}
			}

		}
	}

	return no_bombs;
}

void Board::flag_field(char x, int y) {
	Square& square = fields.at(helpers::get_identifier(x, y));
	if(square.get_is_bomb()) {
		no_bombs_selected += (square.get_is_flagged() ? -1 : 1);
	}
	square.toggle_flagged();

	if(no_bombs == no_bombs_selected) {
		this->is_playing = false;
		cout << "You won! Congratulations!" << endl;
	}
}

void Board::check_input(string input) {
	bool flag = false;
	if(input[0] == '*') {
		input.erase(0, 1);
		flag = true;
	}

	if(fields.find(input) == fields.end()) {
		cout << "Invalid input!" << endl;
	}

	char x = (char) toupper(input[0]);
	int y = 0;

	stringstream ss;
	ss << input[1];
	ss >> y;

	if(flag) {
		flag_field(x, y);
	} else {
		hit_field(x, y);
	}
}
