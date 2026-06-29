  int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        return 1+max(leftheight,rightheight);
    }

** jab recusrion likh rha h tho soch mera function muzhe vo required chij de dega ye man ke aage bad aur bas base condtiton likh de 
