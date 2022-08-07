//problem link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

class Solution
{
	public:
	
	    bool nextPermutation(string &s){
	        int n=s.length(),i,j;
	        for(i=n-2;i>=0;i--){
	            if(s[i]<s[i+1]) break;
	        }
	        if(i==-1) return false;
	        int l=i+1, r=n-1;
	        while(l<=r){
	            int mid=l+(r-l)/2;
	            if(s[mid]>s[i]){
	                l=mid+1;
	                j=mid;
	            }
	            else r=mid-1;
	        }
	        swap(s[i],s[j]);
	        reverse(s.begin()+i+1,s.end());
	        return true;
	    }
	
		vector<string>find_permutation(string s)
		{
		    vector<string> res;
		    sort(s.begin(),s.end());
		    res.push_back(s);
		    while(nextPermutation(s)){
		        res.push_back(s);
		    }
		    return res;
		}
};