/*
 * Die.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <ctime>
#include <cstdlib>

#include "Die.h"

Die::Die(int s) {
	sides = s;
	srand(time(NULL));
	int rand();
}

int Die::roll() {

//	int f = rand();
	return (rand() % sides);
}

