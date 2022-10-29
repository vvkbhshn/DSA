//problem link: https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_set<int> mp;
    for(auto x:A){
        if(mp.find(x-B)!=mp.end() || mp.find(x+B)!=mp.end()) return 1;
        mp.insert(x);
    }
    return 0;
}