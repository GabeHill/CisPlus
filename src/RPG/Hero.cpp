/*
 * Hero.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#include"Hero.h"
#include "Being.h"
#include "HealthPot.cpp"
#include "ManaPot.cpp"



	Hero::Hero(int s, int i, int d, std::string n) :
			Being(s, i, d) {
	name = n;
	}

std::string Hero::getName() const {
		return name;
	}


	void Hero::addHealthPot(int pots) {
		int added = 0;

		for (int i = 0; i < sizeof(hPots); i++) {
		HealthPot p = hPots[i];
		if (p.getPointsLeft() == 0) {
				hPots[i] = HealthPot();
				added++;
				pots--;
			}
		}
		int used = 0;
		if (pots > 0) {
			for (int i = 0; i < pots; i++) {
				addHealth(HealthPot().use());
				used++;
			}
		}
		std::cout
				<< used << " health pots used. " << added
				<< " health pots added to inventory." << std::endl;
	}

	void Hero::addMana(int mana) {
		currentMana += mana;
		if (currentMana > maxMana) {
			currentMana = maxMana;
		}
	}


	void Hero::addManaPot(int pots) {
		int added = 0;

		for (int i = 0; i < sizeof(mPots); i++) {
		HealthPot p = hPots[i];

		if (p.getPointsLeft() == 0) {
				mPots[i] = HealthPot();
				added++;
				pots--;
			}
		}
		int used = 0;
		if (pots > 0) {
			for (int i = 0; i < pots; i++) {
				addMana(ManaPot().use());
				used++;
			}
		}
		std::cout
				<< used << " mana pots used. " << added
				<< " mana pots added to inventory." << std::endl;
	}

	int Hero::getNumOfPots(std::string pot) const {
		int count = 0;
		if (pot == "mana") {
			for (ManaPot manaPot : mPots) {
				if (manaPot.getPointsLeft() != 0) {
					count++;
				}
			}
	} else if (boost::iequals(pot, "health")) {
			for (HealthPot healthPot : hPots) {
				if (healthPot.getPointsLeft() != 0) {
					count++;
				}
			}
		} else {
			return -1;
		}

		return count;
	}

	std::string Hero::toString() const {
		return name << ": Current HP: " << currentHP() << ", Current mana: "
				<< currentMana();
	}

	void Hero::useManaPot() {
		for (ManaPot mPot : mPots) {
			if ((mPot.getPointsLeft() != 0)) {
				addMana(mPot.use());

			}
		}
	}
	void Hero::useHealthPot() {
		for (HealthPot hPot : hPots) {
			if ((hPot.getPointsLeft() != 0)) {
				addHealth(hPot.use());

			}
		}
	}


