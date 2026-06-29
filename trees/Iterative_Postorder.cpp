vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<int> ans;
        if(root==NULL) return ans ;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left!=NULL) st1.push(curr->left );
            if(curr->right!=NULL) st1.push(curr->right );
        }
        while(st2.size()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }