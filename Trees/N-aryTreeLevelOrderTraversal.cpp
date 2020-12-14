
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/submissions/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> row;
        while(!q.empty()){
            Node* top = q.front();
            if(top == nullptr){
                res.push_back(row);
                q.pop();
                if(q.empty()){
                   break; 
                }
                row.clear();
                q.push(nullptr);
            } else{
                row.push_back(top->val);
                for(int i =0; i < top->children.size(); ++i){
                    q.push(top->children[i]);
                }
                q.pop();
            }           
        }
                
        return res;
    }
};
