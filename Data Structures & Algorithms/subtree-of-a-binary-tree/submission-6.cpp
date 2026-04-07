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
    void calculateZ(vector<int>& z, const string& s){
        int l=0, r=0;
        cout << s << endl;
        for(int k=1;k<s.length();k++){
            if(k>r){ //outside box
                l = r = k;
                while(r<s.length() && s[r]==s[r-l]){
                    r++;
                }
                z[k] = r-l;
                r--;
            }else{
                int k1 = k-l;
                if(z[k1] < r-k+1){
                    z[k] = z[k1];
                }else{
                    l = k;
                    while(r<s.length() && s[r]==s[r-l]){
                        r++;
                    }
                    z[k] = r-l;
                    r--;
                }
            }
        }
    }


    string encode(TreeNode* root){
        if(!root) return "&";
        return "$" + to_string(root->val) + "*" + encode(root->left) + "*" + encode(root->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        string sR = encode(subRoot);
        string sr = encode(root);
        string s = sR + "|" + sr;
        vector<int> z(s.length(),0);
        calculateZ(z, s);
        for(const int zVal: z){
            if(zVal==sR.length()) return true;
        }
        return false;
    }
};
