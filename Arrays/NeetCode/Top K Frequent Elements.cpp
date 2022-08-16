//problem link: https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    
    int partition(vector<pair<int,int>> &v, int l, int r){
        int pivot=v[r].second, index=l;
        for(int i=l;i<r;i++){
            if(v[i].second>pivot){
                swap(v[i],v[index++]);
            }
        }
        swap(v[r],v[index]);
        return index;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        
        // Method-1 O(N) [Bucket Sort]        
        unordered_map<int,vector<int>> bucket;
        for(auto &p:mp) bucket[p.second].push_back(p.first);
        vector<int> res;
        for(int i=n; i>0 && res.size()<k; i--){
            if(bucket.find(i)!=bucket.end()){
                res.insert(res.end(),bucket[i].begin(),bucket[i].end());
            }
        }
        return res;
        
        // Method-2 O(N) average [QuickSelect algorithm]
        // vector<pair<int,int>> v;
        // for(auto &p:mp) v.push_back(p);
        // int l=0, r=v.size()-1;
        // while(l<=r){
        //     int mid=partition(v,l,r);
        //     if(mid>k-1) r=mid-1;
        //     else if(mid<k-1) l=mid+1;
        //     else break;
        // }
        // vector<int> res;
        // for(int i=0;i<k;i++){
        //     res.push_back(v[i].first);
        // }
        // return res;
        
        // Method-3: O(NlogK)
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // for(auto &p:mp){
        //     pq.push({p.second,p.first});
        //     if(pq.size()>k) pq.pop();
        // }
        // vector<int> res;
        // while(!pq.empty()){
        //     res.push_back(pq.top().second);
        //     pq.pop();
        // }
        // return res;
        
        // Method-4: O(NlogN)
        // vector<pair<int,int>> v;
        // for(auto &p:mp){
        //     v.push_back({p.second,p.first});
        // }
        // sort(v.rbegin(),v.rend());
        // vector<int> res;
        // for(int i=0;i<k;i++){
        //     res.push_back(v[i].second);
        // }
        // return res;
    }
};