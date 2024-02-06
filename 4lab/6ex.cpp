#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int countSmallestTriangles(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    int leftCount = countSmallestTriangles(root->left);
    int rightCount = countSmallestTriangles(root->right);

    if (root->left != nullptr && root->right != nullptr) {
        return 1 + leftCount + rightCount;
    }

    return leftCount + rightCount;
}

int main() {
    int N;
    cin >> N;

    Node* root = nullptr;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int result = countSmallestTriangles(root);
    cout << result << endl;

    return 0;
}