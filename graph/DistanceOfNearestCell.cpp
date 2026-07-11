https://leetcode.com/problems/01-matrix/solutions/3920110/9487-multi-source-bfs-queue-by-vanamsen-gd1q/

CONCEPT ==>>
WE WILL USE BFS becuase for all 0 cells , adjacent 1 cells are 1 distance ahead then their adjacent 1 cell are 2 distance ahead  this goes like levels 

THIS IS MULTI-SOURCE QUES IN WHICH OUR SOUUCES ARE 0 CELLS WE HAVE TO START FROM THEM AND SEE HOW MUCH WE HAVE   TO TRAVEL TO REACH 1 CELLS
WE ARE SEEING THIS QUESTION IN REVERSE WAY INSTED OF SEEING HOW MUCH WE HAVE TO TRAVEL FORM 1 TO 0
 WE WILL START FROM ALL 0'S AND IF THERE ARE ADJACENT 1 PRESENT ,  AS PER THEIR LEVEL IN QUEUE ,MARK THEIR DISTANCE IN DISTCANE MATRIX WE HAVE CREATED 
note::: 
remebrr bfs is useful for its levels proprty 
in queue we push sources intially , here sourcess are which whose answer we already know or whose info we have for ex if you consider all 1 as souces and start mutli source bfs from them 
then this makes no sense beacuse lets say you got a 0 but since this 0 has different distance for every 1 you cant decide 

** create two matrices for visit and distance in visit you will mark cells which are visited(already reached earlier in distance < currdistance/level )
and in distance marix keep track of distance for which we count levels at that instant 

INTUITON :::::: $$ THINK LIKE WE ARE SPREADING FROM ALL 0 CELLS AT SAME INSTANT IN ALL 4 DIRECTION THEN AGAIN N FURTHER 4 DIRECTION FROM THOSE INTIALL 4 DIRECTION AND SO ON....
 
   vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
       //dist and visit matrix 
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> visit = dist;
         //queue creation 
        queue<pair<int, int>> q;
        //moving in 4 directions 
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        //putting all sources/0 cells in queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    visit[i][j] = 1;
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        //intially level as distance 
        int distance = 0;
        //bfs
        while (!q.empty()) {
            distance++; // moved to one distance ahead each time clearing one level
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int column = q.front().second;
                q.pop();
                for (auto [dx, dy] : dir) {
                    int nrow = row + dx;
                    int ncol = column + dy;
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        !visit[nrow][ncol]) {
                        dist[nrow][ncol] = distance;
                        q.push({nrow, ncol});
                        visit[nrow][ncol] = 1;
                    }
                }
            }
        }
        return dist;
    }
