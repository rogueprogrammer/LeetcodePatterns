// https://leetcode.com/problems/snakes-and-ladders/submissions/
class Solution {
public:
    /*
        [-1,-1,-1,-1,-1,-1],
        [-1,-1,-1,-1,-1,-1],
        
        [-1,-1,-1,-1,-1,-1],
        [-1,35,-1,-1,13,-1],
        [-1,-1,-1,-1,-1,-1],
        [-1,15,-1,-1,-1,-1]]

        Do a BFS to get the shortest path. At each step you can choose current step + 1, +2, .., +6 if the current
        square is -1, otherwise, you go to the square value
        
    */
    int bfs(vector<vector<int>>& board, map<int, pair<int, int>> hm){
        int N = board.size();
        int sRow = N-1;
        int sCol = 0;
        int numMoves = 0;
        queue<pair<int, int>> q; // (val, numMoves)
        set<int> visited;
        
        q.push({1, 0});
        
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            int curVal = cur.first;
            int curMoves = cur.second;
            if(curVal == N*N){
                return curMoves;
            }
            int boardVal = board[hm[curVal].first][hm[curVal].second];
            if(boardVal == -1){
                //add all 6 values to the queue
                for(int i = 1; i <= 6 && curVal + i <= N*N ; ++i){
                    auto it = visited.find(i + curVal);
                    if(it == visited.end()){
                        q.push({i+curVal, curMoves+1});
                        visited.insert(i+curVal);
                    }
                }
            } else{
                q.push({boardVal, curMoves});
                visited.insert(boardVal);
            }
        }
        
        
        return 0;
    }
    
    
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int numRows = board.size();
        int numCols = board[0].size();
        
        int row = numRows - 1;
        int col = 0;
        bool lr = true;
        int val = 1;
        map<int, pair<int, int>> hm;
        
        while(row >= 0){
            while(col >= 0 && col <= numCols-1){
                hm[val++] = {row, col};        
                if(lr){
                    ++col;
                } else{
                    --col;
                }
            }
            lr = !lr;
            --row;
        }
        return bfs(board, hm)-1;
        
    }
};
