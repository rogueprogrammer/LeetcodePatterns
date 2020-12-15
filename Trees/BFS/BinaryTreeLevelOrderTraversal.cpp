//https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/

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
    3
  9  20
     15  7
    
    Q: , , 20, 15, 7
    
    */
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        TreeNode* n = root;
        q.push(n);
        TreeNode* nullNode = nullptr;
        q.push(nullNode); //marker for end of level
        vector<int> row;
        
        while(!q.empty()){ // 3, null, 9, 20
            TreeNode* top = q.front();
            if(top == nullptr){
                res.push_back(row);
                row.clear();
                q.pop();
                if(!q.empty()){
                    q.push(nullNode);
                }
            }
            else{
                row.push_back(top->val); // {3
                if(top->left){
                    q.push(top->left);
                } 
                if(top->right){
                    q.push(top->right);
                }
                q.pop();
            }
        }
        
        return res;
    }
};
