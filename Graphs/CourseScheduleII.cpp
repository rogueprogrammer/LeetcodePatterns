class Solution {
public:
        
        /*
        This is a typical topological sort problem, which has the following template:
        Build the graph
        Find the in-degree of each node
        topological_sort = []
        Push all nodes that have in-degree == 0 onto queue
        while q is not empty:
            node cur = q.front
            q.pop
            visit node => add it to topological_sort
            for neighbor in cur's neighbors:
                indegree[neighbor]--
                if indegree[neighbor] == 0
                   push(neighbor)
        
        return topological_sort.size() == numCourses; (all courses were visited in a particular order without cycles)
        */
         vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        
        //compute indegrees
        vector<int> indegrees(numCourses, 0);
        for(vector<int> p : prerequisites){
            int course = p[0];
            indegrees[course]++;
        }
        
        //generate graph
        map<int, vector<int>> adj;
        for(vector<int> p : prerequisites){
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }      
        
        queue<int> q;
        //push all courses with indegree == 0
        for(int i = 0; i < indegrees.size(); ++i){
            if(indegrees[i] == 0) q.push(i);    
        }
        
        while(!q.empty()){
            int course = q.front();
            order.push_back(course);
            vector<int> neighbors = adj[course];
            for(int course : neighbors){
                int indegree = --indegrees[course];
                if(indegree == 0){
                    q.push(course);
                }
            }
            q.pop();
        }
        if(order.size() == numCourses) return order;
        return vector<int>();
        
    }
        
        
    
};
