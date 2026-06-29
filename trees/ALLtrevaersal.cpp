## LEVEL ORDER TRAVERSAL 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        /* rot == null check krne ka yad rkhna 

        if (root == NULL)   
            return ans;  /* {}*/

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }



## PREORDER TRAVERSAL
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

## INORDER TRAVERSAL
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
    
   ## POSTORDER TRAVERSAL 
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

