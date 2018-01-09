/*
 * DiceBag.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#pragma once

#include<vector>

class DiceBag {
public:
	DiceBag();

	int getDiceRoll(int sides);

	std::vector<int> multiRoll(int sides, int numOfDie);
};
