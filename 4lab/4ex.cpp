#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void findMaxLevelAndSum(TreeNode* root, int level, vector<int>& levelSums) {
    if (!root) {
        return;
    }
    if (level >= levelSums.size()) {
        levelSums.push_back(0);
    }
    levelSums[level] += root->val;
    findMaxLevelAndSum(root->left, level + 1, levelSums);
    findMaxLevelAndSum(root->right, level + 1, levelSums);
}

int main() {
    int n;
    cin >> n;
    vector<int> permutation(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> permutation[i];
    }
    
    TreeNode* root = NULL;
    vector<int> levelSums;
    
    for (int i = 0; i < n; ++i) {
        root = insert(root, permutation[i]);
    }
    
    findMaxLevelAndSum(root, 0, levelSums);
    
    int maxLevel = levelSums.size();
    
    cout << maxLevel << endl;
    
    for (int i = 0; i < maxLevel; ++i) {
        cout << levelSums[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}