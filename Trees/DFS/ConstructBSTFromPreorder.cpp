/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    /*
                    [8,5,1,7,10,12]
                        8
                5,1,7[5]     10,12[10]
             1       7                 12
    */
    
    TreeNode* constructBST(vector<int>& preorder, int l, int r){
        if(l > r){
            return NULL;
        }
        if(l == r){
            return new TreeNode(preorder[l]);
        }
        
        TreeNode* root = new TreeNode(preorder[l]);
        int i = l+1;
        for(; i <= r; ++i){
            if(preorder[i] > root->val){
                break;
            }
        }
        root->left = constructBST(preorder, l+1, i-1);
        root->right = constructBST(preorder,i, r);
        return root;        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructBST(preorder, 0, preorder.size()-1);
    }
};
