/*
https://leetcode.com/problems/subsets/submissions/
                    {}
             {1}              {2}          {3}
            {1,2} {1,3}       {2,3}        
          {1,2,3}
*/


void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int> slate, int index) {

    if (index > nums.size()) {
        return;
    }

    res.push_back(slate);

    for (int i = index; i < nums.size(); ++i) {
        slate.push_back(nums[i]);
        dfs(res, nums, slate, i + 1);
        slate.pop_back();
    }

}


vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> slate;
    dfs(res, nums, slate, 0);
    return res;
}
