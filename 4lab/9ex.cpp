#include <iostream>

using namespace std;

struct Node {
    int key;
    int count; 
    Node* left;
    Node* right;

    Node(int k) : key(k), count(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        root->count++;
    }

    return root;
}

Node* deleteKey(Node* root, int key) {
    if (!root) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteKey(root->left, key);
    } else if (key > root->key) {
        root->right = deleteKey(root->right, key);
    } else {
        if (root->count > 1) {
            root->count--; 
        } else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }

            root->key = temp->key;
            root->count = temp->count;

            root->right = deleteKey(root->right, temp->key);
        }
    }

    return root;
}

int search(Node* root, int key) {
    if (!root) {
        return 0;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else if (key > root->key) {
        return search(root->right, key);
    } else {
        return root->count;
    }
}

int main() {
    Node* root = nullptr;
    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        int X;
        cin >> query >> X;

        if (query == "insert") {
            root = insert(root, X);
        } else if (query == "delete") {
            root = deleteKey(root, X);
        } else if (query == "cnt") {
            int multiplicity = search(root, X);
            cout << multiplicity << endl;
        }
    }

    return 0;
}