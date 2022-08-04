//problem link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>> res;
        if(n<4) return res;
        sort(arr.begin(),arr.end());
        for(int i=0;i+3<n;i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j+2<n;j++){
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int target=k-arr[i]-arr[j];
                int l=j+1, r=n-1;
                while(l<r){
                    int sum=arr[l]+arr[r];
                    if(sum==target){
                        res.push_back(vector<int>{arr[i],arr[j],arr[l],arr[r]});
                        while(l<r && arr[l]==arr[l+1]) l++;
                        while(l<r && arr[r]==arr[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};