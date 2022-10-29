//problem link: https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n=A.size();
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(B-A[i])!=mp.end()) return {mp[B-A[i]],i+1};
        if(mp.find(A[i])==mp.end()) mp[A[i]]=i+1;
    }
    return {};
}
