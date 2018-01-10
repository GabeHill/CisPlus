/*
 * Hero.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <string>

#include "Being.h"

Being::Being() {
	strength = 0;
	intelligence = 0;
	dexterity = 0;
	maxMana = intelligence * 5;
	maxHP = strength * 5;
	setHitBonus();
	setStrengthBonus();
	setIntBonus();
	setDodgeBonus();
}

Being::Being(int s, int i, int d) {
	strength = s;
	intelligence = i;
	dexterity = d;
	maxMana = intelligence * 5;
	maxHP = strength * 5;
	setHitBonus();
	setStrengthBonus();
	setIntBonus();
	setDodgeBonus();
}

int Being::getCurrentMana() {
	return currentMana;
}

int Being::getCurrentHP() {
	return currentHP;
}

int Being::getDexterity() {
	return dexterity;
}

int Being::getDodgeBonus() {
	return dBonus;
}

int Being::getIntelligence() {
	return intelligence;
}

int Being::getMagicBonus() {
	return iBonus;
}

int Being::getMaxHP() {
	return maxHP;
}

int Being::getStrength() {
	return strength;
}

int Being::getStrengthBonus() {
	return sBonus;
}

int Being::getStrikeBonus() {
	return sBonus;
}

bool Being::isAlive() {
	return currentHP >= 0;
}

int Being::attackSpecial() {
	if ((currentMana - 10) >= 0) {
		currentMana -= 10;
		return 15 + iBonus;
	} else {
		return 0;
	}
}

int Being::attackNormal() {
	return (10 + sBonus);
}

void Being::takeDamage(int dmg) {
	currentHP -= dmg;
}

void Being::addHealth(int health) {
	currentHP += health;
	if (currentHP > maxHP) {
		currentHP = maxHP;
	}
}

