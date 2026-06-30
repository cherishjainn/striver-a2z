int sum(TreeNode* root , int &maxi ){
        if(root == NULL ) return 0;
        int leftsum = sum(root->left,maxi);
        int rightsum  = sum(root->right,maxi);
        maxi  = max(maxi,root->val + leftsum + rightsum);
        if(root->val + max(leftsum,rightsum)<0) return 0;
        return root->val + max(leftsum,rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum(root,maxi);
        return maxi;