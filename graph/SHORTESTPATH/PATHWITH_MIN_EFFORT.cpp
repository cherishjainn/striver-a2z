HOW TO RELATE =??
- there is a soruce and  a destination 
- there can be diff paths from src to dest
// MOST IMPORTANTLY ->
- we have to choose a path that minimize something (here EFFORT)

 SO THINK OF DIJSKTRA AND WHILE DRY RUN YOU WILL REALIZE THAT YES , WE RE RIGHT 

 BAISCALLY THINK LIKE DIJSKTRA SE TU DIFF PATH MESE KISI JI PARTICULAR CHIJ ME MINIMUM VALA PATH DHUND RHA HAI 
 IT CAN BE DISTANCE , EFFORT ... 

 approach -->> 
 Our approach we will be similar 
 jaise hum distance matrix bana kr uss node tk distance store krte the aur agr hume usse chota dist milta that tho update krte the and we push it in pr. qu. so that we can move in that path if overall in whole pq that dist is minimum 
 similary yaha uss point tak pahele effort nikal le 
 aur agr already existing effort(uss node ka)(can be inf_max) 
 se vo chote hai tho replace krde dist matrix me (here we call it effort matrix ) aur push krde pq me !!!!!!


  int minimumEffortPath(vector<vector<int>>& heights) {
        // {effort,{row,col}}
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        //matrix for effort like dis 
       int m = heights.size();//row
       int n = heights[0].size(); //col
       vector<vector<int>> effort(m,vector(n,INT_MAX)); //basically this will store max abs diff / effort till any particualr node like we store dis till a particualr node in dis matrix 

       //source node
       effort[0][0] = 0;
       pq.push({0,{0,0}});

       while(!pq.empty()){
        int effcurr = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
         pq.pop();
        //whenever you first pop out the dest it will the min effort as for all other effort will me equal or grater than first pooped 
        if(r==m-1 && c==n-1){
            return effcurr;
        }

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto [x,y] : dir){
            int nr = r+x;
            int nc = c+y;
            
            if(nr>=0 && nc>=0 && nr<m && nc<n){

                // now check that the effort from this path  for new node is less than previously filled effort 
                int effnew = max(abs(heights[nr][nc] - heights[r][c]) , effcurr);
                //this effnew is effort till this node from this
                if(effnew < effort[nr][nc]){
                    pq.push({effnew,{nr,nc}});
                    effort[nr][nc] = effnew;
                }
            }
        }
       }
       return 0;
    }

    TIME COMP-> same as dijsktra ElogV 
     -> n*m * log(n*m)

     space comp -> n*m (matrix) 
     where N * M is the distance matrix containing N * M cells, plus the priority queue in the worst case containing all the nodes (N * M)