/*
 * ManaPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#include <ctime>
#include <cstdlib>

#include"ManaPot.h"

ManaPot::ManaPot() {
	srand(time(NULL));
	int rand();
	points = rand() % 10;
}

int ManaPot::getPointsLeft() {
	return points;
}

int ManaPot::use() {
	int temp = points;
	points = 0;
	return temp;
}

