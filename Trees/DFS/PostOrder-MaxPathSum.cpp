// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
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

// solution i came up with after seeing solution:
 int dfs(TreeNode* root, int& res){
        if(!root){
            return 0;
        }
        int left = max(0, dfs(root->left, res)); 
        int right = max(0, dfs(root->right, res)); //compute value of right subtree
        res = max(res, root->val+left+right);
        return max(root->val+left, root->val+right);
    } 
    
    
    int maxPathSum(TreeNode* root) {
        
        int res = 0;
        res = INT_MIN;
        dfs(root, res);
        return res;
    }

/* MY ORIGINAL SOLUTION, passed 91/93 cases
class Solution {
public:
        // do a post order traversal, piping up your sum to the parent and keep updating the global result in theprocess

    
    int dfs(TreeNode* root, int& res){
        
        if(!root->left && !root->right){
            res = max(res, root->val); //6
            return root->val;
        }
        
        int leftSum = 0; int rightSum = 0;
        if(root->left){
            leftSum = dfs(root->left, res); //6
        }
        if(root->right){
            rightSum = dfs(root->right, res);
        }
        
        int max1 = max(res, root->val);
        int max2 = max(max(root->val+leftSum, root->val+rightSum), root->val+leftSum+rightSum);
        res = max(max1, max2);        
        
        return max(leftSum, rightSum) + root->val;
    } 
    
    
    int maxPathSum(TreeNode* root) {
        
        int res = 0;
        if(!root){
            return res;
        }
        res = root->val;
        dfs(root, res);
        return res;
    }
*/
};
