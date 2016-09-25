#include "Square.h"

Square::Square(bool is_bomb) {
	this->is_bomb = is_bomb;
}

bool Square::get_is_bomb() {
	return this->is_bomb;
}

bool Square::get_is_flagged() {
	return this->is_flagged;
}

void Square::add_close_bomb() {
	this->no_bombs_around += 1;
}

void Square::toggle_flagged() {
	this->is_flagged = !this->is_flagged;
}

void Square::set_checked() {
	this->is_checked = true;
}

bool Square::get_checked() {
	return this->is_checked;
}

char Square::get_identifier(bool cheat = false) {
	if(cheat) {
		if(is_bomb) {
			return '*';
		}
	} else {
		if(this->is_flagged) {
			return '*';
		}

		if(this->is_checked) {
			return (char) ('0' + no_bombs_around);
		}
	}

	return '.';
}

void Square::set_close_bombs(int number) {
	this->no_bombs_around = number;
}
