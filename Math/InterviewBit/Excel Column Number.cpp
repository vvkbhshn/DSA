//problem link: https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    int res=0;
    for(auto c:A) res=res*26+(c-'A'+1);
    return res;
}