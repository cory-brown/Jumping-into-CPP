//
// Created by Cory Brown on 01/07/2017.
//

#include "score.h"

void Arcade::print() {
	cout << this->_name << " " << this->_score;
}

int Arcade::compare(Score& s) {
	if (this->_score == s.getScore()) {
		return 1;
	} else if (this->_score > s.getScore()){
		return 0;
	} else {
		return -1;
	}
}

void Arcade::sort(vector<Score*>& s) {
	
}
