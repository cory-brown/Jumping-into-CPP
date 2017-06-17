//
// Created by Cory Brown on 15/05/2017.
//

#ifndef INC_21_03_BINARYTREE_H
#define INC_21_03_BINARYTREE_H

#include <iostream>

using namespace std;

struct binaryTree {
    int data;
    binaryTree* left;
    binaryTree* right;
};


void menu(binaryTree*);
binaryTree* insert_node(binaryTree*, int);
void print(binaryTree*);
void reverse_print(binaryTree*);

#endif //INC_21_03_BINARYTREE_H
