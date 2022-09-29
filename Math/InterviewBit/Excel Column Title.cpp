//problem link: https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int n) {
    string res;
    while(n>0){
        res+=('A'+(n-1)%26);
        n=(n-1)/26;
    }
    reverse(res.begin(),res.end());
    return res;
}