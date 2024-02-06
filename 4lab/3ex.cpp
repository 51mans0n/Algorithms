#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->value);
    preorder(root->left, result);
    preorder(root->right, result);
}

int main() {
    int n, k;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; i++) {
        cin >> gifts[i];
    }
    cin >> k;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = insert(root, gifts[i]);
    }

    vector<int> result;

    TreeNode* currentNode = root;
    while (currentNode->value != k) {
        if (k < currentNode->value) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    preorder(currentNode, result);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}