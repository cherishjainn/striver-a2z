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

LOGIC ==>
- 1. Root ko stack me daalo.
2. Stack se top most node nikalo. =>sabse top most ko nikalenge kyoki vo left vala node h (jo ki aghe ki subtree ke liye head h)
3. Usko answer me daalo.
4. Pehle right push karo, phir left push karo => kyoki hame ( root left right ) chaiye sabse pahele head push krenge fir uske bas usko pop krte hue  
                                                right - left push krenge aur sath me head ko ans vector me store bhi krte jayenge aur jaise abhi 
                                                right-left store hue h jab next bar me top nikalenge tho vo left vala ayega top pe hoga tho usko store krlenge kyoki vo  head of next subtree hai  !!!!

        
