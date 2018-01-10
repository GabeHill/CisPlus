/*
 * Being.h
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#ifndef BEING_H_
#define BEING_H_
//#include "Hero.h"
class Being {
protected:
//	friend Hero;
	int strength, intelligence, dexterity, sBonus, iBonus, dBonus, currentHP,
			maxHP, currentMana, maxMana, hitBonus;
	void setStrengthBonus() {
		sBonus = 0;
		for (int i = 15; i < strength; i++) {
			sBonus++;
		}
		for (int i = 10; i > strength; i--) {
			sBonus--;
		}
	}
	void setHitBonus() {
		hitBonus = 0;
		if ((dexterity > 15) && ((dexterity % 2) == 0)) {
			if (dexterity == 20) {
				hitBonus = 3;
			} else {
				hitBonus += (dexterity - 14) / 2;
			}
		} else if ((dexterity > 6) && (dexterity < 9)) {
			hitBonus--;
		} else if (dexterity < 7) {
			hitBonus = -2;
		}
	}
	void setIntBonus() {
		iBonus = 0;
		for (int i = 15; i < intelligence; i++) {
			iBonus += 2;
		}
		for (int i = 10; i > intelligence; i++) {
			iBonus -= 2;
		}
	}
	void setDodgeBonus() {
		dBonus = 0;
		if (dexterity > 15) {
			if (dexterity == 20) {
				dBonus = 3;
			} else {
				dBonus += (((dexterity - 15) / 2) + 0.1);
			}
		} else if ((dexterity > 7) && (dexterity < 11)) {
			dBonus--;
		} else if (dexterity < 8) {
			dBonus = -2;
		}
	}

public:
	Being(int s, int i, int d);
	Being();
	int getCurrentMana();
	int getCurrentHP();
	int getDexterity();
	int getDodgeBonus();
	int getIntelligence();
	int getMagicBonus();
	int getMaxHP();
	int getStrength();
	int getStrengthBonus();
	int getStrikeBonus();
	bool isAlive();
	int attackSpecial();
	int attackNormal();
	void takeDamage(int dmg);

	void addHealth(int health);
//	void addMana(int mana);
};

#endif /* BEING_H_ */
