//problem link: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> mp;
        int res=0, sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0) res=i+1;
            else{
                if(mp.find(sum)!=mp.end()){
                    res=max(res,i-mp[sum]);
                }
                else mp[sum]=i;
            }
        }
        return res;
    }
};