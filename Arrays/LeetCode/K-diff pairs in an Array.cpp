//problem link: https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& A, int k) {        
        unordered_map<int,int> mp;
        int res=0;
        for(int i=0;i<A.size();i++){
            if(k==0){
                if(mp[A[i]]==1) res++;
            }
            else{
                if(mp[A[i]]>0) continue;
                res+=mp[A[i]-k]+mp[A[i]+k];
            }
            mp[A[i]]++;        
        }
        return res;
    }
};