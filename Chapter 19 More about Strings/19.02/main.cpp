#include <iostream>
#include <vector>

using namespace std;

int main() {
  string data;
  int input = -1;
  vector<char> seperator;

  while (1) {
    cout << "1. Enter tabulared data " << endl;
    cout << "2. exit and output" << endl;
    cout << "input: ";
    cin >> input;
    cin.ignore();
    switch (input) {
      case 1:
        cout << "Data: ";
        getline(cin, data, '\n');
        data += input + '\n';
      break;
      case 2:
        for (int i = 0; i < data.size(); i++) {
          if (ispunct(data[i])) {
            seperator.push_back(data[i]);
          }
        }
        cout << "I found ";
        (seperator.size() <= 1) ? cout << "this " : cout << "these ";
        cout << "sperating symbols in the inputted string: ";

        for (int i = 0; i < seperator.size(); i++) {
          cout << seperator[i] << " ";
        }
        cout << endl;
        exit(0);
      break;
      default:
        cout << "Something went wrong" << endl;
        exit(0);
      break;
    }
  }
}
