// https://leetcode.com/problems/permutations/submissions/
// similar to the solution in Permutations II, where we check used vector instead of searching if the element is in temp before adding to temp.

class Solution {
public:
    
    /*
    s = {1, 2, 1}
    
    1        2         1                    i = 0, 3 choices
 12  11   21   21     11  12                  i = 1, 2 choices
 121  112  211  211    112   121              i = 2, 1 choice
    */
    
    
   void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& result) {

    if (temp.size() == nums.size()) {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp, result);
            temp.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;

    vector<bool> used(nums.size(), 0);
    backtrack(nums, used, temp, result);
    return result;
}
};
