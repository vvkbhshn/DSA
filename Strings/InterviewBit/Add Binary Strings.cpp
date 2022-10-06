//problem link: https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    int n=A.length(), m=B.length();
    int carry=0;
    int i=n-1, j=m-1;
    string res;
    while(i>=0 || j>=0 || carry>0){
        int sum=0;
        if(i>=0){
            if(A[i]=='1') sum++;
            i--;
        }
        if(j>=0){
            if(B[j]=='1') sum++;
            j--;
        }
        if(carry==1) sum++;
        carry=sum/2;
        if(sum%2==0) res+='0';
        else res+='1';
    }
    reverse(res.begin(),res.end());
    return res;
}
