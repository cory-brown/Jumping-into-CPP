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

int main() {
    binaryTree* root = NULL;
    int rand_num[] = {13, 14, 12, 17, 2};
    for (int i = 0; i < 5; i++) {
        root = insert_node(root, rand_num[i]);
    }
    menu(root);
}

void menu(binaryTree* root) {
    int input;

    cout << "1. Print list in sorted order" << endl;
    cout << "2. Print list in sorted an reversed order" << endl;

    cin >> input;

    switch (input) {
        case 1:
           // print(root);
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