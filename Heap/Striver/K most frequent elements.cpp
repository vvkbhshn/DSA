//problem link: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {       
        
        // Method-1: BucketSort [time: O(n)]
        int n=arr.size();
        vector<int> res;
        // vector<vector<int>> bucket(n+1);
        unordered_map<int,vector<int>> bucket;
        unordered_map<int,int> mp;
        for(auto &x:arr) mp[x]++;
        for(auto &p:mp){
            bucket[p.second].push_back(p.first);
        }
        for(int i=n; i>0 && res.size()<k; i--){
            if(bucket.find(i)!=bucket.end()){
                for(int j=0;j<bucket[i].size() && res.size()<k; j++){
                    res.push_back(bucket[i][j]);
                }
            }
        }
        return res;
        
        
        // Method-2: using minHeap [time: O(nlogk)]
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // unordered_map<int,int> mp;
        // for(auto &x:arr) mp[x]++;
        // for(auto &x:mp){
        //     int num=x.first, cnt=x.second;
        //     pq.push({cnt,num});
        //     if(pq.size()>k) pq.pop();
        // }
        // vector<int> res;
        // while(!pq.empty()){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;
    }
};