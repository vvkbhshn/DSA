//problem link: https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

void fillLPS(vector<int> &lps, string &s){
    int n=s.length();
    lps[0]=0;
    int i=1, len=0;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else{
				len=lps[len-1];
			}
        }
    }
}

int Solution::solve(string A) {
    //KMP algorithm
    int n=A.length();  
    string B=A;
    reverse(B.begin(),B.end());  
    string s=A+'~'+B;
    vector<int> lps(2*n+1);
    fillLPS(lps,s);    
    return n-lps[2*n];
}