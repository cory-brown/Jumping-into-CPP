#include <iostream>
#include <string>

using namespace std;

int main() {

  string needle, haystack;
  int count = 0;

  cout << "What is your needle?" << endl; // What word, character or phase you are looking for.
  getline(cin,needle,'\n'); // the last argument is use when the istream comes across a new line it will stop taking input

  cout << "What is your haystack?" << endl; // The sectence you want searching
  getline(cin,haystack,'\n');

  // the string method find will return npos if nothing matching the first argument. The second argument determines the position you want to start looking

  for(int i = haystack.find(needle, 0); i != string::npos; i = haystack.find(needle, i)) {
    i++; // this is to move to the next character to continue looking through the 'haystack'
    count++; // increment the count variable
  }

  cout << needle << " was found "  << count << " time/s" << endl;
}
