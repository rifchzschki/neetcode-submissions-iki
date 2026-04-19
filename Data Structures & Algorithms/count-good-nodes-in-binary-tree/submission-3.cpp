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
    // vector<int> parents(1e3, 0);
    // vector<int> sizes(1e3);
    // unordered_map<int, int> maxVal;

    // void make_set(int s){
    //     parents[s] = s;
    //     sizes[s] = 1;
    // }

    // int find_set(int a){
    //     if(parents[a]==a) return a;
    //     return parents[a] = find_set(a);
    // }

    // bool unoin_set(int a, int b){
    //     int pa = find_set(a);
    //     int pb = find_set(b);
    //     if(pa==pb) return false;
    //     if(pa<pb){
    //         swap(pa,pb);
    //     }
    //     parents[pb]=pa;
    //     sizes[pa]+=sizes[pb];
    //     return true;
    // }

    int dfs(TreeNode* root, int maxVal){
        if(!root) return 0;
        if(root->val >= maxVal){
            cout<<root->val<<endl;
            return 1+dfs(root->left, root->val)+dfs(root->right, root->val);
        }else{
            return dfs(root->left, maxVal)+dfs(root->right, maxVal);
        }
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, -1000);
        
    }
};
