//problem link: https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

class Solution{
public:

    void backtrack(string &str, unordered_set<string> &mp, vector<string> &res, string &curr, int n, int idx){
        if(idx==n){
            if(curr.empty()) return;
            res.push_back(curr);
            return;
        }
        int len=curr.length();
        string temp="";
        for(int i=idx;i<n;i++){
            temp+=str[i];
            if(mp.find(temp)!=mp.end()){
                if(!curr.empty()) curr=curr+' ';
                curr+=temp;
                backtrack(str,mp,res,curr,n,i+1);
                curr.erase(curr.begin()+len,curr.end());
            }
        }
    }


    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> res;
        unordered_set<string> mp(dict.begin(),dict.end());
        string str=s;
        string curr="";
        int N=str.length();
        backtrack(str,mp,res,curr,N,0);
        return res;
    }
};