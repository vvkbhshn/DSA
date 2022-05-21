//problem link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& A) {
        int n=A.size();
        vector<int> res;
        
        // Method-1:
        for(int i=0;i<n;i++){
            int idx=abs(A[i])-1;
            if(A[idx]<0) res.push_back(idx+1);
            A[idx]=-A[idx];
        }
        return res;
        
        // Method-2:
        // int p=n+1;
        // for(int i=0;i<n;i++){
        //     A[A[i]%p-1]+=p;
        // }
        // for(int i=0;i<n;i++) A[i]/=p;
        // for(int i=0;i<n;i++) if(A[i]>1) res.push_back(i+1);
        // return res;
    }
};