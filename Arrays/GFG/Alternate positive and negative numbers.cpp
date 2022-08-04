//problem link: https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution{
public:
	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0) pos.push_back(arr[i]);
	        else neg.push_back(arr[i]);
	    }
	    int i=0,j=0, index=0;
	    while(i<pos.size()&&j<neg.size()){
	        arr[index++]=pos[i++];
	        arr[index++]=neg[j++];
	    }
	    while(i<pos.size()) arr[index++]=pos[i++];
	    while(j<neg.size()) arr[index++]=neg[j++];
	}
};