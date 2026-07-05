You can climb 1 or 2 stairs at a time list all possivbe ways to reach nth stair 

int climbStairs(int n) {
        if(n==0) return 1 ;
        if(n==1) return 1 ;
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
         return left + right ;
    }
