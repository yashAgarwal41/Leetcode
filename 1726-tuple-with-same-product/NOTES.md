TC-O(n*n)..Calculating freq of all possible products..
*     if there are more than 1 value of same product, that means tuples can form..
*     so 2 same product can form 1 pair and 8 tuples
*     e.g-1  products = [6->1, 8->1, 12->2, 18->1, 24->1]
*     so only product 12 will made tuples..(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3) , (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
*     similarly 3 same products can form 3 (3c2 = 3) pairs and 8 tuples..
*     similarly 3 same products can form 6 (4c2 = 6) pairs and 8 tuples..
*     similarly 3 same products can form 10(5c2 = 10) pairs and 8 tuples..