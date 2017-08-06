//
// Created by Cory Brown on 30/06/2017.
//

#ifndef INC_26_01_COMPARE_H
#define INC_26_01_COMPARE_H

#include <iostream>
#include <vector>

using namespace std;

class Comparable {
public:
		virtual int compare(Comparable &other) = 0;
};

class HighScoreElements : public Comparable {
private:
		string _name;
		int _score;
public:
		HighScoreElements(string name, int score)
						: _name(name), _score(score){}
		int compare(Comparable &other);
		int getScore() { return _score; }
		string getName() { return _name; }
};

#endif //INC_26_01_COMPARE_H
