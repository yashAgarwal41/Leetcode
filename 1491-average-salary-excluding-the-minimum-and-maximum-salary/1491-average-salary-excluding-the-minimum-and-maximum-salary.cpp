class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(salary.begin(), salary.end());
        double avg = 0.0;
        for(int i=1; i<n-1; i++)
            avg += salary[i];
        avg = avg*1.0/(n-2);
        return avg;
    }
};