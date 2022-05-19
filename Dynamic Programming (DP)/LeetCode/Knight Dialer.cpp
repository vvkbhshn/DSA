//problem link: https://leetcode.com/problems/knight-dialer/submissions/

class Solution {
public:
    int mod=1e9+7;    
    
    long long solve(vector<vector<int>>&dp, int num, int n){
        if(dp[num][n]!=-1) return dp[num][n];
        if(n==1) return dp[num][n]=1;        
        long long res=0;
        if(num==1) res=solve(dp,6,n-1)+solve(dp,8,n-1);
        else if(num==2) res=solve(dp,7,n-1)+solve(dp,9,n-1);
        else if(num==3) res=solve(dp,4,n-1)+solve(dp,8,n-1);
        else if(num==4) res=solve(dp,0,n-1)+solve(dp,3,n-1)+solve(dp,9,n-1);
        else if(num==5) res=0;
        else if(num==6) res=solve(dp,0,n-1)+solve(dp,1,n-1)+solve(dp,7,n-1);
        else if(num==7) res=solve(dp,2,n-1)+solve(dp,6,n-1);
        else if(num==8) res=solve(dp,1,n-1)+solve(dp,3,n-1);
        else if(num==9) res=solve(dp,2,n-1)+solve(dp,4,n-1);
        else if(num==0) res=solve(dp,4,n-1)+solve(dp,6,n-1);
        return dp[num][n]=res%mod;
    }
    
    int knightDialer(int n) {        
        // Method-1: bottomUp DP [O(n) time, O(1) space];
        // vector<vector<int>> paths={{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        // vector<long> dp(10,1);
        // for(int i=0;i<n-1;i++){
        //     vector<long> temp(10,0);
        //     for(int i=0;i<10;i++){
        //         for(auto j:paths[i]) temp[i]=(temp[i]+dp[j])%mod;
        //     }   
        //     dp=temp;
        // }
        // long long res=0;
        // for(int i=0;i<10;i++) res=(res+dp[i])%mod;
        // return res;
        
        // Method-2: topDown DP [O(n) time, O(n) space]
        long long res=0;
        vector<vector<int>> dp(10,vector<int>(n+1,-1));
        for(int i=0;i<=9;i++) res+=solve(dp,i,n);
        return res%mod;
    }
};