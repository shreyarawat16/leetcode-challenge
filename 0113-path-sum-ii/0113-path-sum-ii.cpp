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
void solve(TreeNode* root, int k, vector<int> out
        ,vector<vector<int>>& res){
            if(root==NULL){
                return;
            }
        out.push_back(root->val); 
        if( root->left== NULL && root->right==NULL && k==root->val){
            
            res.push_back(out);
        }
        solve(root->left, k-root->val, out, res);
         solve(root->right, k-root->val, out, res);
         out.pop_back();

    }
        
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> out;
        vector<vector<int>> res;
        solve(root, targetSum, out, res);
        return res;
    }
       
};