vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL ) return ans;
        stack<TreeNode*> st; 
        st.push(root);
        while(!st.empty()){
            TreeNode* it = st.top();
            st.pop();
            ans.push_back(it->val);
            if(it->right != NULL) st.push(it->right);
            if(it->left  != NULL) st.push(it->left);
        }   
        return ans ;                    
    }