https://leetcode.com/problems/rotting-oranges/solutions/3166554/c-bfs-easiest-beginner-friendly-sol-on2-54gzi/

SIMILAR TO QUES 2

💡 Remember: Normal BFS starts from one source, but Rotting Oranges uses Multi-Source BFS because multiple rotten oranges spread simultaneous

NOTE :- 
WE HAVE TO USE $ BFS $ AS ADJACENT  fresh oranges ARE ROTTEN SIMULTANEOLSY THEN THEIR ADJACENT and ..... JUST LIKE LEVEL TRAVERSAL!!!! 

few things different and IMPORTANT TO REMEBER ==>>>

** rotten oranges multiple ho skte h intiall grid me 
 aur kyoki  sab ek sath me adjacent orange ko rotten krenge 
 therfore queue me sare rotten oranges jo intially h sabke {row,col} ko dal denge  
jisse sare rotten ke  adjacent ek sath me next level me dal paye !!!!

Use a for loop of queue.size() to process one BFS level at a time;
 after each level, increment minutes since all oranges in that level rot simultaneously.

** ISME 2 IMPORTANT EDGE CASES -> 0 AND -1 KA 

0 - WHEN NO FRESH ORANGES PRESENT
 for that hum intially queue me rotten wale ko dalte vkt hi fresh ka count rkh lenge and if countOffresh ==  0 after ending loop  return 0

-1 -If some fresh oranges can never be reached, they will never become rotten.
 for that jab queue wale loop me, size wale me if(n&& ..==1) wali condition satisfy hogi tho countOffresh-- kr denge 
aur end me  agr ye count != 0 hua means return -1       
