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
    bool state = true;
    int traverse(TreeNode* root){
        if(!root) return 0;
        int leftCnt = traverse(root->left)+1;
        int rightCnt = traverse(root->right)+1;
        if(abs(leftCnt-rightCnt)>1){state = false;}
        cout << "NODE: " << root->val << " LFCNT: " << leftCnt << " RGTCNT: " << rightCnt << endl;
        return max(leftCnt,rightCnt);
    }
    bool isBalanced(TreeNode* root) {
        // traverse secara dfs
        // pas naik satu nanti count heightnya, terus max buat dibawa sama yang selanjutnya
        // cek kalau diff nya > 1, set false
        traverse(root);
        return state;

    }
};
