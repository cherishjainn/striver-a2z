int climbStairs(int n/*index*/) {
        if(n==0) return ;
        if(n==1) return 1 ;
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
         return left + right ;
    }