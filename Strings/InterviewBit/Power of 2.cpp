//problem link: https://www.interviewbit.com/problems/power-of-2/

bool isOne(string &A){
    return A.size()==1 && A[0]=='1';
}

bool isOdd(string &A){
    return ((A.back()-'0')&1)==1;
}

int Solution::power(string A) {
    int i=0;
    while(A[i]=='0') i++;
    A=A.substr(i);
    if(A.empty() || A=="1") return 0;   
    
    while(!isOne(A)){
        if(isOdd(A)) return 0;
        string temp;
        int n=A.length(), carry=0;
        i=0;
        while(i<n){
            int sum=(A[i]-'0')+10*carry;
            if(sum>1){
                carry=sum%2;
                temp+=((sum/2)+'0');  
            }
            else if(sum==1){
                carry=1;
                if(!temp.empty()) temp+='0';
            }
            else if(sum==0) temp+='0';
            i++;
        }
        A=temp;
    }
    return 1;
}
