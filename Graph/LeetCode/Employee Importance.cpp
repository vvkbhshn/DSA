//problem link: https://leetcode.com/problems/employee-importance/

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
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> mp;
        for(auto employee:employees) mp[employee->id]=employee;
        int res=0;
        queue<Employee*> q;
        q.push(mp[id]);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            res+=p->importance;
            for(auto next:p->subordinates) q.push(mp[next]);
        }
        return res;
    }
};