// https://leetcode.com/problems/subsets/solution/
class Solution {
public:
    /*  s = {1, 2, 3} 
* recursion tree below, at each node, we decide whether to include or exclude the number at the current level.
                     {}                                                       
        {}                            {1}                                     i = 0, do we include s[0] = 1, left is exclude 1, right is to include 1
    {}    {2}                 {1}            {1,2}                            i = 1, do we include s[1] = 2, left is to exclude 2, right is to include 2
 {}   {3}   {2}  {2, 3}    {1}  {1,2}   {1,2}     {1,2,3}                     i = 2, do we include s[2] = 3, left is to exclude 3, right is to include 3

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
