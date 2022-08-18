//problem link: https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Method-1: 
        deque<int> q;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            while(!q.empty() && q.front()<=i-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
        
        // Method-2:
        // int n=nums.size();
        // int maxLeft[n], maxRight[n];
        // maxLeft[0]=nums[0];
        // maxRight[n-1]=nums[n-1];
        // for(int i=1;i<n;i++){
        //     maxLeft[i] = (i%k==0) ? nums[i] : max(nums[i],maxLeft[i-1]);
        //     int j=n-1-i;
        //     maxRight[j] = (j%k==0) ? nums[j] : max(nums[j],maxRight[j+1]);
        // }
        // vector<int> res;
        // for(int i=0;i+k<=n;i++){
        //     res.push_back(max(maxRight[i],maxLeft[i+k-1]));
        // }
        // return res;
    }
};