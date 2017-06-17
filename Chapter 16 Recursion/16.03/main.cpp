//
// 3. Write a recursive algorithm to remove elements from a linked list.
// Write a recursive algorithm to add elements into a linked list.
// Try writing the same algorithms using iteration. Do the recursive
// implementations or the iterative
// implementations feel more natural?

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Contact {
  string name;
  long int number;
  Contact *next;
};

Contact* insertPerson(Contact*, string, long int); // inserts new person of the beginning of the list
Contact* removePerson(Contact*, string, long int);          // remove person
void printList(Contact*);    // prints the list


int main() {
  Contact *p_list = NULL; // list

  string input_name;
  long int input_number;
  int input_decision;

  while (input_decision != 4) {

    cout << "\nPlease choose an option" << endl;
    cout << "1. Add person" << endl;
    cout << "2. Remove person" << endl;
    cout << "3. Print full list" << endl;
    cout << "4. Exit" << endl;
    cout << "Option: ";

    cin >> input_decision;
    cin.ignore();
    switch (input_decision) {
      case 1:
        cout << "Enter name" << endl;
        getline(cin, input_name);
        cout << "Enter number" << endl;
        cin >> input_number;

        p_list = insertPerson(p_list, input_name, input_number);
        break;

      case 2:
        cout << "Which person do you want to remove?" << endl;
        printList(p_list);
        cout << "Enter name" << endl;
        getline(cin, input_name);
        cout << "Enter number" << endl;
        cin >> input_number;

        p_list = removePerson(p_list, input_name, input_number);
        break;

      case 3:
        printList(p_list);
        break;

      case 4:
        exit(0);

      default:
        cout << "Error please, please try again." << endl;
        break;
    }
  }
}

Contact* insertPerson(Contact* p_list, string name, long int number) {
  if (p_list == NULL) {
    Contact* new_person = new Contact; // Create new person node

    new_person->name = name; // assign name to person
    new_person->number = number; // assign number to person

    new_person->next = p_list; // point previous node to new node
    p_list = new_person; // point new node to next node

  } else {
    p_list->next = insertPerson(p_list->next, name, number); // recursively iterative through the list
  }

  return p_list;
}

Contact* removePerson(Contact* p_list, string name, long int number){

    if (p_list == NULL) { // if the query doesn't match any of the nodes in the list
        cout << "Person found" << endl;
        return p_list;
    } else if (p_list->name == name && p_list->number == number) { // if the query matches a nodes in the list
        Contact* delete_node;
        delete_node = p_list->next;
        delete p_list;
        return delete_node;
    } else {
        p_list->next = removePerson(p_list->next, name, number); // recursively iterative through the list
        return p_list;
    }

}

void printList(Contact* p_list) {
  if (p_list != NULL) {
    cout << p_list->name << " " << p_list->number << endl;
    printList(p_list->next); // recursively iterative through the list
  }
}
