#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reverseInOrder(TreeNode* root, int& sum, vector<int>& result) {
    if (root == nullptr) {
        return;
    }

    reverseInOrder(root->right, sum, result);
    sum += root->val;
    result.push_back(sum);
    reverseInOrder(root->left, sum, result);
}

vector<int> replaceKeys(TreeNode* root) {
    vector<int> result;
    int sum = 0;
    reverseInOrder(root, sum, result);
    return result;
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        TreeNode* newNode = new TreeNode(val);

        if (root == nullptr) {
            root = newNode;
        } else {
            TreeNode* current = root;
            while (true) {
                if (val < current->val) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    vector<int> result = replaceKeys(root);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }

    delete root;
    return 0;
}