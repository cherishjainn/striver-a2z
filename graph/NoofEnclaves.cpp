"https://leetcode.com/problems/number-of-enclaves/solutions/3388645/python3cjava-easy-and-understand-dfsbeat-xq1l/"

VERY IMPORTANT LOGIC --->>> 
Jab bhi question bole "Can a node reach the boundary/exit?", THO  ye socho ki  "boundary se start karke connected nodes / reachable nodes mark kar tha hun!!!!"
jasie iss question vo graph jo boundary ko touch kr rhe hen vo nhi chiaye tho total nikal ke minuus kr de !!

WRONG THINKING:
Har unvisited land cell se DFS start karunga, us island ka size count karunga aur check karunga ki ye boundary touch karta hai ya nahi.
Lekin problem ye hai ki DFS ke beech me mujhe nahi pata hota ki island boundary touch karega ya nahi.
DFS khatam hone ke baad:
Agar island boundary touch karta hai → ignore kar do.
Agar boundary touch nahi karta → uska size answer me add kar do.

"BETTER THINKING :"
instead of asking:
"Kya ye island boundary tak pahunch sakta hai?"
Ask:
"Boundary se start krke kaha - kaha aur kaun-kaun se land cells tak pahunch sakte hain?" 

NOTE = THIS SIMILAR LOGIC IS USED IN SURROUNDED BY 'X' QUESTION IN THAT RATHER THAN STARTING FROM 'O' AND CHEKING IF IT REACHES TO BOUNDARY/WE GOT A 'O' AT BOUNDARY WE'LL START FROM BOUNDARY AND CHECK KI ME KAUN KAUN SE 'O' CELL TK PAUCH PATA HUN!!!!
QUES LINK - "https://leetcode.com/problems/surrounded-regions/solutions/1552435/easy-explained-solution-with-images-by-y-n6r6/"



** IN THIS INSTED OF USING VISIT MATRIX YOU CAN CHANGE VISITED CELLS  TO 0 SO IT WILL NOT BE VISTED AGAIN AS ONLY CELL OF VLAUE 1 IS REQUIRED 



int dfs(int row, int column, vector<vector<int>>& grid,
            vector<vector<int>>& visit) {
        int count = 1;
        visit[row][column] = 1;
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (auto [dx, dy] : dir) {
            int nrow = row + dx;
            int ncol = column + dy;
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 &&
                ncol < grid[0].size() && !visit[nrow][ncol] &&
                grid[nrow][ncol] == 1) {
                count += dfs(nrow, ncol, grid , visit);
            }
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int landcells = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i<row ; i++){
            for(int j = 0; j<col ; j++){
                if(grid[i][j]==1) landcells++; //COUNTED TOTAL 1'S NOW I WILL MINUS THOSE CONNECTED TO BOUNDARY 
            }
        }
        vector<vector<int>> visit(row, vector<int>(col, 0));

// WE ARE CHEKCING 4 BOUNDARIES 

        for (int i = 0; i < row; i++) {
             if (!visit[i][0] && grid[i][0]==1) {
                landcells -= dfs(i,0,grid,visit);
            }
        }
        for (int i = 0; i < row; i++) {
             if (!visit[i][col-1] && grid[i][col-1]==1) {
                landcells -= dfs(i,col-1,grid,visit);
            }
        }
        for (int i = 0; i < col; i++) {
             if (!visit[0][i] && grid[0][i]==1) {
                landcells -= dfs(0,i,grid,visit);
            }
        }
        for (int i = 0; i < col; i++) {
             if (!visit[row-1][i] && grid[row-1][i]==1) {
                landcells -= dfs(row-1,i,grid,visit);
            }
        }
        return landcells;
    }
