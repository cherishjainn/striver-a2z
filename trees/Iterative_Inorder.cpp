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

        curr = curr->right; /* abb right ka apna kudh ka subtree ayega vo kudh se handle ho jayega */
    }

    return ans;
}


LOGIC====>>
    Jab tak left mil raha hai, left jaate raho aur parent ko stack me save karte raho.
   --> paheli bar  Current = NULL
Ab left khatam ho gaya. 
next step=>Ab stack se nikalo:
Pop 4
ans = [4]  
    let 4 be last root before left is null,

Ab inorder ke hisaab se:
Left ho gaya
ab Root print karo
ab Right jao

    
MISTAKE ==>>>>
    ** abhi bhi while ya if ki condition curr->left ya curr->right par mat lagao.
For example, agar tum while(curr->left != NULL) use karte ho, to jab hum left subtree se wapas upar aayenge, tab loop fir se galat tarike se execute ho sakta hai.
Isliye standard solution mein hum node ke left/right par nahi, balki poore current pointer par check lagate hain:
while(curr != NULL){
    st.push(curr);
    curr = curr->left;
}

 SOL ==> isliye hum purre time curr node ko leke chalenge jo direct hume batayega ki humari current node ki situation ky hai
         agar curr , null  hoga tho usse null bhi kregenge usse muzhe malum pad jayegi ki MUZHE RIGHT JANA HAI AUR FIR ME LEFT ME MOVE KRNE KE LIYE WHILE LOOP NHI LAGUNGA 
         aur bina loop lageya direct curr ko stack ke next top elemne tke equal krke uska right nikalunga ... 


           
