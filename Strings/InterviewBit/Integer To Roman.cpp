//problem link: https://www.interviewbit.com/problems/integer-to-roman/

string solve(int n, int pos, unordered_map<int,string> &mp1, unordered_map<int,string> &mp2){
    string res="";
    if(n==0) return res;
    else if(n<=3) for(int i=0;i<n;i++) res+=mp1[pos];
    else if(n==4) res+=mp2[pos]+mp1[pos];
    else if(n==5) res+=mp2[pos];
    else if(n<=8){        
        for(int i=6;i<=n;i++) res+=mp1[pos];
        res+=mp2[pos];
    }
    else if(n==9) res+=mp1[pos+1]+mp1[pos];
    return res;
}


string Solution::intToRoman(int A) {
    unordered_map<int,string> mp1={{0,"I"},{1,"X"},{2,"C"},{3,"M"}};
    unordered_map<int,string> mp2={{0,"V"},{1,"L"},{2,"D"}};    
    string res;
    int i=0;
    while(A>0){
        res+=solve(A%10,i,mp1,mp2);
        A/=10;
        i++;
    }
    reverse(res.begin(),res.end());
    return res;
}
