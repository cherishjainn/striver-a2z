void levelorder(TreeNode* root, vector<int> &ans){
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> qu;
    qu.push({root,0});
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int level = p.second;
        if(mpp.find(level)==mpp.end()) mpp[level] = node->val;
        if(node->right) qu.push({node->right,level+1});
        if(node->left) qu.push({node->left,level+1});
    }

    for(const auto& it:mpp){
        ans.push_back(it.second);
    }

   }



    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans ;
        if(root ==NULL) return ans;
        levelorder(root,ans);
        return ans;
    }


    void preorder(TreeNode* root , int level , vector<int> &ans){
        if(root == NULL) return ;
        if(level == ans.size()) ans.push_back(root->val);
        preorder(root->right,level+1,ans);
        preorder(root->left,level+1,ans); 
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root,0,ans);
        return ans ;
    }
};