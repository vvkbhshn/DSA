//problem link: https://www.interviewbit.com/problems/prime-sum/

vector<int> Solution::primesum(int A) {
    //Sieve of Eratosthenes
    bool prime[A+1];
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=A;i++){
        if(prime[i]){
            for(int j=i*i;j<=A;j+=i) prime[j]=false;
        }
    }
    for(int i=2;i<=A/2;i++) if(prime[i] && prime[A-i]) return{i,A-i};
    return {};
}
