"https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1"

LOGIC ==>>
we cannot use method of undirected graph becuase in that we only use the concept that if a node is previously visited and not the parnent node it means we've completed the cycle
or If during this process, we reach a node that we’ve already visited in the same DFS path, it means we’ve gone back to an ancestor -cycle!

When we start DFS from one node, some nodes get marked as visited. 
Later, when we start DFS from another node, those visited nodes may appear again (as they were part of different branches) , even if there’s no cycle.
So, using only visited[] isn’t enough.

SO IN DIRECTED WE REUIRED TWO VECTORS - VSIT ( TO KEEP TRACK OF VISITED ELEMENT)
                                        PATHVISIT (TO KEEP TRACK OF ELEMENT IN MY EXISITNG PATH )
                                        And if i find a elemnt that is visited and is also in my path then i ve got the cycle !!


NOTE :- Directed graph me cycle tabhi hota hai jab current path me kisi purane node par wapas aa jao (a back edge).
 Agar node sirf visited hai lekin current path me nahi hai, to woh kisi dusri branch se visit hua tha    !!
 
  
  bool dfs(int start ,vector<vector<int>> &adjlist , vector<int> &visit , vector<int> &pathv){
      visit[start] = 1;
      pathv[start] = 1;
      for(auto adj:adjlist[start]){
          // if already visited then there must be no path becuase the preivous path from which we are comin does not matter for a cycle if there is cycle inclding this adj node then from which branch oyu come you will complete the circle fromm this point onwards 
          if(!visit[adj]){
              if(dfs(adj,adjlist,visit,pathv)) return true ;
              pathv[adj] = 0 ; //when you  backtrack  you have to remove this adj node  from path as now you are changing you path to other adj node 
          }
          
          // ghum fir ke agr current path ke elemnt ke pass paunch gya means cycle formed 
          if(pathv[adj]==1){
              return true;
          }
          
      }
      
      return false;
  }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
       // first we have to convert edges to adjaceny list 
       vector<vector<int>> adjlist(V) ;
       for(auto edge : edges ){
           int u = edge[0];
           int v = edge[1];
           adjlist[u].push_back(v);
       }
       
       vector<int> visit(V);
       vector<int> pathv(V);// this will take care of all those element which are in our current path 
       // when we backtrack and diddnt recieve a true we have to remove the the adjacent node as now we are gonna move towards another adj node 
        for(int i = 0; i< V ; i++){
            if(!visit[i]){
                if(dfs(i,adjlist,visit,pathv)) return true ;
                pathv[i]=0;
            }
        }
        return false ;
    }
};