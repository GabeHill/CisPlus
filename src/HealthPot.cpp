/*
 * HealthPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#include <ctime>
#include <cstdlib>

#include"HealthPot.h"

HealthPot::HealthPot() {
	srand(time(NULL));
	int rand();
	points = rand() % 10;
}

int HealthPot::getPointsLeft() {
	return points;
}

int HealthPot::use() {
	int temp = points;
	points = 0;
	return temp;
}
