//problem link: https://www.interviewbit.com/problems/subarrays-with-distinct-integers/

int func(vector<int> &A, int B){
   int n=A.size(),res=0;
    int i=0,j=0;
    unordered_map<int,int> mp;
    while(j<n){
        mp[A[j]]++;
        while(mp.size()>B){
            mp[A[i]]--;
            if(mp[A[i]]==0) mp.erase(A[i]);
            i++;
        }
        res+=j-i+1;
        j++;
    }
    return res; 
}

int Solution::solve(vector<int> &A, int B) {
    return func(A,B)-func(A,B-1);
}