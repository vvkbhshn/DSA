//problem link: https://www.interviewbit.com/problems/colorful-number/

int Solution::colorful(int A) {
    string s=to_string(A);
    int n=s.length();
    vector<int> prefProd(n);
    int p=1;
    for(int i=0;i<n;i++){
        p=p*(s[i]-'0');
        prefProd[i]=p;
    }
    unordered_set<int> mp;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<n;j++){
            p=prefProd[j];
            if(j>i-1 && prefProd[j-i]>0) p/=prefProd[j-i];
            if(mp.find(p)!=mp.end()) return 0;
            mp.insert(p);
        }
    }
    return 1;
}