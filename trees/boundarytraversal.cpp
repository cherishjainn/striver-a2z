READ PROBLEM DESCIRPTION FIRST ==> https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

LOGIC ====>>>>>
  **Left boundary hum normal loop se nikal lenge
NOTE ==> Ek bat dyan rkha while loop me while(curr) hi       //VERY IMPORTANT // 
rkhna hamesha/mostly aur jo bhi conditions ho vo if else me rkh
lena vrna curr !=NULL ke faltu ke bahut sare case rkhne padenge ,  curr ko aaram 
se pure tree pe ghuma aur null pe rok de agr leaf tk hi lena h tho bhi pura 
hi move kr bas condition lga dena leaf pe rukne ki !!!!!

    **Leaf boundary ke liye tree ko pura traversal krna padega but hum
vo hi root/node lene h throughout jo ki leaf ho aur pahele left ayega fir right 
boundary me so use postorder/inorder and bas rather than push every root vo hi root lena jo leaf ho 


IMP EDGE CASES :
(a)
1
Output:
1
Issue:
Root duplicate ho jata hai.
Fix: // leftboundary ya left boundary me jane se phle ye condition lga di !! //
if(!isleaf(root))
    ans.push_back(root->data);

(b)
 Root has no left child
1
 \
  2
 /
3

Output:

1 3 2 
mene pahele root ko leftbound. me hi add kr rha tha aur leftbound. 
me condition thi agr left nahi hai tho right lelo uss vajahe se 2 pahele aa gya tha !!!!
Agr tu leftbounary me root ko lena chahega tho iss case me issue ayega bcs left
node nhi hai isliyye 2 add ho jayega pahele     !!!!

Fix : Root ko pahele hi add krlo                        //IMPORTANT//
      fir curr = root->left krdo agr intially left nhi hoga tho while(curr) se loop vahi khtm !!!

    
(c)
    1
   /
  2

Wrong:

1 2 2

Correct:

1 2
Fix:

Left/right boundary me leaf nodes add mat karo   !!

CODE :
    
    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;

        while (curr) {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (root == NULL)
            return;

        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
            res.push_back(temp[i]);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;

        if (root == NULL)
            return res;

        if (!isLeaf(root))            // JAB SINGLE NODE HO THO addleaves ME USKO LENGE KYOKI VO LEAF HAI // 
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
