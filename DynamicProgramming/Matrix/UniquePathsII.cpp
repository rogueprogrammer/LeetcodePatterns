// https://leetcode.com/problems/unique-paths-ii/
class Solution {
public:
    
    /*
    m:
    0    0    0 
    0    1    0
    0    0    0
    
    dp:
    1    1    1
    1    -1   1
    1     1   2
    
    0    1    0    1
    0    0    0    1
    0    1    0    0
    0    0    0    0
    
    dp:
    1    -1   -1   -1
    1     1    1   -1
    1    -1    1    1
    1    1     2    3
    
    let dp[i][j] =  number of unique paths from M[0][0] to M[i][j]
    if i == 0 && j== 0 => dp[i][j] = 1
    basecase 1 - for row == 0 => dp[0][j] = (M[0][j] == 1) ? -1 : dp[0][j-1]
    basecase 2 - for col == 0 => dp[i][0] = (M[i][0] == 1) ? -1 : dp[i-1][0]
    
    if(m[i][j] == 1){dp[i][j] = -1}
    up = dp[i-1][j]
    left = dp[i][j-1]
    
    if up and left both are -1, then dp[i][j] = -1
    if only one is -1, then return the one that is not -1.
    else if both are not -1, then return the sum.
    
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
        if(m == 1 && n == 1){
            return !obstacleGrid[0][0];
        }
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        dp[0][0] = 1;
        
        for(int i = 1; i < m; ++i){
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = -1;
            } else{
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for(int i = 1; i < n; ++i){
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = -1;
            } else{
                dp[0][i] = dp[0][i-1];
            }
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = -1;
                } else{
                    int res = 0;
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    if(up != -1){
                        res += up;
                    }
                    if(left != -1){
                        res += left;
                    }
                    if(res == 0){
                        res = -1;
                    }
                    dp[i][j] = res;
                } 
            }
        }
        if(dp[m-1][n-1] == -1){
            return 0;
        }
        return dp[m-1][n-1];
    }
};
