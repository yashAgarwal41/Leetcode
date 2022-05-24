class Solution {
public:
    //Using Seive- TC-(O(nlog(logn)))
    int primes[5000001];
    void seive(int n, int primes[])
    {
        memset(primes, 0, sizeof primes);
        primes[0]=1, primes[1]=1;
        for(int i=2; i<n; i++)
        {
            if(primes[i]==0)
            {
                for(long long j=1LL*i*i; j<n; j+=i)   primes[j]=1;
            }
        }
    }
    int countPrimes(int n) {
        int cnt=0;
        seive(n, primes);
        for(int i=0; i<n; i++)
            cnt+=(primes[i]==0);
        
        return cnt;
    }
};