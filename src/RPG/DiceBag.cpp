/*
 * DiceBag.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */


#include<vector>
#include"Die.cpp"
class DiceBag {
public:
	DiceBag() {

	}

	int getDiceRoll(int sides) {
		return Die(sides).roll();
	}

	std::vector<int> multiRoll(int sides, int numOfDie) {
		std::vector<int> nums(numOfDie);
	for (int i = 0; i < numOfDie; i++) {

			nums[i] = Die(6).roll();
		}
		return nums;
	}
};
