/*
 * GameMaster.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: cosmo
 */

#include <boost/algorithm/string/predicate.hpp>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include"DiceBag.cpp
#include "Being.cpp"
#include "Hero.cpp"

using namespace std;
class GameMaster {
private:
	DiceBag db = new DiceBag();

	Hero hero;

	static void combat(Being monster) {
		cout<<"Rolling initiative.\n"<<endl;

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
				cout<<("Hero initiative: " + heroRoll)<<endl;
				cout<<("Monster initiative: " + monsterRoll)<<endl;
				if (heroRoll == monsterRoll) {
					cout<<("Tie. Rerolling.")<<endl;
					fail = true;
				} else {
					turn = heroRoll > monsterRoll;
				}
			}while (fail);

			do {
				cout << "" << endl;
				cout<<(hero)<<endl;
				cout << "" << endl;
				cout<<(monster)<<endl;
				cout << "" << endl;
				if (turn) {
					// hero
					cout << "" << endl;
					cout<<("Hero's turn.")<<endl;
					cout << "" << endl;
					int hpot = hero.getNumOfPots("health");
					int mpot = hero.getNumOfPots("mana");
					vector<string> inputs;
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
					cout<<inputs<<endl;
					int choice;
					cin >> choice;
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
							cout<<(hero.getCurrentMana() + ": current mana.")<<endl;
						} else {
							hero.useHealthPot();
							cout<<(hero.getCurrentHP() + ": current HP.")<<endl;
						}
						break;
						case 4:
						hero.useManaPot();
						cout<<(hero.getCurrentMana() + ": current mana.")<<endl;
						break;
					}
					bool hit = false;
					if ((choice != 3) && (choice != 4)) {
						if (damage > 0) {
							int attackRoll = db.getDiceRoll(20);
							int defendRoll = db.getDiceRoll(20);
							cout<<("Attacker's roll: " + attackRoll)<<endl;
							cout<<("Defender's roll: " + defendRoll)<<endl;
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
							cout << ("Damage: " + damage) << endl;

							monster.takeDamage(damage);
						} else {
							cout<<("Your attack failed.")<<endl;

						}
					}
					cout << "" << endl;
					turn = false;
					turns++;
				} else {
					// monster
					cout << "" << endl;
					cout<<("Monster's turn.")<<endl;
					cout << "" << endl;
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
						cout<<("Attacker's roll: " + attackRoll)<<endl;
						cout<<("Defender's roll: " + defendRoll)<<endl;
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
						cout<<("Damage: " + damage)<<endl;

						hero.takeDamage(damage);
					} else {
						cout<<("The monster's attack failed.");
					}
					turn = true;
					turns++;
					cout << "" << endl;
				}

				over = !hero.isAlive() || !monster.isAlive();
			}while ((turns < 5) && !over);
			if (!over) {
				cout<<("Rerolling initiative.")<<endl;
			}
		}while (!over);
		rewards();
	}

	Being createBeing(string type) {
		vector<int> rolls;
		vector<int> stats = {0, 0, 0};
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

	Hero createHero(string name) {
		vector<int> rolls = new int[3];
		vector<int> stats = {0, 0, 0};
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

	cout << "Would you like to reroll? y/n" << endl;
	cin >> input;
	return input == 'y' ? true : false;
	}

	void rewards() {
		if (hero.isAlive()) {
			cout<<("You killed it!");
		int num = rand() % 4, manas = 0, healths = 0;

			cout<<("You got " + num + " potions!");

			for (int i = 0; i < num; i++) {
			if (rand() % 1 == 0) {
					hero.addHealthPot(1);
					healths++;
				} else {
					hero.addManaPot(1);
					manas++;
				}
			}
			cout<<("You got " + manas + " mana pots and " + healths + " health pots.");

		} else {
			cout<<("Too bad. So sad.");
		cerr << "YOU DIED" << endl;
		}
	}





	void setup() {
		do {
		cout << "Enter the name for your hero:" << endl;
		string nam;
		cin >> nam;
		hero = createHero(nam);

			cout
					<< (hero.getName() + ", Strength: " + hero.getStrength()
							+ ", Dexterity: " + hero.getDexterity()
					+ ", Intelligence: " + hero.getIntelligence());
		}while (rerollHero());
	}
public:
	void run() {
		setup();

		char input;

		cout << "Would you like to fight? y/n" << endl;
		cin >> input;

		bool fight = input == 'y' ? true : false;
		while (fight) {
			string creature = NULL;
			int choice;
			cin >> choice;
			cout << "1 for Skeleton, 2 for Giant, 3 for Giant flying crab."
					<< endl;
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
		cout << "Would you like to fight another? y/n" << endl;
		cin >> input;

		if (input == 'n' ? true : false) {
			fight = false;
		}

	}


};

