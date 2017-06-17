#include <iostream>
#include <map>

using namespace std;

void add_user(map<string, string>&);
void remove_user(map<string, string>&);
void change_user(map<string, string>&);
void print_book(map<string, string>);

int main() {
    map<string, string> address_book;

    cout << "STL Address book" << endl;
    cout << "****************" << endl;
    cout << endl;
    do {
        cout << "1. Add a user" << endl;
        cout << "2. Remove a user" << endl;
        cout << "3. Change a user" << endl;
        cout << "4. Print the full address book" << endl;
        int get_input;
        cin >> get_input;
        cin.ignore();
        switch (get_input) {
            case 1:
                add_user(address_book);
                break;
            case 2:
                remove_user(address_book);
                break;
            case 3:
                change_user(address_book);
                break;
            case 4:
                print_book(address_book);
                break;
            default:
                address_book.clear();
                exit(0);
        }
    } while (1);
}

void add_user(map<string, string>& address) {
    bool does_usr_exist = true;
    while (does_usr_exist) {
        string name, email;
        cout << "Please enter the users name" << endl;
        getline(cin, name);
        //cin.ignore();
        cout << "Please enter the users email" << endl;
        getline(cin, email);
        //cin.ignore();

        map<string, string>::iterator itr_name = address.find(name);
        if (itr_name != address.end() && itr_name->second == email) {
            cout << "The user:" << itr_name->first << " is alright in the book" << endl;
        } else {
            address[name] = email;
            does_usr_exist = !does_usr_exist;
        }
    }
}

void remove_user(map<string, string>& address) {
    string name, email;
    cout << "Please enter the users name" << endl;
    getline(cin, name);
    cout << "Please enter the users email" << endl;
    getline(cin, email);

    map<string, string>::iterator itr_name = address.find(name);
    if (itr_name != address.end() && itr_name->second == email) {
        cout << "Are you sure you want to remove " << itr_name->first << " from the address book Y/N" << endl;
        string get_input;
        getline(cin, get_input);
        if (get_input == "Y" || get_input == "y") {
            address.erase(itr_name);
        }
    }
}

void change_user(map<string, string>& address) {
    string name, email;
    cout << "Please enter the users name" << endl;
    getline(cin, name);
    cout << "Please enter the users email" << endl;
    getline(cin, email);

    map<string, string>::iterator itr_name = address.find(name);
    if (itr_name != address.end() && itr_name->second == email) {
        cout << "What would you like to change " << itr_name->first << "'s name to?" << endl;
        getline(cin, name);

        cout << "What would you like to change " << itr_name->first << "'s email to?" << endl;
        getline(cin, email);

        address[name] = email;
    } else {
        string get_input;
        cout << "The user: " << name << " isn't in the address book would you like to add them? Y/N" << endl;
        getline(cin,get_input);
        if (get_input == "Y") {
            address[name] = email;
        }
    }
}

void print_book(map<string, string> address) {
    for (map<string, string>::iterator itr = address.begin(), end = address.end(); itr != end; ++itr) {
        cout << "Name: " << itr->first << endl;
        cout << "Email: " << itr->second << endl;
        cout << endl;
    }
}