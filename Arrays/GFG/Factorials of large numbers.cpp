//problem link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> fact;
        fact.push_back(1);
        if(N==1) return fact;
        for(int i=2;i<=N;i++){
            int carry=0;
            for(int j=0;j<fact.size();j++){
                int prod=i*fact[j]+carry;
                fact[j]=prod%10;
                carry=prod/10;
            }
            while(carry){
                fact.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(fact.begin(),fact.end());
        return fact;
    }
};