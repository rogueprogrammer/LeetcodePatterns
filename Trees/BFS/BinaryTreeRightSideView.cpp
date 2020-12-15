//https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){ // , , , , , , , null
            TreeNode* top = q.front(); 
            if(top != nullptr){
                q.pop();
                if(q.front() == nullptr){
                    res.push_back(top->val); // 1, 3, 4
                }
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            } else{
                q.pop();
                if(q.empty()){
                    break;
                } else{
                    q.push(nullptr);
                }
            }
        }
                
        return res;
    }
};
