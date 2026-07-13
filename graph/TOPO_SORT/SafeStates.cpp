topo is also used to traverse from end nodes without including cycles (dag)

we will revrse the graph and then apply topo on graph !!

LOGIC -->
Initially the terminal nodes are those who have outdegree 0 
but after reversal the terminal nodes becomes those which have indegree 0 
so we can apply Kahns algo to find all the nodes connected to it  which have linear dependency on the terminal node or is on the path which leads to terminal node 
so if the nodes is a part of a cycle or points to a cycle , that path cannot lead to terminal node as each node in that  path will have cyclic dependency



vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        
        vector<int> safenodes;
         vector<int> indegree(V); 
         
        // reverse 
        vector<vector<int>> revlist(V);
        for(auto edge : edges){
            int u = edge[0];
            int v  = edge[1];
            revlist[v].push_back(u);
            indegree[u]++;
        }
        //for kahn we reuire 0 indegree so revrsed ,now terminal indegree  = 0
        queue<int> q;
        
       for(int i = 0 ; i<V ; i++){
           if(indegree[i]==0){
               q.push(i);
           }
       }
       while(!q.empty()){
           int  node = q.front();
           q.pop();
           safenodes.push_back(node); // as nodes in queue have indegree = 0
           //only those whose indegree has become 0 can be put in queue or added in topo
           for(auto adj:revlist[node]){
               indegree[adj]--;
               if(indegree[adj]==0){
                   q.push(adj);
               }
           }
       }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
        
    }