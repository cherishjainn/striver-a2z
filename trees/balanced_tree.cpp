##BRUTE APPROACH ----->>> TC ~ O(N^2) {IN WORST CASE WE WILL BE CHEKCING EVERY NODE FOR BOOL AND
                                      CALCULATING HEIGHT AT EVERY NODE [SWEQ TREE]


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


## optimal approach

$$ LOGIC ====>>> 
Brute me hum har node ke liye height nikal kar true/false return kr rhe h aur agr 
false return hua tho further bool laga rhe the age ke node ke liye ..
        
** yaha directly height nikalte vkt hi agr tu bakctrack soche Ga tho last
se start krtue hue kahi bhi condition fulfill nhi hui tho -1 RETURN KR RHE 
THE aur ek abr -1 return hone ke bad we have kept a cond. in line 50.. jisse continuoulsy -1 hi return hota rhega !!
      
TC - O(N)      

int height(TreeNode* root){
        
    if(root == NULL) return 0;
        
    int le = height(root->left);
    int ri =height(root->right);
        
    if(abs(le-ri)>1) return -1;
        
    if(le == -1 || ri == -1) return -1;
        
    return 1+max(le,ri);
   }


    bool isBalanced(TreeNode* root) {
        int ans = height(root);
        if(ans ==-1) return false;
        return true ;
    }
