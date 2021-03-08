/*   https://leetcode.com/problems/knight-probability-in-chessboard/submissions/
  Idea: Draw out the probability matrices (dp[i]) for each step dp[0], dp[1], dp[2], dp[3] for a 3*3 chess board, it's pretty easy to come up with the algo after that:
  
    let dp[k][r][c] = probability knight is on square [r][c] after k steps
        dp[0][r][c] = 1
        for k = 1 until K
           for i = 0 until N
             for j = 0 until N
                Compute dp[k][i][j] += dp[k-1][i_prime][j_prime] * 1/8 , where (i_prime, j_prime) must be 
                a safe or valid square on the chess board. note I used 0.125 instead of 1/8 for simplicity
        
    Final answer is the summation of dp[K]
    
*/

class Solution {
public:
    
vector<pair<int, int>> moves = {
        {-2, -1}, {-2, 1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-1, 2} , {1, 2}
};

// returns true if (r,c) is on the board
bool isSafe(int r, int c, int N) {
    if (r >= 0 && c >= 0 && r < N && c < N) {
        return true;
    }
    return false;
}

// returns the probability that r, c is the next move based on the previous probability matrix
double getProbability(int r, int c, vector<vector<double>> prev, int k) {
    double p = 0;
    for(int i = 0; i < moves.size(); ++i){
        pair<int, int> move = moves[i];
        int _r = move.first + r;
        int _c = move.second + c;
        if(isSafe(_r, _c, prev.size())){
            p += prev[_r][_c] * 0.125;
        }
    }
    
    return p;
}

//returns sum of a matrix
double sumMatrix(vector<vector<double>> m) {
    double res = 0.0;
    int N = m.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            res += m[i][j];
        }
    }

    return res;
}

double knightProbability(int N, int K, int r, int c) {

    vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0)));

    // base case:
    dp[0][r][c] = 1;

    for (int _k = 1; _k <= K; ++_k) { // for each step up until K steps

        for (int _r = 0; _r < N; ++_r) {

            for (int _c = 0; _c < N; ++_c) {

                double probability = getProbability(_r, _c, dp[_k - 1], _k);
                dp[_k][_r][_c] = probability;
            }
        }
    }

    return sumMatrix(dp[K]);
}

};
