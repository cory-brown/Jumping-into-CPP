#include <iostream>

using namespace std;

struct binarytree {
    int data;
    binarytree* left;
    binarytree* right;
};

binarytree* insert_node(binarytree*, int);
void print_tree(binarytree*);
int count_node(binarytree*);

int main() {
    binarytree* root = NULL;
    int rand_num[] = {13, 14, 12, 17, 2};
    for (int i = 0; i < 5; i++) {
        root = insert_node(root, rand_num[i]);
    }
    print_tree(root);
    cout << "\nNumber of nodes in tree: " << count_node(root) << endl;
}


binarytree* insert_node(binarytree* root, int data) {
    if (root == NULL) {
        binarytree* new_node = new binarytree;

        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        return new_node;
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

void print_tree(binarytree* root) {
    if (root != NULL) {
        print_tree(root->left);
        cout << root->data << endl;
        print_tree(root->right);
    }
}

int count_node(binarytree* root) {
    int counter = 1;
    if (root->left != NULL) {
        counter += count_node(root->left);
    }
    if (root->right != NULL) {
        counter += count_node(root->right);
    }
    return counter;
}