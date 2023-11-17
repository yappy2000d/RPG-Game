/*********************************************************************
 * Filename: Position.h
 * Author: Yu-Lun Zhu (B11115022@mail.ntust.edu.tw)
 *		   Yu-Zhang Lin (B11115003@mail.ntust.edu.tw)
 * Date: May 19, 2023
 * Last Edit: May 19, 2023
 * Description: This program defines the structure Position.
 *********************************************************************/

#ifndef POSITION_H
#define POSITION_H

#include <cmath>
#include <vector>

struct Position {
	int x, y;

	Position() : x(0), y(0) {};
	Position(int x, int y) : x(x), y(y) {};
    explicit Position(std::vector<int>& pos) : x(pos[0]), y(pos[1]) {};

	Position abs() const { return {x < 0 ? -x : x, y < 0 ? -y : y}; }
	Position unit() const {
        if (x == 0 && y == 0) return {0, 0};
        else if (x == 0) return {0, y / std::abs(y)};
        else if (y == 0) return {x / std::abs(x), 0};
    }

	bool operator==(const Position& pos) const { return (x == pos.x) && (y == pos.y); }
	Position operator+(const Position& pos) const { return {x + pos.x, y + pos.y}; }
	Position operator-(const Position& pos) const { return {x - pos.x, y - pos.y}; }
};

#endif
