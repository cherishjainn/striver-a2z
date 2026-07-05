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