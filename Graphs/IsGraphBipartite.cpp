
// https://leetcode.com/problems/is-graph-bipartite/submissions/
  /*

  To check if graph is bipartite, need to find out if the graph can have 2-coloring.
  Do BFS on the graph,  for every node visited color it one color and colors its neighbors the opposite color. 
  Do not visit the same node twice (check if the node has already been colored).
  Then go through the coloring vector and check if for every node, its neighbors have a different color. If this is true, then we have bipartite graph. else, its not bipartite.

    Using example 2,

    coloring vector:
    0   1   2   3
    r   b   b   b

*/
    

bool isBipartite(vector<vector<int>>&graph) {

    // coloring is either 0 - not yet colored, 1 - red, 2 - blue    
    vector<int> coloring(graph.size(), 0);

    // loop through all the nodes and do a BFS on it
    for (int i = 0; i < graph.size(); ++i) {
        //do a BFS on all neighbors marking current node as well as neighbors
        if (coloring[i] != 0) { // already colored
            continue;
        }
        int curColor = 1;

        coloring[i] = curColor;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            curColor = (curColor == 1) ? 2 : 1;
            vector<int> neighbors = graph[curNode];
            for (int neighbor : neighbors) {
                if (coloring[neighbor] != 0) {
                    // only visit the node and color it if it hasn't been colored before
                    continue;
                }
                coloring[neighbor] = curColor;
                q.push(neighbor);
            }
        }
    }

    // loop through coloring vector to see if for each node, its neighbors are a different color
    for (int i = 0; i < coloring.size(); ++i) {
        vector<int> neighbors = graph[i];
        for (int j = 0; j < neighbors.size(); ++j) {
            int neighbor = neighbors[j];
            if (coloring[neighbor] == coloring[i]) {
                return false;
            }
        }
    }
    return true;



}
