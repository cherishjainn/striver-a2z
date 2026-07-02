void inorder(Node* root,vector<int> &ans ){
    queue<pair<Node*,int>> qu;
    qu.push({root,0});
    map<int,int> mpp;
    while(!qu.empty()){
        auto p = qu.front();
        Node* node = p.first;
        int coordinate = p.second;
        qu.pop();
        if(mpp.find(coordinate)==mpp.end()) mpp[coordinate] = node->data;   
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