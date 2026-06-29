  int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        return 1+max(leftheight,rightheight);
    }