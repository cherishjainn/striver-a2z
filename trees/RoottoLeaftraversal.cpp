ques- Traverse from root to leaf and give the output in form like [1->3->2->9->3] where these numb are values at nodes 
return all possible paths to diff leafs 

   ex    1
       / \
     12   3
         /
       45
 ["1->12", "1->3->45"]

 $$$$Socho$$$$:
"Current node ka value path me add karo aur baaki ka kaam children ko de do."
REcusion ko use krne ka logic simple h har bar do options h left ya right jane ka tlb 2 raste h to reach leaf so use recursion kyoki har bar 2 naye raste atte ja rhe h tree formation ho rha ha recursion ka in a sense 
 


VERY IMPORTANT EDGE CASES OR THINGS TO REMEMBER :-
 ** ds ko by refernce(using &) mat bhejna function call me vrna added characters(-> and node-'s value) ko
   remove krne me matta phodi hai  , balki usko by value / copy bejna because
   while calling function everytime you add "->newnode(left/right)->value" and this value can be 
   single digit or double digit so you dont know how muvh to remove during backtrack and 
   Therfore it is better to pass ds as (ds +"->") in which we will add the new node value in start


** QUES KE CORE IDEA KO SAMJ AUR FIR RECURSION KI LINES KO UPPER NICHE KAR jaise isme
pahele node->val ko add krenge uske bad check krenge new node leaf ha ya nhi 

** Negative number is imp test case and it is dificult to add 2,3 digit 
number to string ascii containe 1 to 9 therefore 
 use    ###   to_string(value)  ###   which will directly convert integer to string 





bool isleaf(TreeNode* root){
    return (root->left == NULL && root->right == NULL);
   }

   void help(TreeNode* root , string ds , vector<string> &ans ){
    
    ds += to_string(root->val);
       
    if(isleaf(root)){
        ans.push_back(ds);
        return ;
    }
    if(root->left){
        help(root->left,ds+"->",ans);
    }
    if(root->right){
        help(root->right,ds+"->",ans);
    }
   }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string ds;
        help(root,ds,ans);
        return ans ;
    }


