//problem link: https://www.interviewbit.com/problems/implement-strstr/

void fillLPS(vector<int> &lps, string s){
    int n=s.length();
    lps[0]=0;
    int i=1,len=0;
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


int Solution::strStr(const string A, const string B) {
    //Rabin Karp Algorithm
    int n=A.length(), m=B.length();
    vector<int> lps(m);
    fillLPS(lps,B);
    int i=0, j=0, res=-1;
    while(i<n){
        if(A[i]==B[j]){
            i++;
            j++;
        }
        if(j==m){
            res=i-m;
            break;
            j=lps[j-1];
        }
        else if(i<n && A[i]!=B[j]){
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    return res;
}
