#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return findNode(root->left, val);
    }
    return findNode(root->right, val);
}

int subtreeSize(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + subtreeSize(node->left) + subtreeSize(node->right);
}

int main() {
    int N;
    cin >> N;

    TreeNode* root = nullptr;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int targetVal;
    cin >> targetVal;

    TreeNode* targetNode = findNode(root, targetVal);

    int size = subtreeSize(targetNode);
    cout << size << endl;

    return 0;
}