//problem link: https://leetcode.com/problems/permutation-sequence/

class Solution {
public:    
    string findPermutation(int n, int k, int &factN, vector<bool> &vis){
        if(n==0) return "";
        factN/=n; // we need to divide by (n-1) factorial
        int q=k/factN;
        int count=0;
        string res="";
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                if(count==q){
                    vis[i]=true;
                    res+=(char)(i+'1');
                    break;
                }
                count++;
            }
        }
        k=k%factN;
        return res+findPermutation(n-1,k,factN,vis);
    }    
    
    string getPermutation(int n, int k) {
        vector<bool> vis(n,false);
        int factN=1;
        // calculate N factorial
        for(int i=1;i<=n;i++) factN*=i;
        return findPermutation(n,k-1,factN,vis);
    }
};