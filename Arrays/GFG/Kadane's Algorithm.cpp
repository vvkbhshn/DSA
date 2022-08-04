//problem link: https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution{
    public:

    long long maxSubarraySum(int arr[], int n){
        // Your code here
        long long maxSum=arr[0], currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            maxSum=max(maxSum,currSum);
            if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};