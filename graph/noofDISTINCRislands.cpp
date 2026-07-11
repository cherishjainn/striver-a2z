"https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1"

"similar to ques noofislands" bus you have to count total no of distinct islands 
islands is same if same structur without any rotation or anything else ....

CONCEPT ->

##YOU HAVE TO DO TWO THINGS 

** store similar islands once for that use **SET** and in end give set.size() , you will get total diff islands !!

**Now main point is how do you know similar islands ---> for that $$ "Store structure" $$

HOW TO STORE STRUCTUE ????? //IMPORTSANT 

** When we Either  use bfs or dfs we will have a described way of moving in graph like left,right,up,doen or any other permuattion which will be maintained 
so for any particular island keep the statrting cell(while iterating over grid the cell which you first reached) 
of that islands  as base cell and in that island subtact row,column of each cell with the base/starting cell of *that* island !!!

TC - n*m + 4*n*m + log(n*m) 
 // outer loop traversing grid +
   in dfs total recursing 4 direction of n*m elemnets +
   set ka insertion ->log(set size)

Example

Suppose the grid is:

L L 0 0 0
L 0 0 L L
0 0 0 L 0

There are 2 islands.

Island 1

Cells:

(0,0)  (0,1)
(1,0)

Starting cell (first cell found by BFS):

(row, col) = (0,0)

Now store relative coordinates:

Actual Cell	Relative Coordinate
(0,0)	(0-0, 0-0) = (0,0)
(0,1)	(0-0, 1-0) = (0,1)
(1,0)	(1-0, 0-0) = (1,0)

So we store

{ {0,0}, {0,1}, {1,0} }
Island 2

Cells:

(1,3)  (1,4)
(2,3)

Starting cell:

(row, col) = (1,3)

Again subtract the starting cell:

Actual Cell	Relative Coordinate
(1,3)	(1-1, 3-3) = (0,0)
(1,4)	(1-1, 4-3) = (0,1)
(2,3)	(2-1, 3-3) = (1,0)

We again store

{ {0,0}, {0,1}, {1,0} }
