// https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/
// passed 91/93 cases 
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
        // do a post order traversal, piping up your sum to the parent and keep updating the global result in theprocess

    /*
    
    
             10
       2           12
     7          20       -8
      
      
     [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6] 
      
                 9
            6        -3
                 -6       2
                         2  
                        -6   -6
                      -6
    */       
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
};
