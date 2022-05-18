// problem link: https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int> freq;
    int currXOR=0;
    int res=0;
    for(auto x:A){
        currXOR=currXOR^x;
        if(currXOR==B) res++;
        if(freq.find(currXOR^B)!=freq.end()) res+=freq[currXOR^B];
        freq[currXOR]++;
    }
    return res;
}
