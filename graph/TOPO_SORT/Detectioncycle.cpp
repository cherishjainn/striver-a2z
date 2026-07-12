WE USE KAHN algorithum 

logic : 
 idea is to use "Kahn’s algorithm"
 because "it works only for Directed Acyclic Graphs (DAGs)."
  So," while performing topological sorting using Kahn’s algorithm, if we are able to include all the vertices
   in the topological order, it means the graph has no cycle and is a DAG."

However, if at the end there are still some vertices left
 (i.e., their in-degree never becomes 0) - which will happen for nodes in cycle
  as it you reach any random node in cycle and do -1/ -n , according to total connected nodes outerly , even then indegree will not be 0
   as there is a always a other node pointing toaawrds it in cycle .


    Hence, if we cannot get all the vertices in the topological sort, the graph must contain at least one cycle.








 bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
         vector<vector<int>> adj(V);
        
        vector<int> indegree(V);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            indegree[v]++;
            //sath me adj list bhi bana le 
            adj[u].push_back(v);
        }
        
        queue<int> q;
        for(int i = 0; i<V ; i++){
            if(indegree[i]==0){ //jisse koi directed nhi ha usko tension nhi hai u ki so put it 
                q.push(i);
            }
        }
      int count = 0;
        while(!q.empty()){
            int node = q.front();
            count++;
            //take the zero indegree node and push its directed/adj node and foor any oh them infdgree become zero then push them 
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
            }
        }
    }
    if(count==V ) return false  ;
    return true ;
        
    }
