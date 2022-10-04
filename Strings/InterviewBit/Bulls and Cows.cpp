//problem link: https://www.interviewbit.com/problems/bulls-and-cows/

string Solution::solve(string A, string B) {
    int n=A.length();
    int freq[10]={0};
    int bull=0, cow=0;
    for(int i=0;i<n;i++){
        if(A[i]==B[i]) bull++;
        else freq[A[i]-'0']++;
    }
    for(int i=0;i<n;i++){
        if(A[i]!=B[i] && freq[B[i]-'0']>0){
            cow++;
            freq[B[i]-'0']--;
        }
    }
    string res=to_string(bull)+'A'+to_string(cow)+'B';
    return res;
}
