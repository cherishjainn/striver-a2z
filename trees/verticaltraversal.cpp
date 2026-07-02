 vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int , int>>> qu;
        map<int,map<int , multiset<int>>>mpp;
        qu.push({root,{0,0}});
        while(!qu.empty()){
            auto curr  = qu.front();
            qu.pop();
            TreeNode* node = curr.first;
            int vertical = curr.second.first , level = curr.second.second;
            mpp[vertical][level].insert(node->val);
            if(node->left) qu.push({node->left,pair{vertical-1,level+1}});
            if(node->right) qu.push({node->right,pair{vertical+1,level+1}});
        }
        vector<vector<int>> ans;
        for(const auto& it:mpp){
            vector<int> temp;
            for(const auto& st:it.second){
                temp.insert(temp.end(),st.second.begin(),st.second.end());
            }
            ans.push_back(temp);
        }
        return ans ;
    }
