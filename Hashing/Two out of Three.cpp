//problem link: https://www.interviewbit.com/problems/two-out-of-three/

void findNumbers(vector<int> &v, vector<int> &res, unordered_set<int> &mp1, unordered_set<int> &mp2, unordered_set<int> &mp3){
    for(auto x:v){
        int cnt=0;
        if(mp1.find(x)!=mp1.end()) cnt++;
        if(mp2.find(x)!=mp2.end()) cnt++;
        if(mp3.find(x)!=mp3.end()) cnt++;
        if(cnt>1){
            res.push_back(x);
            mp1.erase(x);
            mp2.erase(x);
            mp3.erase(x);
        }
    }
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_set<int> mp1,mp2,mp3;
    for(auto x:A) mp1.insert(x);
    for(auto x:B) mp2.insert(x);
    for(auto x:C) mp3.insert(x);
    vector<int> res;
    findNumbers(A,res,mp1,mp2,mp3);
    findNumbers(B,res,mp1,mp2,mp3);
    findNumbers(C,res,mp1,mp2,mp3);
    sort(res.begin(),res.end());
    return res;
}
