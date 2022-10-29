//problem link: https://www.interviewbit.com/problems/pairs-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_set<int> mp;
    int res=0;
    for(auto x:A){
        if(mp.find(x^B)!=mp.end()) res++;
        mp.insert(x);
    }
    return res;
}
