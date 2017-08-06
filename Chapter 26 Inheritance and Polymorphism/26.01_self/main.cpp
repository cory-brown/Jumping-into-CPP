#include "score.h"
#include <algorithm>

int main() {

	vector<Score *> s;
	vector<Score *> sortedS;

	s.push_back(new Arcade("Bob", 900));
	s.push_back(new Arcade("John", 333));
	s.push_back(new Arcade("Michael", 600));




	for (int i = 1; i < s.size(); i++) {
		cout << (*s[0]).compare(*s[i]) << endl;
	}

	// for (int i = 0; i < s.size(); ++i) {
	// 	(*s[i]).print();
	// 	//cout << " -> " << (*s[i]).getName() << " " << (*s[i]).getScore() << endl;
	// }



}
