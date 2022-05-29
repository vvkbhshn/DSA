//problem link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int res=0;
        int i=0;
        while(i<n-1){
            if(colors[i]!=colors[i+1]) i++;
            else{
                int tempSum=0, maxTime=0;
                int j=i;
                while(colors[j]==colors[i]){
                    tempSum+=neededTime[j];
                    maxTime=max(maxTime,neededTime[j]);
                    j++;
                }
                res+=tempSum-maxTime;
                i=j;
            }            
        }
        return res;
    }
};