 void pre(TreeNode* root,vector<int> &ans){
        if(root == NULL) return ;
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root,ans);
        return ans ;
    }


 void inorder(TreeNode* root,vector<int> &ans){
        if(root == NULL) return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans ;
    }
    
    
  void postorder(TreeNode* root,vector<int> &ans){
        if(root == NULL) return ;
        postorder(root->left,ans);
        postorder(root->right,ans);
    ans.push_back(root->val);
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans ;
    }  