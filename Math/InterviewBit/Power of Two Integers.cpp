//problem link: https://www.interviewbit.com/problems/power-of-two-integers/

// int binPow(int a,int p){
//     long long res=1;
//     while(p){
//         if(p&1) res*=a;
//         a=a*a;
//         p>>=1;
//     }
//     return res;
// }

int Solution::isPower(int A) {
    
    // Method-1:
    // if(A==1) return 1;
    // for(int i=2;i<=sqrt(A);i++){
    //     int p=log(A)/log(i);
    //     if(binPow(i,p)==A) return 1;
    // }
    // return 0;

    // Method-2: (check if A has only 1 factor)
    if(A==1) return 1;
    for(int i=2;i<=sqrt(A);i++){
        int x=A;
        while(x%i==0) x/=i;
        if(x==1) return 1;
    }
    return 0;
}
