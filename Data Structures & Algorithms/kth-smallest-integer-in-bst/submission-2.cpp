/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = -1, kG=-1;
    void dfs(TreeNode* node){
        if(!node) {return;}
        dfs(node->left);
        if(!kG) return;
        kG--;
        if(!kG) {res = node->val;return;}
        dfs(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        kG = k;
        dfs(root);
        return res;
    }
};
