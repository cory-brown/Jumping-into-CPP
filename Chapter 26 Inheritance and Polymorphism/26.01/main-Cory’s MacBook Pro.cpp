#include "compare.h"

int main() {
  vector<Comparable *> score;

  score.push_back(new HighScoreElements("Bob", 20));
  score.push_back(new HighScoreElements("Carl", 30));

	for (vector<Comparable*>::iterator itr = score.begin(), itr_end = score.end(); itr != itr_end; ++itr) {
		cout << (*itr)->compare();
	}

}
