//problem link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int rMax[n], lMax=arr[0];
        rMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(rMax[i+1],arr[i]);
        }
        long long res=0;
        for(int i=1;i<n-1;i++){
            lMax=max(lMax,arr[i]);
            if(min(lMax,rMax[i])>arr[i]) res+=min(lMax,rMax[i])-arr[i];
        }
        return res;
    }
};