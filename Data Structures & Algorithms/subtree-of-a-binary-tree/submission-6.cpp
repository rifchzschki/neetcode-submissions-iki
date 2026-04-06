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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(!p || !q){
            return p || q ? false:  true;
        }
        return p->val == q->val && sameTree(p->left, q->left) && sameTree(p->right, q->right); 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            if(curr->val == subRoot->val){
                cout << curr->val << " " << subRoot->val << endl;
                if(sameTree(curr, subRoot)) return true;
            }
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
        }
        return false;
    }
};
