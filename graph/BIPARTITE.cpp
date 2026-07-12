"https://leetcode.com/problems/is-graph-bipartite/"

lets take two colors 0 amd 1 
"Bipartite graph wo graph hai jisme har node ke saare neighbours (connected nodes) usse different color ke hote hain. "
OR
Har edge hamesha different color ke 2 nodes ko connect kare.
 Agar kisi edge ke dono ends par same color aa gaya, to graph bipartite nahi hai. ✅

IN THIS QUESTION 2 SETs ARE THERE AND EVERY EDGE SHOULD HAVE ONE LEMENT FORM EACH SET ON BOTH SIDE
 LETS SEE THESE TWO SETS AS TWO COLOURS AND ELEMENTS IN sets AS ELEMNTS WHICH haVE THESE COLOURS 

LOGIC => "Har connected node ka color different hona chahiye parent node se
  isliye bfs/dfs lagate vkt adjacent nodes ko opposite color dedo . "

  // important 

$$$ "Agr child node already coloured" ha
 aur Same color ha uska  = Not Bipartite/return false  , 
 aur opposite ha tho dont do anything its been already covered somewhere in traversal 

 IMPORTANT INSIGHT:::

 you can also it like whenever there is no cycle in grpah we can easuly assign opposite color one after another 

 but if there is a cylcle 

** cycle is even -- NO PROBLEM  , you will end up havinf diff color in start and end 
 ex.     0 
      /    \
     /      \     // o and 1 are lets say red and blue color 
     1       1
     \      /
      \    /
        0

** cycle is odd - in this case you will end up in same adjacent color in one of the edge 
 ex.   0
     / \
    /   \
   0-----1    

 SO YOU CAN ALSO DO THIS BY FINDING LENGTH 
 
 
"you can aloso do it using dfs just traversal and assinging color is there "


  bool bfs(int startingNode , vector<vector<int>>& graph , vector<int> &color){
        queue<int> q;
        q.push(startingNode);
        color[startingNode] = 0; //lets suppose started with color2
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adj : graph[node]){
                // if uncoloured color with opposite color 
                if(color[adj]==-1){
                    q.push(adj);
                    color[adj] = !color[node]; //opposite
                }
                // if already coloured with same color then not bipartite 
                else if(color[adj] == color[node]){
                    return false ;
                }
                //if already colored with opposite color  then no tension it has been already passed earlier in queue 
            }
        }
        //not founded a wrong case means bipartite 
        return true ;
   }

    bool isBipartite(vector<vector<int>>& graph) {
        // 1- color1  , 0-color2 , -1 - uncolored 
        int nodes = graph.size();
        vector<int> color(nodes,-1); //dont do int color[nodes] =  {-1}

        // there can be connected component for that you have to chekc every node if a node is not colored means its a part of a different graph 

        for(int i =  0 ; i<nodes ; i++){
            if(color[i]==-1){ 
                if(!bfs(i,graph,color)) return false ; // if any graph gives false return overall false as rule breaked

            }
        }
        return true;
    }

    "COMPLEXITIES SAME AS BFS"

