SIMPLY USE BSE FORM FOR SHORTEST DISTANCE
 THE INSTANT YOU FIND LAST MOST ELEMENT THAT IS MISINUMM STEP NEEDED
 AS BFS IS LEVEL WISE TRAVERSAL !!!!

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> visit(n, vector<int>(n, 0));
        q.push({0, 0});
        visit[0][0] = 1;

        // 8 DIR ALLOWED IN QUES
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0},   {0, -1}, {0, 1},
                                      {1, 1},  {-1, -1}, {1, -1}, {-1, 1}};
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                if (r == n - 1 && c == n - 1)
                    return level;
                q.pop();
                for (auto [x, y] : dir) {
                    int nr = r + x;
                    int nc = c + y;
                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        grid[nr][nc] == 0 && !visit[nr][nc]) {
                        q.push({nr, nc});
                        visit[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};