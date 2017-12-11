/*
 * Hero.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <boost/algorithm/string/predicate.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Being.cpp"
#include "HealthPot.cpp"
#include "ManaPot.cpp"

using namespace std;
class Hero: public Being {

protected:
	string name;
	vector<HealthPot> hPots;
	vector<ManaPot> mPots;
public:
	Hero(int s, int i, int d, string n) {
//		Being(s, i, d);
		name = n;
	}

	string getName() {
		return name;
	}


	void addHealthPot(int pots) {
		int added = 0;

		for (int i = 0; hPots != NULL && i < sizeof(hPots); i++) {
			if ((hPots[i].getPointsLeft() == 0)) {
				hPots[i] = new HealthPot();
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
		cout
				<< used + " health pots used. " + added
						+ " health pots added to inventory." << endl;
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

		for (int i = 0; mPots && i < sizeof(mPots); i++) {
			if ((mPots[i].getPointsLeft() == 0)) {
				mPots[i] = new HealthPot();
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
		cout
				<< used + " mana pots used. " + added
						+ " mana pots added to inventory." << endl;
	}

	int getNumOfPots(string pot) {
		int count = 0;
		if (boost::iequals(pot, "mana")) {
			for (ManaPot manaPot : mPots) {
				if (manaPot) {
					count++;
				}
			}
		} else if (boost::iequals(pot, "health")) {
			for (HealthPot healthPot : hPots) {
				if (healthPot) {
					count++;
				}
			}
		} else {
			return -1;
		}

		return count;
	}

	string toString() {
		return name + ": Current HP: " + currentHP() + ", Current mana: "
				+ currentMana();
	}

	void useManaPot() {
		for (ManaPot mPot : mPots) {
			if ((mPot) && (mPot.getPointsLeft() != 0)) {
				addMana(mPot.use());

			}
		}
	}
	void useHealthPot() {
		for (HealthPot hPot : hPots) {
			if ((hPot) && (hPot.getPointsLeft() != 0)) {
				addHealth(hPot.use());

			}
		}
	}

};

