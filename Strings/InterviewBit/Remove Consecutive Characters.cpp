//problem link: https://www.interviewbit.com/problems/remove-consecutive-characters/

string Solution::solve(string A, int B) {
    int n=A.length();
    string res;
    int cnt=1;
    char c=A[0];
    for(int i=1;i<n;i++){
        if(A[i]==c) cnt++;
        else{
            if(cnt!=B) for(int j=0;j<cnt;j++) res+=c;
            cnt=1;
            c=A[i];
        }
    }
    if(cnt!=B) for(int j=0;j<cnt;j++) res+=c;
    return res;
}
