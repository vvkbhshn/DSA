//problem link: https://www.interviewbit.com/problems/kth-permutation-sequence/

int fact(int n){
    if(n>12) return INT_MAX;
    if(n<=1) return 1;
    return n*fact(n-1);
}

string Solution::getPermutation(int n, int k) {
    k--;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    string res;
    for(int i=0;i<n;i++){
        int f=fact(n-1-i);
        int q=k/f;
        k=k%f;
        auto it=s.begin();
        advance(it,q);
        int num=*it;
        res+=to_string(num);
        s.erase(it);
    }
    return res;
}