//problem link: https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    int n=A.length();
    unordered_map<char,int> mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;
    int res=0;
    for(int i=0;i<n-1;i++){
        if(mp[A[i]]>=mp[A[i+1]]) res+=mp[A[i]];
        else res-=mp[A[i]];
    }
    res+=mp[A[n-1]];
    return res;
}
