/*
 * Hero.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <iostream>
#include <string>
//#include "strings.h"
#include <vector>

#include "Being.cpp"
#include "HealthPot.cpp"
#include "ManaPot.cpp"

class Hero: public Being {

protected:
	std::string name;
	std::vector<HealthPot> hPots;
	std::vector<ManaPot> mPots;
public:
	Hero(int s, int i, int d, std::string n) {
//		Being(s, i, d);
		name = n;
	}

	std::string getName() {
		return name;
	}


	void addHealthPot(int pots) {
		int added = 0;

		for (int i = 0; i < sizeof(hPots); i++) {
			if ((hPots[i].getPointsLeft() == 0)) {
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


	void addHealth(int health) {
		currentHP += health;
		if (currentHP > maxHP) {
			currentHP = maxHP;
		}
	}


	void addMana(int mana) {
		currentMana += mana;
		if (currentMana > maxMana) {
			currentMana = maxMana;
		}
	}


	void addManaPot(int pots) {
		int added = 0;

		for (int i = 0; i < sizeof(mPots); i++) {
			if ((mPots[i].getPointsLeft() == 0)) {
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

	int getNumOfPots(std::string pot) {
		int count = 0;
		if (pot == "mana") {
			for (ManaPot manaPot : mPots) {
				if (manaPot.getPointsLeft() != 0) {
					count++;
				}
			}
		} else if (0 == strcasecmp(pot, "health")) {
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

	std::string toString() {
		return name << ": Current HP: " << currentHP() << ", Current mana: "
				<< currentMana();
	}

	void useManaPot() {
		for (ManaPot mPot : mPots) {
			if ((mPot.getPointsLeft() != 0)) {
				addMana(mPot.use());

			}
		}
	}
	void useHealthPot() {
		for (HealthPot hPot : hPots) {
			if ((hPot.getPointsLeft() != 0)) {
				addHealth(hPot.use());

			}
		}
	}

};

