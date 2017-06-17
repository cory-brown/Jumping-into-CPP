//  1. Write a program to remove an element from a linked list; the remove
//  function should take just
//  the element to be removed. Is this function easy to write—and will it be
//  fast? Could this be
//  made easier or faster by adding an additional pointer to the list?
//  Yes by creating a doubly linked could use the pointer as Previous pointer
//  2. Write a program that adds elements to a linked list in sorted order,
//  rather than at the beginning.
//  3. Write a program to find an element in a linked list by name.

#include <cstdlib>
#include <iostream>

using namespace std;

struct Contact {
  string name;
  long int number;
  Contact *next;
};

Contact *Contact_head = NULL; // Head

void menu();         // prints menu
bool isEmpty();      // checks if the list is empty
void insertPerson(); // inserts new person of the beginning of the list
void removePerson(); // remove person
void findPerson();   // find person by name and/or number
void printList();    // prints the list

int main() { menu(); }

void menu() {
  int option;
  do {
    cout << "\nPlease choose an option" << endl;
    cout << "1. Remove person" << endl;
    cout << "2. Add person" << endl;
    cout << "3. Find person" << endl;
    cout << "4. Print full list" << endl;
    cout << "5. Exit" << endl;
    cout << "Option: ";
    cin >> option;
    cout << endl;
    switch (option) {
    case 1:
      removePerson();
      break;
    case 2:
      insertPerson();
      break;
    case 3:
      findPerson();
      break;
    case 4:
      printList();
      break;
    default:
      exit(0);
    }
  } while (option != 5);
}

bool isEmpty() {
  if (Contact_head == NULL) {
    cout << "List is currently empty" << endl;
    return true;
  } else {
    return false;
  }
}

void insertPerson() {
  // create new node (add Person)
  Contact *newPerson = new Contact; // new Person
  Contact *person_next = Contact_head;
  Contact *person_previous = person_next;
  bool sorted = false;

  cout << "Enter Name:";
  string getName;
  cin.ignore();
  getline(cin, getName);
  newPerson->name = getName; // get name of the person and add it to the node

  cout << "Enter Phone number: ";
  long int new_number;
  cin >> new_number;
  newPerson->number =
      new_number; // get number of the person and add it to the node

  if (Contact_head == NULL) { // add it to the start of the list if empty
    newPerson->next = Contact_head;
    Contact_head = newPerson;
  } else {
    while (person_next != NULL && !sorted) {
      if (person_next->name.at(0) > newPerson->name.at(0)) {
        if (person_previous == Contact_head) {
          newPerson->next = Contact_head;
          Contact_head = newPerson;
          sorted = !sorted;
        } else {
          newPerson->next = person_next;
          person_previous->next = newPerson;
          sorted = !sorted;
        }
      } else {
        if (person_next->next == NULL) { // end of list
          person_next->next = newPerson;
          newPerson->next = NULL;
          sorted = !sorted;
        }
      }
      person_previous = person_next;   // Previous Node of current
      person_next = person_next->next; // move to the next node in list
    }
  }
}

void removePerson() {
  if (!isEmpty()) {
    string rm_name;
    long int rm_num;
    cout << "Which person do you want to remove?" << endl;
    printList();

    cout << "Enter name: " << endl;
    cin.ignore();
    getline(cin, rm_name);

    cout << "Enter phone number" << endl;
    cin >> rm_num;

    Contact *person_current = Contact_head;
    Contact *person_previous = person_current;

    while (person_current != NULL) {
      if ((person_current->name == rm_name) &&
          ((person_current->number == rm_num))) {
        if (person_current == Contact_head) { // Remove the first node
          Contact_head = person_current->next;
        } else if (person_current->next == NULL) { // Remove a node at the end of the list
          person_previous->next = NULL;
        } else { // Remove a node in the middle of the list
          person_previous->next = person_current->next;
        }
        delete person_current;
        person_current = NULL;
      } else {
        person_previous = person_current;      // Previous Node of current
        person_current = person_current->next; // move to the next node in list
      }
    }
  }
}

void findPerson() {
  if (!isEmpty()) {
    string findName;
    Contact *person_it = Contact_head;
    cout << "Which person are you looking for?" << endl;

    cout << "Enter name: " << endl;
    cin.ignore();
    getline(cin, findName);

    while (person_it != NULL) {
      if ((findName == person_it->name)) {
        cout << "Found: " << person_it->name << " " << person_it->number
             << endl;
      }
      person_it = person_it->next;
    }
    delete person_it;
    person_it = NULL;
  }
}

void printList() {
  if (!isEmpty()) {
    Contact *person_it = Contact_head;
    while (person_it != NULL) {
      cout << person_it->name << " " << person_it->number << endl;
      person_it = person_it->next;
    }
  }
}
