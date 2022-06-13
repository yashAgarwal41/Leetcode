* First sort the array and then
* Create PrefixSum and SuffixSum
* Now iterate in the array
* Now at index 'i',  to make all elements equal..
##### -> Make all the left elements zero and all right elements equal to v[i]...
* To make all left 0,  ans = ps[i-1]
* To make all right = v[i], ans += ss[i+1] - (no of elem at right)*v[i]
​