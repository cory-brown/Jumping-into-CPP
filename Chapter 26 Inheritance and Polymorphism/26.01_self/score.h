//
// Created by Cory Brown on 01/07/2017.
//

#ifndef INC_26_01_SELF_SCORE_H
#define INC_26_01_SELF_SCORE_H

#include <iostream>
#include <vector>

using namespace std;

class Score {
protected:
		string _name;
		int _score;
public:
		Score(string name, int score) : _name(name), _score(score) {}
		string getName() { return _name; }
		int getScore() { return _score; }
		virtual void print() = 0;
		virtual int compare(Score& s) = 0;
};

class Arcade : public Score {
public:
		Arcade(string name, int score) : Score(name, score) {}
		void print();
		int compare(Score& s);
		void sort(vector<Score*>& s);
};

#endif //INC_26_01_SELF_SCORE_H
