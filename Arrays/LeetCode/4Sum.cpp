//problem link: https://leetcode.com/problems/4sum/

#define ll long long

class Solution {
public:    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
        if(n<4) return res;
        sort(nums.begin(),nums.end());        
        for(int i=0;i+3<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if((ll)nums[i]+(ll)nums[i+1]+(ll)nums[i+2]+(ll)nums[i+3]>target) break;
            if((ll)nums[i]+(ll)nums[n-3]+(ll)nums[n-2]+(ll)nums[n-1]<target) continue;
            for(int j=i+1;j+2<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if((ll)nums[i]+(ll)nums[j]+(ll)nums[j+1]+(ll)nums[j+2]>target) break;
                if((ll)nums[i]+(ll)nums[j]+(ll)nums[n-2]+(ll)nums[n-1]<target) continue;
                int l=j+1, r=n-1;
                long long new_target=target-nums[i]-nums[j];
                while(l<r){                   
                    if(nums[l]+nums[r]==new_target){
                        res.push_back(vector<int>{nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l+1]==nums[l]) l++;
                        while(l<r && nums[r-1]==nums[r]) r--;
                        l++;
                        r--;
                    }
                    else if(nums[l]+nums[r]<new_target) l++;
                    else r--;
                }
            }
        }
        return res;
            
    }
};