#include <iostream>
#include <vector>
#include <algorithm>

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
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int findMaxDistance(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftMaxDistance = findMaxDistance(root->left);
    int rightMaxDistance = findMaxDistance(root->right);

    return max(max(leftMaxDistance, rightMaxDistance), leftHeight + rightHeight);
}

int main() {
    int N;
    cin >> N;
    vector<int> values(N);

    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    TreeNode* root = nullptr;

    for (int i = 0; i < N; ++i) {
        root = insert(root, values[i]);
    }

    int maxDistance = findMaxDistance(root) + 1;
    cout << maxDistance << endl;

    return 0;
}