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
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        unordered_map<TreeNode*, int> depths;

        while (!stack.empty() || node != nullptr) {
            if (node != nullptr) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                if (node->right == nullptr || last == node->right) {
                    stack.pop();
                    int left = depths[node->left];
                    int right = depths[node->right];
                    if (abs(left - right) > 1) return false;
                    depths[node] = 1 + max(left, right);
                    last = node;
                    node = nullptr;
                } else {
                    node = node->right;
                }
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool state = true;
//     int traverse(TreeNode* root){
//         if(!root) return 0;
//         int leftCnt = traverse(root->left)+1;
//         int rightCnt = traverse(root->right)+1;
//         if(abs(leftCnt-rightCnt)>1){state = false;}
//         cout << "NODE: " << root->val << " LFCNT: " << leftCnt << " RGTCNT: " << rightCnt << endl;
//         return max(leftCnt,rightCnt);
//     }
//     bool isBalanced(TreeNode* root) {
//         // traverse secara dfs
//         // pas naik satu nanti count heightnya, terus max buat dibawa sama yang selanjutnya
//         // cek kalau diff nya > 1, set false
//         traverse(root);
//         return state;

//     }
// };
