/*
 * Hero.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */
#pragma once

#include <string>
#include <vector>

#include "Being.h"
#include "HealthPot.h"
#include "ManaPot.h"

class Hero: public Being {
private:
	std::string name;
	std::vector<HealthPot> hPots;
	std::vector<ManaPot> mPots;

public:
	Hero();
	Hero(int s, int i, int d, std::string n);

	std::string getName() const;

	void addHealthPot(int pots);

	void addHealth(int health);

	void addMana(int mana);

	void addManaPot(int pots);

	int getNumOfPots(std::string pot) const;

	std::string toString();

	void useManaPot();
	void useHealthPot();

};

