//problem link: https://www.interviewbit.com/problems/distinct-numbers-in-window/

vector<int> Solution::dNums(vector<int> &A, int k) {
    int n=A.size();
    vector<int> res;
    if(n==0 || k>n) return res;
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++) mp[A[i]]++;
    res.push_back(mp.size());
    for(int i=k;i<n;i++){
        mp[A[i]]++;
        mp[A[i-k]]--;
        if(mp[A[i-k]]==0) mp.erase(A[i-k]);
        res.push_back(mp.size());
    }
    return res;
}