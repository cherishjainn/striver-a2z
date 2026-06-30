$$ Path sum -> Pure tree ke kissi bhi do node ke bich ki values ka sum including them 


TEST CASES :

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

Input :  100                             
       /   \
    -50    -60

Expected:100  


Input :      10
            /  \
           2    10
          / \     \
         20  1    -25
                  /  \
                 3    4

Expected:42
Path:20 → 2 → 10 → 10        

        
(**note==> jaruri nhi ki leaf to leaf ka distance le kisi bhi do nodes ko pick kr rkte h)         

LOGIC===>>>
      **simple si baat hai tuzhe path ka sum nikalna hai jo ki max ho tho always take a node aur 
uske leftisde ka max sum nikal aur right side ka max sum nikla aur node ko add krde considering it as a curve point of path

VERY IMP : agr tuzhe left side ya right me kisi ka bhi sum negative mile tho 0 return kr dena unki trf se kyoki logically hum left/right me se kisi bhi node ko lenge hi nhi 


int sum(TreeNode* root , int &maxi ){
        if(root == NULL ) return 0;
        
        int leftsum = sum(root->left,maxi); // ye sum function hume max sum dega kisi bhi side ka ye consider krke solve kara kr 
        int rightsum  = sum(root->right,maxi);
        
        maxi  = max(maxi,root->val + leftsum + rightsum);
        if(root->val + max(leftsum,rightsum)<0) return 0; // isko backtrack krke soch ki agr child tak maxsum negative
                                                        mila tho parent ko 0 return krna bahetar hai!!
       
        return root->val + max(leftsum,rightsum);  //aise soch apn ko solve krne ke liye both
                                                        left aur rigth ka individual maxsum chiaye tho vo nikalte vkt me 
                                                        jis bhi node pe pahuchunga vaha tk ka maximum path sum nikal lunga usko node ko curve point  man kr 
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        sum(root,maxi);
        return maxi;
