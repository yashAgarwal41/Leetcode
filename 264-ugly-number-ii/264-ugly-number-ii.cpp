class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n];
        arr[0]=1;
        int i=0, j=0, k=0;
        for(int x = 1;  x<n; x++)
        {
            int a = 2*arr[i];
            int b = 3*arr[j];
            int c = 5*arr[k];
            int mini = min({a, b, c});
            
            if(a==mini) 
            {
                arr[x] = a;
                i++;
            }
            if(b==mini)
            {
                arr[x] = b;
                j++;
            }
            if(c==mini)
            {
                arr[x] = c;
                k++;
            }
        }
        
        return arr[n-1];
    }
};