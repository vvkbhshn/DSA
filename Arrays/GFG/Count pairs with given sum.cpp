//problem link: https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int> mp;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=mp[k-arr[i]];
            mp[arr[i]]++;
        }
        return cnt;
    }
};