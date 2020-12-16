/*
 * 深度优先遍历二叉树，用非递归
 */

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
}

int dfs(TreeNode *root) {
    if (root == nullptr) {
        return -1; // error
    }
    stack<TreeNode *> ss;
    ss.push(root);
    TreeNode *tmp = root;
    while (!ss.empty()) {
        tmp = ss.top();
        ss.pop();
        cout << tmp->val << endl;
        if (tmp->right) {
            ss.push(tmp->right);
        }
        if (tmp->left) {
            ss.push(tmp->left);
        }
    }
    return 0;
}


int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}
