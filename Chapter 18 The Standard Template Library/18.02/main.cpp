#include <iostream>
#include <vector>

using namespace std;

void input_highscore(vector<int>&);
void print_highscore(vector<int>&);


int main() {

  vector<int> high_score = {100, 500, 600, 300};
  do {
    int input;
    cout << "1. Enter highscore" << endl;
    cout << "2. Print highscores" << endl;
    cin >> input; cin.ignore();
    switch (input) {
      case 1:
        input_highscore(high_score);
        break;
      case 2:
        print_highscore(high_score);
        break;
      default:
        exit(0);
    }
  } while (1);

}

void input_highscore(vector<int>& high_score) {
  int score = 0;
  cout << "Enter you score: ";
  cin >> score; cin.ignore();
  high_score.push_back(score);
  sort(high_score.rbegin(), high_score.rend());
}

void print_highscore(vector<int>& high_score) {
  cout << "Highscores" << endl;
  cout << "**********" << endl;
  cout << endl;
  int num = 1;
  for (vector<int>::iterator vect_itr = high_score.begin(), vect_end = high_score.end(); vect_itr != vect_end; ++vect_itr) {
    cout << num++ << ". " << *vect_itr << endl;
  }
  cout << endl;
}