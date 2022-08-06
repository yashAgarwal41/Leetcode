class Solution {
public:
    //MergeSort..TC-O(nlogn), SC-O(n)..
    int mergeSort(int low, int high, vector<int> &v)
    {
        int mid = low+(high-low)/2, cnt=0;
        int i=low, j=mid+1, k=0;
        vector<int> temp(high-low+1);
        
        //First count the no of pairs..
//         for(int i=low; i<=mid; i++)
//         {
//             while(j<=high and v[i]>2LL*v[j])
//                 j++;
//             cnt += j-(mid+1);
//         }
        while(i<=mid and j<=high)
        {
            if(v[i]>2LL*v[j]) 
            {
                cnt+=mid-i+1;
                j++;
            }
            else i++;
        }
        //Nw merge Sort..
        i=low, j=mid+1;
        while(i<=mid and j<=high)
        {
            if(v[i]>v[j])   temp[k++] = v[j++];
            else temp[k++] = v[i++];
        }
        while(i<=mid)
            temp[k++] = v[i++];
        while(j<=high)
            temp[k++] = v[j++];
        
        k=0;
        for(int i=low; i<=high; i++)
            v[i] = temp[k++];
        
        return cnt;
        
    }
    int invCount(int low, int high, vector<int> &v)
    {
        if(low>=high)   return 0;
        int mid = low+(high-low)/2;
        int x = invCount(low, mid, v);
        int y = invCount(mid+1, high, v);
        int z = mergeSort(low, high, v);
        
        return x+y+z;
    }
    int reversePairs(vector<int>& v) {
        int n = v.size();
        return invCount(0, n-1, v);
    }
};