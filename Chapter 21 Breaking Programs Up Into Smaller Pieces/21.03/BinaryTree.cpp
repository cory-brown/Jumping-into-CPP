//
// Created by Cory Brown on 15/05/2017.
//

#include "BinaryTree.h"

void menu(binaryTree* root) {
  int input;

  cout << "1. Print list in sorted order" << endl;
  cout << "2. Print list in sorted an reversed order" << endl;

  cin >> input;

  switch (input) {
    case 1:
      print(root);
      break;
    case 2:
      reverse_print(root);
      break;
    default:
      break;
  }
}

binaryTree* insert_node(binaryTree* root, int data) {
  if (root == NULL) {
    binaryTree* new_node = new binaryTree;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;

    return new_node;
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void print(binaryTree* root) {
  if (root != NULL) {
    print(root->left);
    cout << root->data << endl;
    print(root->right);
  }
}

void reverse_print(binaryTree* root) {
  if (root != NULL) {
    reverse_print(root->right);
    cout << root->data << endl;
    reverse_print(root->left);
  }
}