class Solution {
public:
    //priority Queue, TC-O(n)..
    static bool compare(vector<int> v1, vector<int> v2)
    {
        if(v1[1]==v2[1])    return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> pq;
        int day = 0, ans=0;
        for(auto &v: courses)
        {
            if(v[0] + day <= v[1])
            {
                ans++;
                day += v[0];
                pq.push(v[0]);
            }
            else 
            {
                if(pq.empty())  continue;
                if(pq.top()>v[0])
                {
                    if(day - pq.top() + v[0] <= v[1])   //swap the largest value with the current value..
                    {
                        day = day - pq.top() + v[0];
                        pq.pop();
                        pq.push(v[0]);
                    }
                }
            }
        }
        return ans;
    }
};