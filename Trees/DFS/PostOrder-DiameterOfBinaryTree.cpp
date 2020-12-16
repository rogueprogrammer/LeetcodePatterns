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
                        a
                b                  c
        d          e
      
      The diameter at any node is equal to l + r + 1, where l is height of left subtree and r is height of right subtree
      The height/depth of the node needs to be piped up to the parent node, and is computed as max(l, r)+1
      The idea is to use a bottom up, post-order traversal which pipes up the height of a node to its parent, but also
      updates the diameter. The diameter relies on the height of both the left and right subtrees of any node.
    */
    
    int getHeight(TreeNode* root, int& res){
        
        if(!root){
            return 0;
        }
        
        int lh = getHeight(root->left, res);
        int rh = getHeight(root->right, res);
        
        // update the final answer which should be the length of the diameter/inverted v at this intermediary node, root
        res = max(res, lh + rh);
        
        //pipe up the height at this intermediary node, root:
        return max(lh, rh) + 1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = 0;
        getHeight(root, res);
        return res;
    }
};
