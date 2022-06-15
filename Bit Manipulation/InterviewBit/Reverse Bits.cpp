//problem link: https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int A) {
    unsigned int res=0;
    
    // Method-1:
    for(int i=0;i<32;i++){
        res<<=1;
        if(A&(1<<i)) res++;
    }
    
    // Method-2:
    // int i,j;
    // for(i=31,j=0; i>=0; i--,j++){
    //     //swap Ith and Jth bits
    //     if(A&(1<<j)) res|=(1<<i);
    // }
    
    return res;
}