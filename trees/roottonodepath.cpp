PATH FROM ROOT TO ANY NODE 
whenever doing recursion think that you aim is current node means consider you ot what  you want from further now adjust code like what you have to return to above means when you call function again in function for recursio assume you got a  prefect desired asnwer from function now write code such that what you want to do with current elemnt or what you want above function should receive from you
note====>>>

    
VERY IMPORTANT : since there is only one path of root to node you did not need to move in left then pop then move in right then pop
you can use true false concept and if you revceived true means you find path
 if you get false then it means at evry step from end to that point you must have got false 
so we have written a line of pop back and return false after doing if condition did not work !!!! 

$$$$$ tip : true false me pop back krne vale chij end me hi likhna 
pahele recusrion krlena kyoki think in end of rrecusrion in last call  if we got true then everthing fine we will subsequently return true  but if we recieve false in last  from leaf node  menas true thing does not work 


bool getPath(TreeNode* root, int x, vector<int>& path) {
    if (root == NULL) return false;

    // Add current node to path
    path.push_back(root->val);

    // If current node is the required node
    if (root->val == x)
        return true;

    // Search in left or right subtree
    if (getPath(root->left, x, path) || getPath(root->right, x, path))
        return true;

   
    // Backtrack: remove current node
    path.pop_back();

    return false;
}

vector<int> rootToNodePath(TreeNode* root, int x) {
    vector<int> path;
    getPath(root, x, path);
    return path;
}
