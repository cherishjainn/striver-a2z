vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL || !st.empty()) {

        while(curr != NULL) {
            st.push(curr);     /*TAKE ALL LEFT FIRST AS WE HAVE TO MOVE TO THE LEFT OF LEFT OF....*/
            curr = curr->left;  
        }
                              /*all left is taken and we have arrived to last left now pushback root just above last left */
                             /* last left here is NULL */
        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
    }

    return ans;
}


LOGIC====>>
    Jab tak left mil raha hai, left jaate raho aur parent ko stack me save karte raho.
   --> paheli bar  Current = NULL
Ab left khatam ho gaya. 
next step=>Ab stack se nikalo:
Pop 4
ans = [4]  /*let 4 be last root before left is null,

Ab inorder ke hisaab se:
Left ho gaya
ab Root print karo
ab Right jao

    
MISTAKE ==>>>>
    ** first do not take condition in while loop or if else on basis of CURR->LEFT OR CURR->RIGHT  
       for ex.. if you take while(curr->left!=NULL) when we move upward after taking left , loop will again start ..
        Isliye standard solution me hum:
       while(curr != NULL){  st.push(curr); curr = curr->left;  }
       karte hain, taaki poora left ek hi baar traverse h !!!!!

 SOL ==> isliye hum purre time curr node ko leke chalenge jo direct hume batayega ki humari current node ki situation ky hai
         agar curr null ko hoga tho usse null bhi kregenge usse muzhe malum pad jayegi ki MUZHE RIGHT JANA HAI AUR FIR ME LEFT ME MOVE KRNE KE LIYE WHILE LOOP NHI LAGUNGA 
         aur bina loop lageya direct curr ko stack ke next top elemne tke equal krke uska right nikalunga ... 


           
