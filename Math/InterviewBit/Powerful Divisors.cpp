# problem link: https://www.interviewbit.com/problems/powerful-divisors/

class Solution:
    def powerfulDivisors(self, A):
        maxi=max(A)
        dp=[2]*(maxi+1);
        dp[0],dp[1]=0,1
        for i in range(2,maxi+1):
            if i*i>maxi: 
                break
            for j in range(i*i,maxi+1,i):
                if j==i*i:
                    dp[j]+=1
                else:
                    dp[j]+=2
        for i in range(1,maxi+1):
            if dp[i]&(dp[i]-1)==0:
                dp[i]=dp[i-1]+1
            else:
                dp[i]=dp[i-1]            
        return [dp[x] for x in A]