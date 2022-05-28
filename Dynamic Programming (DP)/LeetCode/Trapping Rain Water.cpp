//problem link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        // Method-1: [O(n) time, O(1) space]
        // Two Pointer approach
        int res=0;
        int l=0, r=n-1;
        int lMax=0, rMax=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lMax) lMax=height[l];
                else res+=lMax-height[l];
                l++;
            }
            else{
                if(height[r]>=rMax) rMax=height[r];
                else res+=rMax-height[r];
                r--;
            }
        }
        return res;
        
        // Method-2: [O(n) time, O(n) space]
        // int rMax[n];
        // rMax[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--) rMax[i]=max(rMax[i+1],height[i]);
        // int res=0, lMax=height[0];
        // for(int i=1;i<n-1;i++){
        //     lMax=max(lMax,height[i]);
        //     res+=min(lMax,rMax[i])-height[i];
        // }
        // return res;
    }
};