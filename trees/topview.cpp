###VERTICAL TRAVERSAL KAR LE PAHELE 
 test case
               1
            /     \
           2       3
          / \     / \
         4   5   6   7
              \
               8
                \
                 9

HD:
4 -> -2
2 -> -1     //-2,-1,0,1,2 are different vertical lines representing total elements views from top or represtin columns
1 -> 0
3 -> +1
7 -> +2
Top View:
4 2 1 3 7
8 aur 9 ignore honge.

NOTE :- i was trying to do it using leftside trevaersal and right traversal for top view but a very imp edge case missed 
    edge case //very important 
                1
              /   \
             2     3
              \
               4
                \
                 5
                  \
                   6
    ****top view is 2136 not 213 
    isliye mera method galat h thereofre do this


LOGICX ===>>>>
"level order lgao use kr better rhega just like vertical traversal ""

"Queue me (node, horizontal distance //**start from 0 and do -1 for left +1 for right**//  ) store krna "

"NOW USE MAP jisse distance negative se postive me jaye sorted order me and distance ke sath value bhi store krle fir badme map ko iterate krlena "

"horizontal distance use karo,
aur har horizontal distance par pehli baar aane wale node ko hi top view me include karo."


******NOTE:- level order / bfs use krenge bcs jo paritcular distance pe element pahele ayega ussse hi lenge top view se vo hi dikhe ga auur level order me upper se hi chalu hota ha



void inorder(Node* root,vector<int> &ans ){
    
    queue<pair<Node*,int>> qu; //here int is for coordinate like -2,-1,0,1,2 etc ...
    qu.push({root,0});
    map<int,int> mpp;
    
    while(!qu.empty()){
        auto p = qu.front(); //bottomost node 
        Node* node = p.first;
        int coordinate = p.second;
        qu.pop();
        if(mpp.find(coordinate)==mpp.end()) mpp[coordinate] = node->data;  //VERY IMP //agar uss coordinate me element pahele aa chuka tho naya nhi lenge becasue top view me upper jo ayega vo hi lena ha  
        if(node->left) qu.push({node->left,coordinate-1});
        if(node->right) qu.push({node->right,coordinate+1});
    }
    for(const auto& it:mpp){
        ans.push_back(it.second);
    }
    
}
class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans ;
        inorder(root,ans);
        return ans;
        
    }
};
