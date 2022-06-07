//problem link: https://www.interviewbit.com/problems/palindrome-integer/

int Solution::isPalindrome(int A) {
    
    // Method-1:
    if(A<0) return 0;
    if(A==0) return 1;
    int pow=log10(A);
    int pow10=1, p=pow;
    while(p--) pow10*=10;
    for(int i=pow; i>0 && A>0; i-=2){
        //compare first and last digits
        if(A/pow10!=A%10) return 0;
        A%=pow10;
        A/=10;
        pow10/=100; 
    }
    return 1;

    // Method-2
    // if(A<0) return 0;
    // int temp=0, x=A;
    // while(x){
    //     temp=temp*10+x%10;
    //     x/=10;
    // }
    // if(temp==A) return 1;
    // return 0;

    // Method-3
    // if(A<0) return 0;
    // string a=to_string(A);
    // string b=a;
    // reverse(b.begin(),b.end());
    // if(a==b) return 1;
    // return 0;
}
