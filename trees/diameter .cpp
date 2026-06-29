  int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        return 1+max(leftheight,rightheight);
    }
    void diameter(TreeNode* root , int &maxi){
      if(root == NULL) return ;
     int lh = maxDepth(root->left);
     int rh = maxDepth(root->right);
     maxi = max(maxi,lh+rh);
    diameter(root->left,maxi);
    diameter(root->right,maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi  = 0;
     diameter(root,maxi);
     return maxi ;
    }