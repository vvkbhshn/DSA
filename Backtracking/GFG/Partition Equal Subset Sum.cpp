//problem link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum&1) return 0;
        sum/=2;
        bool dp[sum+1]={0};
        dp[0]=1;
        for(int i=0;i<N;i++){
            for(int j=sum;j>=arr[i];j--){
                dp[j] = dp[j] | dp[j-arr[i]];
            }
        }
        return dp[sum];
    }
};