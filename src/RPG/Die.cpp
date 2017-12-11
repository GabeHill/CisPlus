/*
 * Die.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

class Die {
private:
	int sides;

public:

	Die(int s) {
		sides = s;
	}

	int roll() {
		int rand();
		return (rand() % sides);
	}
};



