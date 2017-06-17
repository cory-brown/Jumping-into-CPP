#include "BinaryTree.h"

int main() {
  binaryTree* root = NULL;
  int rand_num[] = {13, 14, 12, 17, 2};
  for (int i = 0; i < 5; i++) {
    root = insert_node(root, rand_num[i]);
  }
  menu(root);
}