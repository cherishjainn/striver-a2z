DIAMETER => Tree ke kisi bhi do nodes ke beech ka sabse lamba path (edges ke count me).

## brute approach 
** tc -> o(n^2)


LOGIC =>>
  **me hur node ka longest path nika rha hu considering it as curve points of path 
isliye longest path voga vo LEFT HRIGHT + RIGTH HEIGHT hoga simply 
  ** usko maxi me store krke age badenge aur dobara recusrive function lagagenge...

  
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int leftheight = maxDepth(root->left);
        int rightheight = maxDepth(root->right);
        return 1+max(leftheight,rightheight);
    }
    void diameter(TreeNode* root , int &maxi){
      if(root == NULL) return ;
     int lh = maxDepth(root->left);
     int rh = maxDepth(root->right);
     maxi = max(maxi,lh+rh);
    diameter(root->left,maxi);
    diameter(root->right,maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi  = 0;
     diameter(root,maxi);
     return maxi ;
    }


OPTIMAL ==>>
 TC => O(N)

  LOGIC==>>
  ** apn hur node ke liye uska left h + right h nikal rhe the aur fir next nodes ke liye check kr rhe the 
but HUM HEIGHT NIKLATE VKT HI maxi me left h + right h store kra skte h hume dobara us node pe jane ki jarurat nhi h
backtracking ke hisab se soch 
jab tu height ke last me pauchega tho maxi me store krna chalu kr and consequtic=vely move upwards of tree..!!!


    int maxDepth(TreeNode* root, int &maxi) {
  
        if(root == NULL) return 0;
  
        int leftheight = maxDepth(root->left , maxi);
        int rightheight = maxDepth(root->right , maxi);
  
        maxi = max(maxi,leftheight+rightheight);
  
        return 1+max(leftheight,rightheight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
    int maxi  = 0;
     maxDepth(root,maxi);
     return maxi ;
    }
