
// https://leetcode.com/problems/path-sum-ii/submissions/
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
    
    /*
    Template is to always pass the root value into the dfs funciton, and then in dfs function, during recursive case, add the left or right values into the variables
    that need to be passed to lower stages in the tree.
    Runtime complexity: Line 26, pushing the path to res, the worse case scenario is when we have a complete binary tree and every path to leaf nodes
    the path can be max length logn, and the number of leaf nodes in this scenario would be n/2. Thus, the time complexity is O(n/2*logn) = O(nlogn)
    */
    void dfs(TreeNode* root, int sum, int sumAcc, vector<vector<int>>& res, vector<int> path){
        
        if(!root->left && !root->right && sumAcc == sum ){
            res.push_back(path);
            return;
        }
        
        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left, sum, sumAcc+root->left->val, res, path);
            path.pop_back();
        }
        
        if(root->right){
            path.push_back(root->right->val);
            dfs(root->right, sum, sumAcc+root->right->val, res, path);
            path.pop_back();
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(!root){
            return res;
        }
        path.push_back(root->val);
        dfs(root, sum, root->val, res, path);
        return res;
    }
};
