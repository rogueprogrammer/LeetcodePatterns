// https://leetcode.com/problems/subsets/solution/
class Solution {
public:
    /* if we consider set s = {1, 2, 3} 
we can create recursion tree below of all subsets, at each node, we decide whether to include or exclude the number at the current level. final result is all the leaf nodes
                     {}                                                       
        {}                            {1}                                     i = 0, do we include s[0] = 1, left is exclude 1, right is to include 1
    {}    {2}                 {1}            {1,2}                            i = 1, do we include s[1] = 2, left is to exclude 2, right is to include 2
 {}   {3}   {2}  {2, 3}    {1}  {1,2}   {1,2}     {1,2,3}                     i = 2, do we include s[2] = 3, left is to exclude 3, right is to include 3

Runtime: O(((2^n)/2)*n) = O((2^n)*n) because the number of leaf nodes = 2^n, and each node needs to copy the set of numbers into the result vector, which is an O(n) runtime
operation.
*/     
    vector<vector<int>> res;
    
    void helper(vector<int> nums, int i, vector<int> curSet){
        
        if(i >= nums.size()){
            res.push_back(curSet);
            return;
        }
        
        helper(nums, i+1, curSet); //dont include current elem
        
        curSet.push_back(nums[i]);
        helper(nums, i+1, curSet); //include current elem
        curSet.pop_back(); //return to original state
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curSet;
        helper(nums, 0, curSet);
        return res;          
    }
};
