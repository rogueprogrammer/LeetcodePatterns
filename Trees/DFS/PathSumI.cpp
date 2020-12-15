// https://leetcode.com/problems/path-sum/
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
    
    void dfs(TreeNode* root, int sum, int sumAcc, bool& res){
        if(!root->left && !root->right && sumAcc == sum){ // leaf node
            res = true;
            return;
        }
        //subordinate nodes:
        if(root->left){
            dfs(root->left, sum, sumAcc+root->left->val, res);
        }
        if(root->right){
            dfs(root->right, sum, sumAcc+root->right->val, res);
        }      
    }
    
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root){
            return false;
        }
        int sumAcc = 0;
        bool res = false;
        dfs(root, sum, root->val, res);
        return res;
    }
};
