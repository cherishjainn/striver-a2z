https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1

LOGIC --> 
* we will first arrange nodes in topological order beacuse in topo.. order for any node all nodes that are invloved in different paths from source to current node are already there
"SO TILL THE POINT WE REACHED A NODE WE ALREADY CALCUATED DISTANCES OF DIFF PATHS AND WE  UPDATE DISTANCE OF NODE AS WE PROCED IN STACK"

Processing the vertices in topological order ensures that by the time you get to a vertex, youve already processed all the vertices that can precede it 

Once we have topological order (or linear representation), 
we one by one process all vertices in topological order.
 For every vertex being processed, we update distances of its adjacent using distance of current vertex. 
 and if new distance calculated is less than previousy calculated distance then update in dist array !!!! $$ IMPORTANT $$



  //source -> 0
   void dfs(int node ,vector<vector<pair<int,int>>> &graph , stack<int> &s , vector<int> &visit){
     visit[node] =1;
     for(auto adj : graph[node]){
         int u =adj.first;
         if(!visit[u]){
             dfs(u,graph,s,visit);
         }
     }
      s.push(node); //think of recursion ,  in last level no adj , so push that as it is stack when popped will come in last in topo sort list  
       
   }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
       // convert edges to standard form 
       vector<vector<pair<int,int>>> graph(V);
       for(int i = 0 ; i<E; i++){
           int u = edges[i][0]; 
           int v = edges[i][1];
           int w = edges[i][2]; // dist 
           graph[u].push_back({v,w});
       }
       // form topological order 
       //use dfs/stack method (can use  kahn as well)
    vector<int> visit(V);
    stack<int> s;
    dfs(0,graph,s,visit);
    // we have got the filled stack 
    
    // start main algo of filling distance vector 
    vector<int> dist(V,INT_MAX); 
    
    dist[0] = 0;
    
    while(!s.empty()){
        int node = s.top();
        s.pop();
        
        //we have got the minimunm dist till node now check dist already in adj is >/< !
        for(auto adj:graph[node]){
            int u = adj.first;
            int v = adj.second;
            // case1-our path of node is shorter to adj
            if(dist[node]+v < dist[u]){
                dist[u] = dist[node] + v;
            }
            // otherwise we earlier found a shorter path to adj from source 
        }
    }
    /// not rechable nodes , dist = -1
    for(int i =  0; i<V; i++){
        if(dist[i]==INT_MAX) dist[i]= -1;
    }
    return dist;
    }
};
