//problem link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&arr)
	{
	    // Code here
	    int cnt=0, n=arr.size();
	    vector<int> aux=arr;
	    sort(aux.begin(),aux.end());
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++){
	        mp[arr[i]]=i;
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i]!=aux[i]){
	            int idx=mp[aux[i]];
	            swap(arr[i],arr[idx]);
	            mp[arr[idx]]=idx;
	            mp[arr[i]]=i;
	            cnt++;
	        }
	    }
	    return cnt;
	}
};