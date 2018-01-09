/*
 * GameMaster.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "strings.h"
#include"DiceBag.h"
#include "Being.h"
#include "Hero.h"

class GameMaster {
private:
	DiceBag db;
	Hero hero;

	void combat(Being monster) {
		std::cout << "Rolling initiative.\n" << std::endl;

		bool fail, turn, over;
		int turns;
		do {
			turn = true;
			fail = false;
			over = false;
			turns = 0;
			do {
				int heroRoll = db.getDiceRoll(20);
				int monsterRoll = db.getDiceRoll(20);
				std::cout << ("Hero initiative: " + heroRoll) << std::endl;
				std::cout << ("Monster initiative: " + monsterRoll)
						<< std::endl;
				if (heroRoll == monsterRoll) {
					std::cout << ("Tie. Rerolling.") << std::endl;
					fail = true;
				} else {
					turn = heroRoll > monsterRoll;
					fail = true;
				}
			}while (fail);

			do {
				std::cout << std::endl;
				std::cout << hero << std::endl;
				std::cout << std::endl;
				std::cout << monster << std::endl;
				std::cout << std::endl;
				if (turn) {
					// hero
					std::cout << std::endl;
					std::cout << ("Hero's turn.") << std::endl;
					std::cout << std::endl;
					int hpot = hero.getNumOfPots("health");
					int mpot = hero.getNumOfPots("mana");
					std::vector<std::string> inputs;
					if ((mpot == 0) && (hpot == 0)) {
						inputs.push_back("Normal attack");
						inputs.push_back("Special attack");
					} else if (mpot == 0) {
						inputs.push_back("Normal attack");
						inputs.push_back("Special attack");
						inputs.push_back("Use health pot");
					} else if (hpot == 0) {
						inputs.push_back("Normal attack");
						inputs.push_back("Special attack");
						inputs.push_back("Use mana pot");

					} else {
						inputs.push_back("Normal attack");
						inputs.push_back("Special attack");
						inputs.push_back("Use health pot");
						inputs.push_back("Use mana pot");

					}
					std::cout << inputs << std::endl;
					int choice;
					std::cin >> choice;
					int damage = 0;
					switch (choice) {
						case 1:
						damage = hero.attackNormal();
						break;
						case 2:
						damage = hero.attackSpecial();

						break;
						case 3:
						if (hpot == 0) {
							hero.useManaPot();
							std::cout
									<< (hero.getCurrentMana()
											+ ": current mana.")
									<< std::endl;
						} else {
							hero.useHealthPot();
							std::cout
									<< (hero.getCurrentHP() + ": current HP.")
									<< std::endl;
						}
						break;
						case 4:
						hero.useManaPot();
						std::cout << (hero.getCurrentMana() + ": current mana.")
								<< std::endl;
						break;
					}
					bool hit = false;
					if ((choice != 3) && (choice != 4)) {
						if (damage > 0) {
							int attackRoll = db.getDiceRoll(20);
							int defendRoll = db.getDiceRoll(20);
							std::cout << ("Attacker's roll: " + attackRoll)
									<< std::endl;
							std::cout << ("Defender's roll: " + defendRoll)
									<< std::endl;
							if ((defendRoll == 20) && (attackRoll == 20)) {
								hit = (attackRoll + hero.getStrikeBonus()) > (defendRoll + monster.getDodgeBonus());
							} else if ((attackRoll == 1)) {
								damage = 0;
							}

							attackRoll += hero.getStrikeBonus();
							defendRoll += monster.getDodgeBonus();
							if ((attackRoll == defendRoll) || (attackRoll < defendRoll)) {
								damage = 0;
							} else {
								if (attackRoll == 20) {

									hit = true;
									damage *= 2;
								}
								if (defendRoll == 1) {
									hit = true;
									damage *= 2;
								}
								if (attackRoll > defendRoll) {
									hit = true;
								}
							}
						}

						if (hit) {
							std::cout << ("Damage: " + damage) << std::endl;

							monster.takeDamage(damage);
						} else {
							std::cout << ("Your attack failed.") << std::endl;

						}
					}
					std::cout << std::endl;
					turn = false;
					turns++;
				} else {
					// monster
					std::cout << std::endl;
					std::cout << ("Monster's turn.") << std::endl;
					std::cout << std::endl;
					int damage = 0;
					int choose = rand() % 2;
					switch (choose) {
						case 0:
						damage = monster.attackNormal();
						break;
						case 1:
						damage = monster.attackSpecial();

						break;
					}
					bool hit = false;

					if (damage > 0) {
						int attackRoll = db.getDiceRoll(20);
						int defendRoll = db.getDiceRoll(20);
						std::cout << ("Attacker's roll: " + attackRoll)
								<< std::endl;
						std::cout << ("Defender's roll: " + defendRoll)
								<< std::endl;
						if ((defendRoll == 20) && (attackRoll == 20)) {
							hit = (attackRoll + monster.getStrikeBonus()) > (defendRoll + hero.getDodgeBonus());
						} else if ((attackRoll == 1)) {
							damage = 0;
						}

						attackRoll += monster.getStrikeBonus();
						defendRoll += hero.getDodgeBonus();
						if ((attackRoll == defendRoll) || (attackRoll < defendRoll)) {
							damage = 0;
						} else {
							if (attackRoll == 20) {

								hit = true;
								damage *= 2;
							}
							if (defendRoll == 1) {
								hit = true;
								damage *= 2;
							}
							if (attackRoll > defendRoll) {
								hit = true;
							}
						}
					}

					if (hit) {
						std::cout << ("Damage: " + damage) << std::endl;

						hero.takeDamage(damage);
					} else {
						std::cout << ("The monster's attack failed.");
					}
					turn = true;
					turns++;
					std::cout << std::endl;
				}

				over = !hero.isAlive() || !monster.isAlive();
			}while ((turns < 5) && !over);
			if (!over) {
				std::cout << ("Rerolling initiative.") << std::endl;
			}
		}while (!over);
		rewards();
	}

	Being createBeing(std::string type) {
		std::vector<int> rolls;
		std::vector<int> stats = { 0, 0, 0 };
		for (int i = 0; i < sizeof(stats); i++) {
			rolls = db.multiRoll(6, 3);

			for (int j : rolls) {
				stats[i] += j;
			}
			if (stats[i] >= 16) {
				int f = db.getDiceRoll(6);
				if (f == 6) {
					f += db.getDiceRoll(6);
				}
				stats[i] += f;
			}
		}
		if (type) {
			if (boost::iequals(type, "skeleton")) {
				return Being(stats[0], stats[1], stats[2]);
			} else if (boost::iequals(type, "giant")) {
				return Being(stats[0], stats[1], stats[2]);
			} else if (boost::iequals(type, "giant flying crab")) {
				return Being(stats[0], stats[1], stats[2]);
			} else {
				return NULL;
			}
		} else {
			return NULL;
		}

	}

	Hero createHero(std::string name) {
		std::vector<int> rolls(3);
		std::vector<int> stats = { 0, 0, 0 };
	for (int i = 0; i < sizeof(stats); i++) {
			rolls = db.multiRoll(6, 3);
			for (int j : rolls) {
				stats[i] += j;
			}
			if (stats[i] >= 16) {
				int f = db.getDiceRoll(6);
				if (f == 6) {
					f += db.getDiceRoll(6);
				}
				stats[i] += f;
			}
		}

	return new Hero(stats[0], stats[1], stats[2], name);

	}

	bool rerollHero() {
	char input;

		std::cout << "Would you like to reroll? y/n" << std::endl;
		std::cin >> input;
	return input == 'y' ? true : false;
	}

	void rewards() {
		if (hero.isAlive()) {
			std::cout << ("You killed it!") << std::endl;
		int num = rand() % 4, manas = 0, healths = 0;

			std::cout << ("You got " + num + " potions!") << std::endl;

			for (int i = 0; i < num; i++) {
			if (rand() % 1 == 0) {
					hero.addHealthPot(1);
					healths++;
				} else {
					hero.addManaPot(1);
					manas++;
				}
			}
			std::cout
					<< ("You got " + manas + " mana pots and " + healths
							+ " health pots.") << std::endl;

		} else {
			std::cout << ("Too bad. So sad.") << std::endl;
			std::cerr << "YOU DIED" << std::endl;
		}
	}





	void setup() {
		do {
			std::cout << "Enter the name for your hero:" << std::endl;
			std::string nam;
			std::cin >> nam;
		hero = createHero(nam);

			std::cout
					<< (hero.getName() << ", Strength: " << hero.getStrength()
							<< ", Dexterity: " << hero.getDexterity()
							<< ", Intelligence: " << hero.getIntelligence())
					<< std::endl;
		}while (rerollHero());
	}

	void run() {
		setup();

		char input;

		std::cout << "Would you like to fight? y/n" << std::endl;
		std::cin >> input;

		bool fight = input == 'y' ? true : false;
		while (fight) {
			std::string creature;
			int choice;
			std::cin >> choice;
			std::cout << "1 for Skeleton, 2 for Giant, 3 for Giant flying crab."
					<< std::endl;
			switch (choice) {
			case 1:
				creature = "skeleton";
				break;
			case 2:
				creature = "giant";
				break;
			case 3:
				creature = "giant flying crab";
				break;
			}
			combat(createBeing(creature));
		}
		std::cout << "Would you like to fight another? y/n" << std::endl;
		std::cin >> input;

		if (input == 'n' ? true : false) {
			fight = false;
		}

	}
public:
	int main() {
		run();
		return 0;
	}


};

