//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/
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
    Example tree:
    
                    a
                  b     c
                d   e    f  g
               h i  j    k   l m
    [a],   [c, b], [d,e, f,g], [m, l, k, j, i, h]
    
    Idea: code up normal breadth first traversal, then modify it such that at every other level, you add a reversed
    version of the level of the tree. the way to make a row reversed (without reversing it iteratively once the level is complete), is to use a deque and push elements to the front of it. When you want to add elements normally, then add to the back of the deque. 
    
    runtime: O(n)    
    */
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root); 
        q.push(nullptr);
        deque<int> row;
        bool leftright = 1;
        while(!q.empty()){ // q = , , , , , , , null
            TreeNode* top = q.front(); // 15
            q.pop();
            if(top == nullptr){
                vector<int> v(row.begin(), row.end());
                res.push_back(v);
                if(q.empty()){
                    break;
                } else{    
                    q.push(nullptr);
                    leftright = !leftright; //leftright = 1
                    row.clear();
                }
            } else{
                if(leftright){
                    row.push_back(top->val);
                } else{
                    row.push_front(top->val);
                }
                                
                if(top->left){
                    q.push(top->left); 
                }
                if(top->right){
                    q.push(top->right);
                }
            }
            
        }
                
        return res;
    }
};
