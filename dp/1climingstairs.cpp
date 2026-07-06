You can climb 1 or 2 stairs at a time list all possivbe ways to reach nth stair 


RECURSION APPROACH :-
first consider that climbstairs will give total ways to reach nth index from 0 th index 
now since we can move 1 step or 2 step at a time , start from top(we can do from both side top o rbottom doent matter for total ways) 
we will move 1st 1 step and then in second possible case 2 steps then found all ways from 0 to that n-1 and n-2 th index and add them  !!
subsequnetly recursion will do again same 2 cases for n-1 and n-1 index and this contiue....

        
int climbStairs(int n) {
        if(n==0) return 1 ;
        if(n==1) return 1 ;
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
         return left + right ;
    }

However, this solution has exponential time complexity (O(2^n))

  ****** NOTE :- SEE PROPERLY THIS QUESTION / RECUSRION FOLLOWS FIBONACCI APPROACH ****
        

MEMOIZATION APPROACH :-
VERY IMPORTANT **We use an vector array to store the already computed results for each step n. 
Before making a recursive call, we check if the result for the given n exists in the vector. 
If it does, we return the stored value; otherwise, we compute the result recursively and store it  for future reference.
        
int help(int n , vector<int> &dp){
        if(dp[n]!=-1) return dp[n];
        int left = help(n-1,dp);
        int right = help(n-2,dp);
        return dp[n] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1 , dp[1] = 1;
        return help(n,dp);
    }
TC -O(N)
SC -O(N) + O(N)

        

TABLATION APPROACH :-
It  uses a $$ bottom-up $$ approach to solve the problem iteratively. 
It creates a DP table (dp) of size n+1 to store the number of ways to reach each step.
The base cases (0 and 1 steps) are initialized to 1 since there is only one way to reach them. 
Then, it iterates from 2 to n, filling in the DP table by summing up the values for the previous two steps. 
Finally, it returns the value in the last cell of the DP table, which represents the total number of ways to reach the top.

int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] =1;
        dp[1] =1;
        for(int i =2 ; i<n+1 ; i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }
        return dp[n];
    }

TC-O(N)
SC-O(N) // ONLY dp vector occupied space no recursive stack space //



SPACE OPTIMIZATION :-
since the pattern for this question folows fibonacci approeach
we can use variabel prev1 and prev2 to store n-1 and n-2 valaues
which we will update by iterating over the loop and eventually move curr to nth stair 

 int climbStairs(int n) {
     int prev1 = 1 ;
     int prev2 = 1;
     int curr = 1;
     for(int i = 2; i<n+1 ; i++){
        curr = prev1 + prev2 ;
        prev1 = prev2;
        prev2 = curr;
     }
     return curr;
    }

TC - O(N);
sc - O(1) ; 
        

A SLIGTH VARIATION  ---->>>>> https://www.geeksforgeeks.org/problems/geek-jump/1
more variation *** --->>>https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4  (read th eosl written by me in tuf editor )

SIMILAR PROBLEM -- https://leetcode.com/problems/house-robber/ 
        just instead of frog jump in above question they have said money robbed when we are at n we can rob till n-2 then rob n or rob n-1 , return max of them 


