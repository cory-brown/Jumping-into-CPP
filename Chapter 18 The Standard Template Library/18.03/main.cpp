#include <iostream>
#include <map>

using namespace std;

void register_user(map<string, string>&);
void login_user(map<string, string>&);

int main() {
  int input;
  map<string, string> users;

  do {
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cin >> input; cin.ignore();

    switch(input) {
      case 1:
        register_user(users);
        break;
      case 2:
        login_user(users);
        break;
      default:
        exit(0);
    }
  } while (1);
}

void register_user(map<string, string>& users) {
  bool username_exists = true;
  while (username_exists) {
    string username, password;
    cout << "What username do you want?" << endl;
    getline(cin, username);
    cout << "What password do you want?" << endl;
    getline(cin, password);
    map<string, string>::iterator itr = users.find(username);
    if (itr != users.end()) {
      cout << "This username exists please choose another one" << endl;
    } else {
      users[username] = password;
      username_exists = !username_exists;
    }
  }
}

void login_user(map<string, string>& users) {
  bool try_login = true;
  do {
    string username, password;
    cout << "Login" << endl;
    cout << "*****\n" << endl;
    cout << "Enter your username" << endl;
    getline(cin, username);
    cout << "Enter your password" << endl;
    getline(cin, password);
    map<string, string>::iterator iterator1 = users.find(username);
    if (iterator1 != users.end() && password == iterator1->second) {
        bool usr_is_login = true;
        do {
            int input = 0;
            cout << "Welcome " << iterator1->first << endl;
            cout << "1. Change password" << endl;
            cout << "2. logout" << endl;
            cin >> input; cin.ignore();
            string new_password;
            switch (input) {
                case 1:
                    cout << "New password ";
                    getline(cin, new_password);
                    users[username] = new_password;
                    break;
              default:
                 usr_is_login = !usr_is_login;
                try_login = !try_login;
                break;
            }
        } while (usr_is_login);
    } else {
        cout << "Sorry, we could find you details." << endl;
        try_login = !try_login;
    }
  } while (try_login);
}