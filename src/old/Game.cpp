/*
 * Gam.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: Gabe
 */
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int mn() {
	bool playing = true;
	do {
	string diff, again;
	int max = 1, rando, tries = 5, userNum, di;
		bool notValid = true;
	while (notValid) {
	cout << "How hard you want this?\n1) Easy\n2) Medium\n3) Hard" << endl;
	cin >> diff;
			stringstream f(diff);
			f >> di;

			switch (di) {
			case 1:
				max = 10;
				notValid = false;
				break;
			case 2:
				max = 50;
				notValid = false;
				break;
			case 3:
				max = 100;
				notValid = false;
				break;
			default:
				cout << "You waht m8???? Try again." << endl;
				break;
	}
	}
		srand(time(NULL));
		rando = rand() % max + 1;
		for (; tries > 0; tries--) {
			cout << "Gimme an integer:" << endl;
			cin >> userNum;
			if (userNum > rando) {
				cout << "Higher than a kite there." << endl;
				continue;
			} else if (userNum < rando) {
				cout << "Tryin to dig a hole to China?" << endl;
				continue;
			} else if (userNum > max || userNum < 1) {
				cout << "You're not even in range to hit it n00b." << endl;
				continue;
			} else {
				cout << "Right on." << endl;
				tries = -1;
			}
			if (tries > 0) {
				cout << "You've got " << tries - 1 << " remaining." << endl;
			}
		}
		if (tries != -1) {
			cout << "The number was " << rando << endl;
		}
		notValid = true;
			cout << "Wanna play again? 1 for yes, 2 for no." << endl;
		do {
			cin >> again;
		if (again == ("2")) {
				exit(0);

		} else if (again == ("1")) {
			playing = true;
				notValid = false;
			} else {
				cout << "What?" << endl;
			continue;
			}
		} while (notValid);
	} while (playing);
		return 0;
}
