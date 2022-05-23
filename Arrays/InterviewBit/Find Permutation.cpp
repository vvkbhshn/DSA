//problem link: https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    int n=A.length();
    int inc=0, dec=0;
    for(int i=0;i<n;i++){
        if(A[i]=='I') inc++;
        else dec++;
    }
    int temp=dec+1;
    int lo=temp-1, hi=temp+1;
    vector<int> res={temp};
    for(int i=0;i<n;i++){
        if(A[i]=='I') res.push_back(hi++);
        else res.push_back(lo--);
    }
    return res;
}
