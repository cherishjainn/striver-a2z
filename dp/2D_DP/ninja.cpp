int f(vector<vector<int>> &points , int ind , int last){
    int maxi  = 0;  
    if(ind == 0 ){
        for(int i = 0 ; i<3 ; i++){
            if(i!=last){
                maxi = max(maxi,points[ind][i]);
            }
        }
        return maxi;
         maxi = 0;
        for(int i = 0; i<3 ; i++){
            if(i!=last){
                maxi = max(maxi,points[ind][i]  + f(points , ind-1,i));
            }
        }
        return maxi ;
    }
}
