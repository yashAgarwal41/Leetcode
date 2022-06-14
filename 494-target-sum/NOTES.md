Solution-1
* Add '+' or '-'...
* for sum-> 0 to 1000 dp[i][sum]
* for sum-> -1 to -1000 dp[i][1000-sum], i.e. (1001-2001)
​
Solution-2
* lets take an vector v = [1, 1, 2, 3], target = 1
* so possible ans: +1, -1, -2, +3 => (1+3) - (1+2) =1
* -1, +1, -2, +3 => (1+3) - (1+2) =1
* +1, +1, +2, -3 => (1+1+2) - (3) =1
* So calculate all subsequence sums=sum1
* so remainig sum = totalSum-sum1;
* now if sum1 - remaining = target, then add to ans.