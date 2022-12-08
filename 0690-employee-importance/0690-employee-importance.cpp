/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> map;
    void dfs(int x, int &sum)
    {
        sum += map[x]->importance;
        for(auto &y:map[x]->subordinates) 
            dfs(y, sum);
    }
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &x:employees)  map[x->id] = x;
        int sum = 0;
        sum += map[id]->importance;
        for(auto &x:map[id]->subordinates)    
            dfs(x, sum);
        return sum;
    }
};