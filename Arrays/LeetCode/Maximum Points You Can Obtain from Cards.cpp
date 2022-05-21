//problem link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0, temp=0;
        for(int i=0;i<n-k;i++){
            sum+=cardPoints[i];
            temp+=cardPoints[i];
        }
        int minSubarraySum=temp;
        for(int i=n-k;i<n;i++){
            //Sliding Window Technique to calculate sum of subarrays of length n-k
            temp=temp+cardPoints[i]-cardPoints[i-(n-k)];
            minSubarraySum=min(minSubarraySum,temp);
            sum+=cardPoints[i];
        }
        return sum-minSubarraySum;
    }
};