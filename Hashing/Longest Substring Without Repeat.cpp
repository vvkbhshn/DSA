//problem link: https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    int n=A.length();
    unordered_set<char> mp;
    int i=0,j=0;
    int res=0;
    while(i<=j && j<n){
        if(mp.find(A[j])!=mp.end()){
            while(i<=j && A[i]!=A[j]){
                mp.erase(A[i]);
                i++;
            }
            i++;
        }
        mp.insert(A[j]);
        res=max(res,j-i+1);
        j++;
    }
    return res;
}