#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

bool isPathExists(TreeNode* root, string path) {
    TreeNode* current = root;
    for (char direction : path) {
        if (direction == 'L') {
            current = current->left;
        } else if (direction == 'R') {
            current = current->right;
        }
        if (!current) return false;
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    TreeNode* root = nullptr;
    
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }
    
    for (int i = 0; i < M; i++) {
        string path;
        cin >> path;
        
        if (isPathExists(root, path)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}