//https://leetcode.com/problems/number-of-distinct-islands/

class Solution {
public:
    
    /*
        Do a DFS, building strings which represent the island and insert them into a set, and return the size
        of the set
        eg 11 = 1r1
        
        this string will also be able to represent complex islands like this:
        11  1
        11111
        
    */
    
    bool isSafe(vector<vector<int>>& grid, int row, int col){
        int numRows = grid.size();
        int numCols = grid[0].size();
        if(row < 0 || row >= numRows){
            return false;
        }
        if(col < 0 || col >= numCols){
            return false;
        }
        if(grid[row][col] == 0){
            return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, string& island){
        if(!isSafe(grid, row, col)){
            return;
        }
        
        grid[row][col] = 0; // mark as visited
        island += "1";
        
        if(isSafe(grid, row, col-1)){
            island += "l";
            dfs(grid, row, col-1, island); //go left
        }
        
        if(isSafe(grid, row, col+1)){
            island += "r";
            dfs(grid, row, col+1, island); //go right
        }
        
        if(isSafe(grid, row-1, col)){
            island += "u";
            dfs(grid, row-1, col, island); //go down
        }
        
        if(isSafe(grid, row+1, col)){
            island += "d";
            dfs(grid, row+1, col, island); //go down
        }
        island += "end";
    }
    
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> islands;
        int numRows = grid.size();
        int numCols = grid[0].size();
        for(int i = 0; i < numRows; ++i){
            for(int j = 0; j < numCols; ++j){
                if(grid[i][j] == 1){
                    string island = "";
                    dfs(grid, i, j, island);
                    islands.insert(island);
                }
            }
        }
        
        return islands.size();
    }
};
