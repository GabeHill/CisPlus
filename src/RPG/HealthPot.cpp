/*
 * HealthPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

class HealthPot {

private:
	int points;

public:
	HealthPot() {
		int rand();
		points = rand() % 10;
	}
	int getPointsLeft() {
		return points;
	}
	int use() {
		int temp = points;
		points = 0;
		return temp;
	}
};

