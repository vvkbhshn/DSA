//problem link: https://www.interviewbit.com/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &arr) {
    int sum=0, n=arr.size();
    for(auto x:arr) sum+=x;
    int k=sum/2;
    vector<bool> dp(k+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=k;j>=arr[i];j--){
            dp[j]=dp[j] || dp[j-arr[i]];
        }
    }
    for(int i=k;i>=0;i--){
        if(dp[i]) return sum-2*i;
    }
    return 0;
}