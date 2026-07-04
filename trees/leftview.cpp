IN THIS QUESTION RIGHT IS FINDED SIMLARLY LEFT CAN BE FIND !!!!

https://leetcode.com/problems/binary-tree-right-side-view/description/ ##see diagram to understand##


****REVISE THE OPTIMAL APPROACH *****

    
My/1st Approach:

similarly jaise top view nikala vaise hi using line method level traversal krke har level ko 0,1,2,3,.. man le aur right vale element ko pahele indert kr means first prefernce fir left aur agr uss level me already element agaya ha tho naya element of same level nhi ayega because pahele pref rightmost ko di mtlb rightmost aa chuka h  fir left vala nhi ayega bcs right view ha left view me left ko preference pahele denge !!!!

    void levelorder(TreeNode* root, vector<int> &ans){
    
    map<int,int> mpp;  // 1st int for level // 2nd int for node value 
    
    queue<pair<TreeNode*,int>> qu;
    
    qu.push({root,0});
    
    while(!qu.empty()){
        auto p = qu.front();
        qu.pop();
        TreeNode* node = p.first;
        int level = p.second;
        
        if(mpp.find(level)==mpp.end()) mpp[level] = node->val;       //important

        //pahele right vale ko lenge 
        
        if(node->right) qu.push({node->right,level+1});
        if(node->left) qu.push({node->left,level+1});
        
    }

    for(const auto& it:mpp){
        ans.push_back(it.second);
    }

   }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans ;
        
        if(root ==NULL) return ans;
        levelorder(root,ans);
        return ans;
    }

NOTE :- in 1st approach TC is 0(NlogH) hai beacuse N nodes and logH map ki 
                         SC is map+queue



*** OPTIMAL APPROACH 
>>>>> Using Recursion 

TC -: TC - O(N)  , SC - O(H)
    
    void preorder(TreeNode* root , int level , vector<int> &ans){
        if(root == NULL) return ;
    
        if(level == ans.size()) ans.push_back(root->val);  ##Ye condition ka matlab:
                                                           ans.size() batata hai ki ab tak kitne levels cover hue hain.
                                                            Agar current level pe abhi tak koi node add nahi hui hai,
                                                            to jo node pehli baar mili hai usko add kar do.                                                    ///VERY IMPORTANT 
                                                ***** Hum right pahele ja rhe h jisse rightest pahele add ho jaye fir badme kisi dure node ka left ya right same level pe aya bhi tho vo add nhi hoga  kyoki ans ki size > level ho gayi rightmost ko add krne ke bad 
    
        preorder(root->right,level+1,ans);
        preorder(root->left,level+1,ans); 
    
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root,0,ans);
        return ans ;
    }
};
