//problem link: https://www.interviewbit.com/problems/multiply-strings/

string Solution::multiply(string A, string B) {    
    int m=A.length(), n=B.length();
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());    
    string res(m+n,'0');
    for(int i=0;i<m;i++){
        int carry=0;
        for(int j=0;j<n || carry>0;j++){
            int sum=(res[i+j]-'0')+carry;
            if(j<n) sum+=(A[i]-'0')*(B[j]-'0');
            res[i+j]=(sum%10)+'0';
            carry=sum/10;
        }
    }    
    while(res.length()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(),res.end());    
    return res;
 }
