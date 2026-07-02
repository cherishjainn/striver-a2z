## https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
striver v: https://youtu.be/q_a6lpbKJdw (watch)


@Basically sawal me bas traversal kra h you can do it using preorder or posTorder ALSO (TRY)  
mainn use map,multiset,pair ka ha, in this ques we have to use
map<int,map<int,multiset<int>>> for storing rows and column of every node along with node->val


**queue me nodes,column,row sab store hoga  

**VERY IMP :- Sirf nodes aur colum/vertical hi store mt krna levels/rows 
bhi  store hoga bcs same level ke nodes ko sort krna h 
isliye map ke under int(vertical) ke sath <int,multiset> rkha har level(int) ke same variable wale nodes i.e, stored in multiset in sorted manner 


**queue se rows,columns ko store krne ke liye map<int,map<int,multiset<int>>>  lena padega 

reason - * agr node same level pe he aur same column/vertical hai tho sort 
them acc to ques isliye int-column/veritcla ke liye ,
map<int //level ke liye (row) // , multiset<int> same level pe jin nodes ki same row/vertical unko
store krne ke liye taki vo sorted rhe !!




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
        for(const auto& it:mpp){   //variable ki value kam ki nhi ha bas map variable ke according
                                   sorted hai enough //mpp[variable] i.e, it will give <level,nodes value of that particular level having column/vertical of that accessing vertical 
            vector<int> temp;

 // All the elements from diff levels having same vertical are pushed in temp vector 
//as already discussed we can directly pushed elemnts in temp without multiset but MULTISET IS USED TO TACKLE ELEMNTS FROM SAME LEVEL WITH SAME COLUMN
           

             for(const auto& st:it.second){    //accessing set

                temp.insert(temp.end(),st.second.begin(),st.second.end()); //docx likha h iss repo me read it for syntax 

            }

            ans.push_back(temp);
        }


        return ans ;
    }
