* To make all combinations of length len of k numbers we need to have numbers 1-k atleast appearing len times in the array :
* Example : for k = 3 len = 2
All possible sequences :
=> 1 1, 1 2, 1 3, 2 1, 2 2, 2 3, 3 1, 3 2, 3 3
* to create all those possibilities of arrangements we need to have 1,2,3,1,2,3 in the array as a subsequence (single 1-k group of numbers can be in any order i.e, we
can also have 3,2,1,3,2,1 or 2,3,1,1,3,2 etc.)
which is numbers from 1-k must be appearing len times in the array as a subsequence.