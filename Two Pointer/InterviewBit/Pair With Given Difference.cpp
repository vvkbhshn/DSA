//problem link: https://www.interviewbit.com/problems/pair-with-given-difference/

int Solution::solve(vector<int> &A, int B) {    
    // Method-1: O(n) time, O(n) space
    unordered_set<int> mp;
    for(auto x:A){
        if(mp.find(x-B)!=mp.end() || mp.find(x+B)!=mp.end()) return 1;
        mp.insert(x);
    }
    return 0;
    
    // Method-2: O(nlogn) time, O(1) space
    // sort(A.begin(),A.end());
    // B=abs(B);
    // int n=A.size();
    // int i=0, j=1;
    // while(i<n && j<n){
    //     int diff=A[j]-A[i];
    //     if(diff==B && i!=j) return 1;
    //     else if(diff>B) i++;
    //     else j++;
    // }
    // return 0;
}
