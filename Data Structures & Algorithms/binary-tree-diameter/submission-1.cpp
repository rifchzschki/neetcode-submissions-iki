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
        int next = 1 + max(left, right);
        cout << left << " " << right << endl;
        globalMax = max(globalMax , left+right);
        return next;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return globalMax;
    }
};
