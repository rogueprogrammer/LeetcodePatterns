class Solution {
public:
    
    /*
    [2,3,6,7], sum = 7
    
        {}
      {2}                                         {3}        {6}        {7}
   {2,2} {2,3} {2,6}                         {3,3} {3,6}
 {2,2,2} {2,2,3}                            {3,3,6}  
 {2,2,2,2}
    
    
    */
    /*
    we need to maintain the index variable so we know to only look at numbers that are after the current number in order
    to avoid having duplicates
    time complexity: let n = len(candidates), t = target sum, m= min num in candidates array
    O(n^(t/m)
    
    [2,6], t = 7
    [2], [2,2] , [2,2,2], [2,2,2,2], [2,6], [6]
    2^(7/2)
    2^3    
    */
    void dfs(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& slate, int& sumAcc, int index){
        
        if(sumAcc > target){
            return;
        }
        if(sumAcc == target){
            res.push_back(slate);
            return;
        }
        
        for(int i = index; i < candidates.size(); ++i){
            int curNum = candidates[i];
            slate.push_back(curNum);
            sumAcc+= curNum;
            dfs(res, candidates, target, slate, sumAcc, i);
            sumAcc -= curNum;
            slate.pop_back();
        }
        
    }    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> slate;
        int sumAcc = 0;
        dfs(res, candidates, target, slate, sumAcc, 0);
        
        return res;
    }
};
