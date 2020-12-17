
class Solution {
public:
    
    /*
    https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/
    
      l             r
      0    1  2  3  4
    [-10, -3, 0, 5, 9]
    
                                                cBST(nums, 0, 4), root = nums[2]=0
             cBST(nums, 0, 1), root=nums[0]=-10                               cBST(nums, 3, 4), root=nums[3] = 5
 cBST(nums, 0, -1) null    cBST(nums, 1, 1), root=nums[1]=-3     cBST(nums, 3, 2),null    cBST(4,4),root=nums[4]=9  
       
        0
     -10  5
    -3      9   
       
       
    */
    TreeNode* constructBST(vector<int>& nums, int l, int r){
        if(l > r){ //we come up with this case by constructing the recursion tree as shown above
            return NULL;
        }
        
        if(l == r){ //base case
            return new TreeNode(nums[l]);
        }
        else{
            int m = (l+r)/2;
            TreeNode* root = new TreeNode(nums[m]);
            root->left = constructBST(nums, l, m-1);
            root->right = constructBST(nums, m+1, r);
            return root;
        }
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = constructBST(nums, 0, nums.size()-1);
        return root;        
    }
};
