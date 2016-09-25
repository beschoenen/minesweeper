#include <iostream>
#include "Models/Board.h"

using namespace std;

int main() {
	cout << "Welcome, let's play minesweeper!" << endl;

	bool wants_to_play = true;
	while(wants_to_play) {

		int board_size = 0;
		while (board_size < 5 || board_size > 20) {
			cout << "How big would you like your playing field? (5-20): ";

			int given_size;
			cin >> given_size;

			if (given_size < 5 || given_size > 20) {
				cout << "Please try again!" << endl;
			} else {
				board_size = given_size;
			}
		}

		int bomb_chance = 0;
		while (bomb_chance < 10 || board_size > 25) {
			cout << "How big would you like the chance of bombs being placed? (10-25): ";

			int given_size;
			cin >> given_size;

			if (given_size < 10 || given_size > 25) {
				cout << "Please try again!" << endl;
			} else {
				bomb_chance = given_size;
			}
		}

		cout << "Okay! Let's start!" << endl;

		Board *board = new Board(board_size, bomb_chance);

		while(board->is_playing) {
			board->print_board(false);
			cout << "Please enter the location you want to check (prepend with '*' to flag): ";

			string input;
			cin >> input;

			board->check_input(input);
		}

		cout << "Do you want to play again? (y/N)";
		string answer;
		cin >> answer;

		if(answer != "y") {
			wants_to_play = false;
		}
	}

	return 0;
}