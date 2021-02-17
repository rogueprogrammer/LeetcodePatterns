// https://leetcode.com/problems/range-sum-query-2d-immutable/

/*
Step 1 - Using the sample matrix from the example, M, create another matrix called dp, which
will store accumulated sums. we define dp[i][j] = sum from M[0][0] to M[i][j]
dp[i][j] = matrix[i][j] + dp[i-1][j-1] + (dp[i-1][j] - dp[i-1][j-1]) + (dp[i][j-1] - dp[i-1][j-1])
Note that extra row and column can be added to remove the need to check edge cases (top row and left most col). Step 1 only takes O(mn) to compute.

Step 2 - Write out the dp matrix for the inputted matrix. It is quite easy to come up with
the formula just eyeballing a sample rectangle
It can be seen that sum(r1, c1, r2, c2) = dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1]
Step2 takes only O(1) to compute. 
*/

class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return;
        }
        int numRows = matrix.size(); 
        int numCols = matrix[0].size();
        
        // note - add extra row and column to remove the need to check edge cases (top row
        // and left most col)
        dp = vector<vector<int>>(numRows+1, vector<int>(numCols+1, 0));
        for(int i = 1; i <= numRows; ++i){
            
            for(int j = 1; j <= numCols; ++j){
                
                dp[i][j] = dp[i-1][j-1] + matrix[i-1][j-1] + (dp[i][j-1] - dp[i-1][j-1]) +
                    (dp[i-1][j] - dp[i-1][j-1]);
                
            }            
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
    }
};

