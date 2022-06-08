//problem link: https://www.interviewbit.com/problems/city-tour/

#define mod 1000000007

long long fact(int n){
    long long res=1;
    for(int i=1;i<=n;i++){
        res *= i;
        res %= mod;
    }
    return res;
}

long long power(long long base, long long exp){
    base %= mod;
    long long res=1;
    while(exp>0){
        if(exp&1) res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res;
}

int Solution::solve(int numCities, vector<int> &visited) {
    sort(visited.begin(), visited.end());
    vector<int> interval;
    interval.push_back(visited[0]-1);
    for(int i=1; i<visited.size(); i++) interval.push_back(visited[i]-visited[i-1]-1);
    interval.push_back(numCities-visited.back());
    
    int remaining=numCities-visited.size();
    long long ans=fact(remaining);
    for(auto x:interval){
        ans *= power(fact(x),mod-2);
        ans %= mod;
    }

    int n=0;
    for(int i=1; i<interval.size()-1; i++) if(interval[i]>1) n += (interval[i]-1);
    ans = (ans*power(2,n))%mod;
    return ans;
}