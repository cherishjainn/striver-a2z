int dfsheight(TreeNode* root){
        if(root == NULL) return 0;
        int leftheight = dfsheight(root->left);
        int rightheight = dfsheight(root->right);
        return 1+max(leftheight,rightheight);
     }


    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true ;
        int Lh = dfsheight(root->left);
        int Rh = dfsheight(root->right);
        if(abs(Lh-Rh)>1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left||!right) return false;
        return true ;
    }