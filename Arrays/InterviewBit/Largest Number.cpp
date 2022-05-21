//problem link: https://www.interviewbit.com/problems/largest-number/

bool myCmp(string a, string b){
    int m=a.length(), n=b.length();
    for(int i=0;i<min(m,n);i++){
        if(a[i]>b[i]) return true;
        else if(b[i]>a[i]) return false;
    }
    if(m>n) return myCmp(a.substr(n,m-n),b);
    else if(n>m) return myCmp(a,b.substr(m,n-m));
    return true;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    for(auto x:A) v.push_back(to_string(x));
    sort(v.begin(),v.end(),myCmp);
    string s="";
    for(auto x:v) s+=x;
    if(s[0]=='0'){
        while(s.length()!=1) s.pop_back();
    }
    return s;
}
