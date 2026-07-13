safe nodes are nodes which evettually reaches terminal node through all outgoings from them directly or through a path 

concpt -->> all nodes will eventually end at point and reach  terminal !! 
but those involved in cycle or through any adjacent directed node reaches a cycle will not be safe !!!

BY DFS -> USE CYCLE DTETECTION ALGO 

// check if cycle
    // if any node is a part of cycle or reach a cycle from any direction
    // ->never reach terminal  , 
    ///for strt after all adj checked if no cycle found  add to  ans , return true -> no use but to end dfs if cycle found in any of adj
    // return false and dont add to ans

    bool dfs(int start, vector<int>& visit, vector<int>& pathvisit,
             vector<vector<int>>& graph, vector<int>& check, vector<int>& ans) {
        visit[start] = 1;
        pathvisit[start] = 1;
        // in this ques true -> no cycle (what i wanted)
        for (auto adj : graph[start]) {

            // not visited check if cycle if connected to this

            if (!visit[adj]) {
                // if any adj false, return false as start cant reach terminal
                if (!dfs(adj, visit, pathvisit, graph, check, ans)) {
                    check[start] = 0;
                    return false;
                }
            }

            // if already in path , cycle found , return false -> cant reCH
            // TERMINAL  ,end!
            else if (pathvisit[adj]) {
                check[start] = 0;
                return false;
            }

//"### important insight -->> in pathvisit those involved in path are =1 along with that those who reaches/part of any cycle are also =1 
//becuase if cycle found we return false imediately without chnging back pathvisit to 0 so it remains 1"

        }

        // no cycle for any adj to start
        check[start] = 1;
        ans.push_back(start);
        pathvisit[start] = 0;
        return true; // dfs successful -> no cycle
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int v = graph.size();
        vector<int> visit(v);
        vector<int> pathvisit(v);
        vector<int> check(v); // to keep a track of safe nodes
        for (int i = 0; i < v; i++) {
            if (!visit[i]) {
                dfs(i, visit, pathvisit, graph, check, ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans  ;
}


"### important insight -->> in pathvisit those involved in path are =1 along with that those who reaches/part of any cycle are also =1 
becuase if cycle found we return false imediately without chnging back pathvisit to 0 so it remains 1"
