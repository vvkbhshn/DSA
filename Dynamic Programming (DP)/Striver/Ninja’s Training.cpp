//problem link: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

int solve(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int type){
    if(n==0) return 0;
    if(dp[n][type]!=-1) return dp[n][type];
    int res=0;
    for(int i=0;i<3;i++){
        if(i!=type) res=max(res,points[n-1][type]+solve(points,dp,n-1,i));
    }
    return dp[n][type]=res;
}


int ninjaTraining(int n, vector<vector<int>> &points){
//     method-1: bottom up
        int prev[3]={0};
        int curr[3]={0};
        for(int i=0;i<n;i++){
            curr[0]=points[i][0]+max(prev[1],prev[2]);
            curr[1]=points[i][1]+max(prev[0],prev[2]);
            curr[2]=points[i][2]+max(prev[0],prev[1]);
            for(int j=0;j<3;j++) prev[j]=curr[j];
        }
        return max(curr[0],max(curr[1],curr[2]));
    
//     method-2: top down
//     vector<vector<int>> dp(n+1,vector<int>(3,-1));
//     solve(points,dp,n,0);
//     solve(points,dp,n,1);
//     solve(points,dp,n,2);
//     return max(dp[n][0],max(dp[n][1],dp[n][2]));
}