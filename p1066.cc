#include <iostream>
using namespace std;

struct Node {
    int n;
    Node* left;
    Node* right;
    Node() : n(0), left(nullptr), right(nullptr) {}
};

int height(Node* t) {
    if (t == nullptr) return 0;
    return max(height(t->left), height(t->right)) + 1;
}

Node* rotateRight(Node* t) {
    Node* new_root = t->left;
    t->left = new_root->right;
    new_root->right = t;
    return new_root;
}

Node* rotateLeft(Node* t) {
    Node* new_root = t->right;
    t->right = new_root->left;
    new_root->left = t;
    return new_root;
}

Node* rotateLeftRight(Node* t) {
    t->left = rotateLeft(t->left);
    return rotateRight(t);
}

Node* rotateRightLeft(Node* t) {
    t->right = rotateRight(t->right);
    return rotateLeft(t);
}

Node* insert(Node* root, int n) {
    if (root == nullptr) {
        root = new Node();
        root->n = n;
    }
    else if (n < root->n) {
        root->left = insert(root->left, n);
        if (height(root->left) - height(root->right) >= 2) {
            if (n < root->left->n) {
                root = rotateRight(root);
            }
            else {
                root = rotateLeftRight(root);
            }
        }
    }
    else {
        root->right = insert(root->right, n);
        if (height(root->right) - height(root->left) >= 2) {
            if (n > root->right->n) {
                root = rotateLeft(root);
            }
            else {
                root = rotateRightLeft(root);
            }
        }
    }

    return root;
}

int main()
{
    int n, v;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        root = insert(root, v);
    }
    cout << root->n << endl;
    return 0;
}

