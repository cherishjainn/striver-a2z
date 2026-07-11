 
https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

CONCEPT ---->>>  If you visit a vertex that's already visited AND it's not your parent → cycle!

 **In an undirected graph, every edge is present in both directions. So, when we move from parent → node, we will always see the parent again in the node's adjacency list
 **Therefore, while exploring the neighbours of a node:
If the neighbour is not visited, continue the BFS.
If the neighbour is already visited and is not the parent,
then that neighbour has been reached through another path from the
 source (AS NODES WHICH COMES IN PATH STARTING FROM SOURCE  CAN ONLY BE  REACHED  ). This means there are two different paths to the same node, which forms a cycle.


 $$  **source node ke parent ko -1 bol dena beacuse vo starting point ya reference h hamara $$


bool bfs(int start  , vector<vector<int>> &adjlist , vector<int> &visit){
      queue<pair<int,int>> q;
      q.push({start,-1});   
      visit[start] = 1;
      while(!q.empty()){
          int node = q.front().first;
          int parent  = q.front().second;
          q.pop();
          for(auto adjacent : adjlist[node]){
              if(!visit[adjacent]){
                  visit[adjacent] = 1;
                  q.push({adjacent,node});
              }
              else if(adjacent!=parent){
                  return true ;
              }
          }
      }
      return false;
  }

  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adjlist(V);                   // **VERY IMPORTANT 
        for(auto vertex : edges){                         // ques me edges ki directed array de rkhi h tuzhe usko undiected me convert krna h beacuse desciption me likha hh    
            int u = vertex[0];
            int v = vertex[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int> visit(V,0);

        //CONNECTED COMPONENT CAN BE THERE THEREFORE CHECK NODES IF NOT VISITED MEANS SEPARATED FROM EXISTING GRAPH/PATH 

        for(int i = 0; i<V ; i++){
            if(!visit[i]){
                if(bfs(i,adjlist,visit)) return true;
            }
        }
        return false;
    }

TC - O(V)//CONNECTED COM. + O(V+2E)//BFS


 ## USING DFS 
 THIS CAN BE DONE USING DFS AS WELL
 THESE ARE JSUT METHOD OF TRAVERSAL 
 OUR LOGIC IS SAME IF ADJACENT NODE IS ALREADY VISTED AND IT IS NOT PARENT THEN
 HOW IT IS VISITED? --> BEACUSE IT IS ALREADY REACHED BY SOURCE NODE SOMEHOW AND  BECAME  A PART OF PATH ALREADY

 bool dfs(int node,int parent ,vector<vector<int>> &adjlist , vector<int> &visit){
      visit[node]  = 1;
      for(auto neighbour : adjlist[node]){
          if(!visit[neighbour]){
              visit[neighbour] = 1;
              if(dfs(neighbour,node,adjlist,visit)) return true ;
          }
          else if(neighbour!=parent){
              return true ;
          }
      }
      return false ;
  }
