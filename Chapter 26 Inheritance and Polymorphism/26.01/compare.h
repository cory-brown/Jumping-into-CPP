//
// Created by Cory Brown on 30/06/2017.
//

#ifndef INC_26_01_COMPARE_H
#define INC_26_01_COMPARE_H

#include <iostream>
#include <vector>

using namespace std;

class Comparable {
protected:
  string _name;
  int _score;
public:
		virtual int compare(Comparable &other) = 0;
    virtual void printScores() = 0;
};

class HighScoreElements : public Comparable {
public:
		HighScoreElements(string name, int score)
						: _name(name), _score(score){}
		int compare(Comparable &other);
		int getScore() { return _score; }
		string getName() { return _name; }
    void printScores();
};

#endif //INC_26_01_COMPARE_H
