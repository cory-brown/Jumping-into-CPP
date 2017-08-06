//
// Created by Cory Brown on 30/06/2017.
//

#include "compare.h"

int HighScoreElements::compare(Comparable& other) {
	if (this->getName() == other._name)
		return 0;
  else
	  return 1;
//	} else if (this->_name > o) {
//		return 1;
//	} else {
//		return -1;
//	}
}

void HighScoreElements::printScores() {
  cout << this->_name << " " << this->_name << endl;
}