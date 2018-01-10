/*
 * ManaPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#pragma once

class ManaPot {

private:
	int points;

public:
	ManaPot();

	int getPointsLeft();

	int use();
};
