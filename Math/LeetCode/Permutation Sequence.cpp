//problem link: https://leetcode.com/problems/permutation-sequence/

class Solution {
public:    
    string findPermutation(int n, int k, int &factN, string &nums){
        if(n==0) return "";
        factN/=n; // we need to divide by (n-1) factorial
        int idx=k/factN;
        k=k%factN;
        string res="";
        res+=nums[idx];
        nums.erase(nums.begin()+idx);        
        return res+findPermutation(n-1,k,factN,nums);
    }    
    
    string getPermutation(int n, int k) {
        string nums(n,'0');
        int factN=1;
        for(int i=1;i<=n;i++){
            factN*=i;
            nums[i-1]+=i;
        }
        return findPermutation(n,k-1,factN,nums);
    }
};