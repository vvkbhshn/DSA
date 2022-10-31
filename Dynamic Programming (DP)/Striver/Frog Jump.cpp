// problem link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

int energyLost(vector<int> &heights, vector<int> &dp, int index){
    if(index==0) return 0;
    if(dp[index]!=-1) return dp[index];
    int jumpOne=abs(heights[index]-heights[index-1])+energyLost(heights,dp,index-1);
    int jumpTwo=INT_MAX;
    if(index>1) jumpTwo=abs(heights[index]-heights[index-2])+energyLost(heights,dp,index-2);
    return dp[index]=min(jumpOne,jumpTwo);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n,-1);
    return energyLost(heights,dp,n-1);
}