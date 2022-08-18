**Kadane's Algo (check all letters pairs (a-z)), TC-O(nx26x26)..**
​
**Concept:**
* **Check for all pairs -> (a,b), (a,c), ...(a,z), (b,a), (b,c),...(b,z), ....., (z,a),(z,b), ....(z,y)**
​
**1.** Only consider two characters each time. Specify one p with higher frequency and one q with lower frequency. Thus, the time complexity would be in O(26*26*n).
**2.** Run Kadane's algorithm. Keep counting p and q. Once q's count > p's count, reset their counts. If q's count > 0, calculate the difference of counts between p and q.
**3.** There would be an edge case e.g., pqqpppppp, in which the last pppppp will not be involved as q's count is set to zero after processing first pq. Set a flag to extend the current interval after reseting p and q's count.
​
* bool **qSeen** flag would deal with the edge case
* e.g., "pqqpppppp"
after reset, there is no q but we can extend the interval to the previous q and the answer should -1