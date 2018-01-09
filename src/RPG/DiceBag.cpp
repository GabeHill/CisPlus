/*
 * DiceBag.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include"DiceBag.h"
#include<vector>
#include"Die.h"

DiceBag::DiceBag() {

	}

int DiceBag::getDiceRoll(int sides) {
		return Die(sides).roll();
	}

std::vector<int> DiceBag::multiRoll(int sides, int numOfDie) {
		std::vector<int> nums(numOfDie);
	for (int i = 0; i < numOfDie; i++) {

			nums[i] = Die(6).roll();
		}
		return nums;
	}

