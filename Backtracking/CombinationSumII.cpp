

/* same as combination sum I, but also need to add acc and accs which keep track of the numbers, 
for example, consider [10,1,2,7,6,1,5], 8
if one of the subsets is 1, 7, acc becomes 17, and we need to add that to the set of numbers, to ensure that {1,7} doesn't get added twice, which it would normally
since there are two 1's in the above input set of numbers.
*/
void dfs(vector<vector<int>> & res, vector<int> & candidates, int target, vector<int> & slate, int& sumAcc, int index, long long& acc, set<long long>& accs) {

    if (sumAcc > target) {
        return;
    }
    if (sumAcc == target) {
        auto it = accs.find(acc);
        if (it == accs.end()) {
            accs.insert(acc);
            res.push_back(slate);
        }
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        int curNum = candidates[i];
        slate.push_back(curNum);
        int temp = acc;
        acc = (acc * 10) + curNum;
        sumAcc += curNum;
        dfs(res, candidates, target, slate, sumAcc, i + 1, acc, accs);
        acc = temp;
        sumAcc -= curNum;
        slate.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int> & candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res;
    vector<int> slate;
    int sumAcc = 0;
    long long acc = 0;
    set<long long> accs;
    dfs(res, candidates, target, slate, sumAcc, 0, acc, accs);
    return res;
}
