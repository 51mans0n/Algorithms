#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findWidth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    queue<pair<TreeNode*, int>> q; 
    q.push({root, 0});
    unordered_map<int, int> levelWidth; 

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

           
            levelWidth[level]++;

          
            if (node->left) {
                q.push({node->left, level + 1});
            }
            if (node->right) {
                q.push({node->right, level + 1});
            }
        }
    }

    int maxWidth = 0;
    for (auto& entry : levelWidth) {
        maxWidth = max(maxWidth, entry.second);
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode*> nodes(n + 1);

    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode(i);
    }

    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    int maxWidth = findWidth(nodes[1]); 
    cout << maxWidth << endl;

    return 0;
}