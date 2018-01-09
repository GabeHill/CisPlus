/*
 * ManaPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#include"ManaPot.h"

ManaPot::ManaPot() {
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

