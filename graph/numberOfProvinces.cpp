 
 
 
 https://leetcode.com/problems/number-of-provinces/  

 BASICALLY HUM DFS/TRAVERSAL KRKE EK SINGLE PATH YA SINGLE GRAPH KE SARE NODE KO VISITED MARK KR RHE H 
 JISSE KI HUM USS GRAPH PE EK  BAR KI DFS LAGEY KYOKI AGLI BAR VO VISITED MARKED H THO DFS NHI LAAGYENGE(WE KEPT CONDITON) 
 AUAR JITNI BAR DFS LGA MTLB UTNE GRAPH H ALG ALG
 BCS SINGLE DFS WILL COVER  ALL NODES OF THAT GRAPH 
 KEEP A COUNT OF THEM !!!!!!!
 
 
 void dfs(int node , vector<vector<int>> &list ,  vector<int> &visit ){
          visit[node] = 1 ;
          for(const auto& it : list[node]){                               TIME COMPLEXITY OF DFS  ===>>> O(V + 2E)
            if(!visit[it]){                                               YAHA V AUR E USS PARTICULAAR GRAPH KE DIFF GRAPHS KE LIYE IT WILL BE DIFF 
                dfs(it,list,visit);                                         
            }
          }
    }


    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        vector<int> visit(V+1,0);
        int count = 0;


        /// code for tranfering matrix of edges to list    VERY IMPORTANYT ******


          vector<vector<int>> list(V+1);
        for(int i = 0; i<V ; i++){
            for(int j = 0; j<V ; j++){
                if(isConnected[i][j] ==1 && i!=j){
                    list[i+1].push_back(j+1);
                }
            }
        }

        
        for(int i  =1  ; i<=V ; i++){                   NOTEEE ==>>>
                                                        TIME COMPLEXITY =>> O(N) + O(V+2E)  =~ O(N)
            if(!visit[i]){                               YAHA V TOTAL VERTICES JO KI QUES ME GIVEN H VO H TOTAL OF ALL GRAPHS                            
                dfs(i,list,visit);                       SIMILAR FOR E        
                count++;                                 

            }
        }
        return count ;
    }
