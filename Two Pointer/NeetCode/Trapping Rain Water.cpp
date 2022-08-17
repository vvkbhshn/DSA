//problem link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(), res=0;
        int i=0, j=n-1;
        int maxLeft=height[i], maxRight=height[j];
        while(i<j){
            if(maxLeft<=maxRight){
                i++;
                maxLeft=max(maxLeft,height[i]);
                res+=maxLeft-height[i];
            }
            else{
                j--;
                maxRight=max(maxRight,height[j]);
                res+=maxRight-height[j];
            }
        }
        return res;
    }
};