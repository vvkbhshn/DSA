//problem link: https://leetcode.com/problems/two-sum/

class Solution {
public:       
    vector<int> twoSum(vector<int>& nums, int target) {
        //Method-1: [O(n) time and O(n) space]
        vector<int> res;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                res={i,mp[target-nums[i]]};
                break;
            }
            mp[nums[i]]=i;
        }
        return res;
        
        // Method-2: [O(nlogn) time]
        // vector<int> res;
        // int n=nums.size();
        // vector<pair<int,int>> v;
        // for(int i=0;i<n;i++){
        //     v.push_back({nums[i],i});
        // }
        // sort(v.begin(),v.end());
        // int i=0, j=n-1;
        // while(i<j){
        //     if(v[i].first+v[j].first==target){
        //         res.push_back(v[i].second);
        //         res.push_back(v[j].second);
        //         break;
        //     }
        //     else if(v[i].first+v[j].first<target) i++;
        //     else j--;
        // }
        // return res;
    }
};