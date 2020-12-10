
// https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    
    /*
        {}
     {1}                    {2}                   {2}
   {1,2} {1,2}         {2,1} {2,1}               {2,1} {2,1}
 {1,2,2}  {1,2,2}     {2,1,2}  {2,1,2}          {2,1,2}  {2,12}
    Same as subsets I, but need to maintain a set of all the visited subsets, which I represent as an integer. eg - {1,2,3} is represented as 123.
    Check if the visited integer exists before inserting it into resulting set.
    */
    
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> slate, int index, set<int>& s, int& acc){
        
        if(index > nums.size()){
            return;
        }
        if(acc == 0){
            res.push_back(slate);
        }else{
            auto it = s.find(acc);
            if( it == s.end()){
                s.insert(acc);
                res.push_back(slate);
            }
        }
        for(int i = index; i < nums.size(); ++i){
            slate.push_back(nums[i]);
            int temp = acc;
            acc = (acc*10)+nums[i];
            dfs(res, nums, slate, i+1, s, acc);
            acc = temp;
            slate.pop_back();
        }
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> slate;
        set<int> s;
        int acc = 0;
        sort(nums.begin(), nums.end());
        dfs(res, nums, slate, 0, s, acc);
        return res;
    }
};
