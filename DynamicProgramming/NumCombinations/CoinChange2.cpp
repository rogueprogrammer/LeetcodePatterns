// https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    /*
    let dp[k, a] = number of ways to make amount of value a, using c1, .., ck coins
    At each step, we either use ck or we don't.
    If we don't use ck, then dp[k, a] = dp[k-1][a]
    If we do use ck, then dp[k, a] = dp[k][a - c[k]]
    Therefore, dp[k, a] = dp[k-1][a] + dp[k][a - c[k]]
                          where [ a - c[k] >= 0]
    
    Base cases: i) if dp[0, a] = 0
                ii) if dp[k, 0] = 1
    
    Example: amount = 5, coins = [1, 2, 5]
    
    dp[k, a] = dp[k-1][a] + dp[k][a - c[k]]
    
                      0      1        2       3       4           5
    0                 0      0        0       0       0           0
    1 (1)             1      1        1       1       1           1
    2 (1, 2)          1        
    3 (1, 2, 5)       1
    note that dp[2, 1] = dp[1][1] + dp[2][-1], second part is not possible, so we check
    if its greater than 0.
    
    dp[3, 5] = dp[2][5] + dp[3][5 - coins[3]]
             = dp[2][5] + dp[3][0]
    
    */
    
    
    int change(int amount, vector<int>& coins) {
        int k = coins.size();
        if(k == 0 && amount == 0){
            return 1;
        }
        if(k == 0){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        vector<vector<int>> dp(k+1, vector<int>(amount+1));
        // base case: k == 0
        for(int i = 0; i <= amount; ++i){
            dp[0][i] = 0;
        }
        // base case: amount == 0
        for(int i = 1; i <= k; ++i){
            dp[i][0] = 1;
        }
        
        for(int i = 1; i <= k; ++i){
            
            for(int j = 1; j <= amount; ++j){
                dp[i][j] = dp[i-1][j];
                if(j - coins[i-1] >= 0) {
                   dp[i][j] += dp[i][j - coins[i-1]];
                }
            }
            
        }
        return dp[k][amount];
            
    }
};
