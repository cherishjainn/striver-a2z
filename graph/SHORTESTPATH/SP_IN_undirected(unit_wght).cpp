Basically simple logic 
DO A SIMPLE TRAVERSAL AND FIND LOOK FOR SHORTEST PATH 
If we find a shorter distance to a neighboring node than the distance we knew before,
 we update its distance and push that neighbor into the queue again, 
 because a shorter path to that node may also produce shorter paths to all the nodes reachable from it


 Unit-weight graph (BFS): Each node is usually pushed once because the first visit gives the shortest distance.

NOTE: THIS QUES CAN BE DONE SIMPLY BY TAVERSING AND KEPING A VISIT ARRAY FIRST TIME WEHN NODE FIND THAT IS ITS MIN DISTANCE AS LEVEL WISE TRAVERSAL IS HAPPING !!

 // Function to find the shortest path from source to all vertices
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {

        // Create an adjacency list of size N to store the undirected graph
        vector<int> adj[N]; 

        // Build the graph by adding edges to the adjacency list
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        // Initialize the distance array with a large value (treated as infinity)
        int dist[N];
        for (int i = 0; i < N; i++) 
            dist[i] = 1e9;

        // Set the source node distance to 0
        dist[src] = 0;

        // Use a queue to perform BFS traversal
        queue<int> q;

        // Start BFS from the source node
        q.push(src); 

        // Loop until queue is empty
        while (!q.empty()) {

            // Get the front node from the queue
            int node = q.front(); 
            q.pop(); 

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {

                // If a shorter path to neighbor is found
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }

        // Initialize the result array with -1 for unreachable nodes
        vector<int> ans(N, -1);

        // Fill in the result array with distances where reachable
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }

        // Return the final shortest distances
        return ans; 
    }