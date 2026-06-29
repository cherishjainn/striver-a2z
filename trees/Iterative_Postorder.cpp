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

LOGIC =>
        ** Postorder mushkil hai, to pehle Root Right Left banao aur usko ulta kar do.
        aur hum reversed version stack 2 me store krenge  aur fir loop chaleke answer me push krdenge..
        
      ** Jab bhi koi node Stack1 se nikalti hai, hum use turant Stack2 me daal dete hain.
Ab hume chahiye ki Stack2 me Root ke baad Right subtree aaye aur uske baad Left subtree aaye. Isliye Stack1 me hum Left ko pehle aur Right ko baad me push karte hain.

Kyunki Stack1 LIFO (Last In First Out) hota hai, isliye Right child pehle process hota hai, aur Stack2 me order ban jata hai:
Root → Right → Left

Ab jab hum Stack2 ko pop karte hain, to ye order reverse hokar milta hai:
Left → Right → Root

jo ki exactly Postorder Traversal hai

tip - //// ek example leke dekh le to confirm ki root right left ka reverse postorder dega!!
