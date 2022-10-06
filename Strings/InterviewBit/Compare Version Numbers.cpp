//problem link: https://www.interviewbit.com/problems/compare-version-numbers/

int Solution::compareVersion(string A, string B) {
    int m=A.length(), n=B.length();
    int i=0,j=0;
    string curr1,curr2;
    while(i<m || j<n){
        while(i<m && A[i]=='0') i++;
        while(j<n && B[j]=='0') j++;
        while(i<m && A[i]!='.') curr1+=A[i++];
        while(j<n && B[j]!='.') curr2+=B[j++];
        int len1=curr1.length(), len2=curr2.length();
        if(len1>len2) return 1; 
        else if(len2>len1) return -1;
		else if(curr1>curr2) return 1;
		else if(curr2>curr1) return -1;
        else{
            curr1.clear();
            curr2.clear();
            i++;
            j++;
        }
    }
    return 0;
}
