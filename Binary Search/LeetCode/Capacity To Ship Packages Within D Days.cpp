//problem link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:    
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        // l=max(A), r=sum(A)
        int l=0,r=0,mid;
        for(auto x:weights){
            l=max(l,x);
            r+=x;
        }        
        while(l<r){
            mid=l+(r-l)/2;
            int curr=0, reqDays=1;
            for(int i=0;i<n && reqDays<=days;i++){
                curr+=weights[i];
                if(curr>mid){
                    curr=weights[i];
                    reqDays++;
                }
            }
            if(reqDays>days) l=mid+1;
            else r=mid;
        }
        return l;
    }
};