/*
 * HealthPot.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#pragma once

class HealthPot {

private:
	int points;

public:
	HealthPot();
	int getPointsLeft();
	int use();
};

