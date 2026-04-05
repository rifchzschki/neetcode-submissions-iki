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
    int globalMax = 0;

    int traverse(TreeNode* root){
        if(!root) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        globalMax = max(globalMax , left+right);
        return 1 + max(left, right);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return globalMax;
    }
};
