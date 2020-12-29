class Solution {
public:
  /*
  A graph is a tree if two properties are satisfied:
    - Its connected. (1 connected component)
    - No cycles
   
   Strategy is to Start from node 0, and then do a BFS (or DFS). The bfs function should return true/false whether a cycle exists.
   If a cycle exists, then you return false, as it means its not a tree.
   The way we detect a cycle in the graph, is to maintain Parent array for each node.
   We construct this parent array in the bfs function itself.
   If there's ever an edge between a node and a visited node that is not the parent, then we have a CROSS EDGE.
   A cross edge implies a cycle.
   Also in the BFS function, you need to maintain count of the number of nodes visited. If number of nodes visited is not equal to the total number of nodes after doing BFS, 
   then this implies that there is more than one component in the graph.
    
  
  For example, here there is a cross edge between 1 and 3, since 1 is not parent of 3, but 1 is already visited, and when 3 tries to visit it, it will form a cycle
  between 1, 2, and 3.
       0
       |  
       1 ---  2
       |      | \
        ----- 3  4
  
  Step 1. Make adj graph 
        0 - 1
        1 - 2, 3, 4
        2 - 1, 3
        3 - 1
        4 - 1
  Step 2. Do BFS, modifying visited array and parent array
  Step 3. Check if there is a cycle and whether number of total visited nodes equals the total number of nodes in the graph.
  
  */


    // returns true if a cycle in graph
    bool bfs(map<int, vector<int>> graph, int n, vector<bool>& visited, int startingNode, vector<int> parent, int& numVisited){
       
        queue<int> q; // node, number of nodes it took to get to node 
        q.push(startingNode);
        ++numVisited;
        visited[startingNode] = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            vector<int> neighbors = graph[front];
            for(int neighbor : neighbors){
                if(!visited[neighbor]){
                    parent[neighbor] = front;
                    q.push(neighbor);
                    visited[neighbor] = 1;
                    ++numVisited;
                } else{
                    if(neighbor != parent[front]){
                        return true;
                    }
                }
            }
            
        }
        return false;
        
    }
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
      
        map<int, vector<int>> g;
        for(vector<int> edge : edges){
            int s = edge[0]; int d = edge[1];
            g[s].push_back(d);
            g[d].push_back(s);
        }
        
        vector<bool> visited(n, 0);
        vector<int> parent(n, -1);
        int numVisited = 0;
        //BFS returns whether there is a cycle in the graph
        if(bfs(g, n, visited, 0, parent, numVisited)){
            return false;
        }
        
        return numVisited == n;
    }
};
