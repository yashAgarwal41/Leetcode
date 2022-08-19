**/* Time Complexity:**
* X = Number of non-obstacle squares.
* O(m*n) ==> To find the start, end, & number of non-obstacle squares.
* O(4 * 3^(X-2)) ==> DFS Helper will explore all possible paths. At each square
* (except start & end) we will explore at most 3 directions. At start we will
* explore 4 directions and at end we will stop the further exploration of that
* path. Here X is bounded by m*n.
*
* Total time complexity: O(m*n + 4 * 3^(X-2)) = O(3^(m*n))
*
* Space Complexity: O(X) --> For recursion stack. Here X is bounded by m*n.
*
*/