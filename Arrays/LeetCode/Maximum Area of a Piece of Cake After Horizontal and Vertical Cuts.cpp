//problem link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int p=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int m=horizontalCuts.size(), n=verticalCuts.size();        
        int maxH=max(horizontalCuts[0], h-horizontalCuts[m-1]);
        int maxW=max(verticalCuts[0], w-verticalCuts[n-1]);
        for(int i=1;i<m;i++) maxH=max(maxH,horizontalCuts[i]-horizontalCuts[i-1]);
        for(int i=1;i<n;i++) maxW=max(maxW,verticalCuts[i]-verticalCuts[i-1]);
        return (long long)maxH*maxW%p;
    }
};