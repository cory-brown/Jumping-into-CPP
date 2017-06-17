/*

Jumping into C++

Chapter 14
Practice Problem

4. Write a program that lets users keep track of the last time they talked to each of their friends.
Users should be able to add new friends (as many as they want!) and store the number of days ago that they last talked to each friend. Let users update this value (but don't let them put in
bogus numbers like negative values). Make it possible to display the list sorted by the names of
the friends of by how recently it was since they talked to each friend.

*/


#include <iostream>
#include <cstdlib> // exit(0)

using namespace std;

void addFriend(int q, string **friendList); // This adds a new friend to the  array (List) of friends
void displayFriendList(int q, string **friendList); // This displays the list of friends, in a grid with the their name and days since they last spoke
string **growArray(int *q, string **friendList); // dynamically expands the array
void changeDate(int q, string **friendList);
void deallocateList(int q, string **friendList); // when the program finishes this deallocate's the memory used by the array

int main() {
  int q = 1; // holds the amount of friends
  string **friendList = new string *[q];
  for (int i = 0; i < q; ++i) {
    friendList[i] = new string[2];
  }

  while (true) {
    cout << "1. Add Friend" << endl;
    cout << "2. Change date" << endl;
    cout << "3. Display sorted list" << endl;
    cout << "4. Exit" << endl;
    int menu;
    cin >> menu;
    cin.ignore();
    switch (menu) {
    case 1:
      addFriend(q, friendList);
      friendList = growArray(&q, friendList);
      break;
    case 2:
      displayFriendList(q, friendList);
      changeDate(q, friendList);
      break;
    case 3:
      displayFriendList(q, friendList);
      break;
    default:
      deallocateList(q, friendList);
      exit(0);
    }
  }
}

void addFriend(int q, string **friendList) {
  cout << "What is your friends name?" << endl;
  string getName;
  getline(cin, getName);
  friendList[q - 1][0] = getName;
  cout << "How many days ago did you speak to " << friendList[q - 1][0] << "?" << endl;
  string getDaysAgo;
  getline(cin, getDaysAgo);
  friendList[q - 1][1] = getDaysAgo;
}

void displayFriendList(int q, string **friendList) {
  cout << endl;
  for (int i = 0; i < q - 1; ++i) {
    cout << "Name of Friend" << endl;
    cout << friendList[i][0] << endl;
    cout << "Days ago since you last spoke to them" << endl;
    cout << friendList[i][1] << endl;
    cout << endl;
  }
}

string **growArray(int *q, string **friendList) {
  *q += 1;
  string **temp_arr = new string *[*q];
  for (int i = 0; i < *q; ++i) {
    temp_arr[i] = new string[2];
  }

  for (int i = 0; i < *q - 1; ++i) {
    // *q-1 is used as the friendList array is only the size of q-1,
    // so trying to access the q value will return a seg fault
    for (int j = 0; j < 2; ++j) {
      temp_arr[i][j] = friendList[i][j];
    }
  }

  for (int i = 0; i < *q - 1; ++i) {
    delete[] friendList[i];
  }

  delete[] friendList;
  return temp_arr;
}

void changeDate(int q, string **friendList) {
  cout << "Enter the name of the friend" << endl;
  string getName;
  getline(cin, getName);
  for (int i = 0; i < q; ++i) {
    if (getName == friendList[i][0]) {
      cout << "Enter the new value of days ago since you spoke to "
           << friendList[i][0] << endl;
      string getDaysAgo;
      getline(cin, getDaysAgo);
      friendList[i][1] = getDaysAgo;
    }
  }
}

void deallocateList(int q, string **friendList) {
  for (int i = 0; i < q; ++i) {
    delete[] friendList[i];
  }
  delete[] friendList;
}
