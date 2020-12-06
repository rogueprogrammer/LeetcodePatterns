/* 
* 
idea is to use backtracking algo, where we build a temp vector from scratch, and
whenever we want to add a number into temp, we first search if it already has been used. if not, then we add it to temp, call backtrack recursively again, 
and after the call to backtrack, we just pop off the number we added to temp and mark it as unused as we are no longer including it in our current set.

example:
let nums = [1,2,3], the following is recursion tree on temp variable:

                                   {}
                            {1}                 {2}                       {3}
                        {1, 2}  {1, 3}         {2, 1}      {2, 3}       {3, 1}     {3, 2} 
                     {1, 2, 3}  {1, 3, 2}      {2, 1, 3}  {2, 3, 1}    {3, 1, 2}   {3, 2, 1}

Need to maintain hashset (ht) of accumulated numbers (acc) which represent the tempset that we are looking to insert into result
for example, the set {1, 2, 1} = 121
The reason we do this is to keep track of all **unique set of numbers**. Eg we don't want the set {1,2,1} to be added twice
Like in Permutations I, we need to keep track of the numbers we used.
Before we pick a number out of our set,we check if it is already used. If it is not used, we add it to our temp set and we mark it as used. Then we do dfs and backtrack
(mark as unused).
*/
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& result, set<int>& ht, int& acc) {

    if (temp.size() == nums.size()) {

        auto it = ht.find(acc);
        if (it == ht.end()) {
            ht.insert(acc);
            result.push_back(temp);
        }
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            temp.push_back(nums[i]);
            int tempAcc = acc;
            acc = acc * 10 + nums[i];
            backtrack(nums, used, temp, result, ht, acc);
            acc = tempAcc;
            temp.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;
    set<int> s;
    int acc = 0;
    vector<bool> used(nums.size(), 0);
    backtrack(nums, used, temp, result, s, acc);
    return result;
}




void main() {
    vector<int> nums = { 1, 2, 1 };
    permuteUnique(nums);

    system("PAUSE");
}
