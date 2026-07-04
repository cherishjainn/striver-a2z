 bool isleaf(TreeNode* root){
    return (root->left == NULL && root->right == NULL);
   }

   void help(TreeNode* root , string ds , vector<string> &ans ){
    
    ds += to_string(root->val);
       
    if(isleaf(root)){
        ans.push_back(ds);
        return ;
    }
    if(root->left){
        help(root->left,ds+"->",ans);
    }
    if(root->right){
        help(root->right,ds+"->",ans);
    }
   }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string ds;
        help(root,ds,ans);
        return ans ;
    }