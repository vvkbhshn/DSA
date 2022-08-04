//problem link: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s;
        s.insert(0);
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(s.find(currSum)!=s.end()) return true;
            s.insert(currSum);
        }
        return false;
    }
};