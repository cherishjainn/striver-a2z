 https://leetcode.com/problems/number-of-islands/

few important things to remember fromt this question ==>>
** A way to move in all four directions by using dir vector and using loop over dir then adding first and second element of  ith vector of dir to row and col!!
**In grid question we have to use visit matrix , unlike in typical graph we use visit array , as in grid  , values are 0 & 1 so only differentiator of nodes is row,col number !!
**everytime you may not be given adjaceny list you may have to see yourself in question which nodes are adjavcent our current node !!!


LOGIC ===>>>

basically islands ek type se ek graph hi ha 
agr mene total no of graphs find kr liye then that will be total islands 

$$ remeber $$ 
graphs find krne ke liye ye dekh ki total serach space / grid / given matrix  me kitni bar bfs/dfs lagana pada!! 
beaucse lets suppose islands ke kisi bhi element se i have started bfs then during bfs all nodes belonging to that  groah/island will be marked visited then usss islands pe dobara bfs nhi lgega 

 
 
 
 void bfs(int row , int column , vector<vector<char>> &grid , vector<vector<int>> &visit){

           queue<pair<int,int>> q;
           q.push({row,column});                 
           int m = grid.size();
           int n = grid[0].size();
           visit[row][column] = 1 ;

           vector<pair<int,int>>  dir = {{1,0} , {0,1} , {-1,0} ,{0,-1}};

           while(!q.empty()){

                int currrow = q.front().first;
                int currcol = q.front().second;
                q.pop();

                for(const auto& [x,y] : dir){
                    int newrow = currrow  + x;
                    int newcol = currcol + y;
                    if(newrow>=0 && newrow < m && newcol >=0 && newcol < n && grid[newrow][newcol] == '1' && !visit[newrow][newcol]){
                        visit[newrow][newcol] = 1;
                        q.push({newrow,newcol});
                    }
                }
                }
           }



    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i = 0 ; i<m ; i++){
            for(int j =  0 ; j<n ; j++){
                if(grid[i][j]=='1' && !visit[i][j]){          $$ Rememebr to check if chossen cell is '1' bas ye hi mt dekhna ki it is not visited 
                    count++;
                    bfs(i,j,grid,visit);
                }
            }
        }
        return count ;
    }


NOTE ==>> A SLIHGHT IMPROVEMENT YOU CAN MAKE IS INSTEAD OF USING VISITED MATRIX YOU CAN CHANGE THE GRID[I][J] TO '0' 
 AT THAT INSTANT THEN WE WILL ONLY CONSIDER THOSE CELL WHICH ARE '1' 
 THIS WILL IMPROVE SC 
