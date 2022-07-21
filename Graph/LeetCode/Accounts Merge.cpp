//problem link: https://leetcode.com/problems/accounts-merge/

class Solution {
public:       
    int findAccount(int x, vector<int> &parent){
        if(parent[x]!=x) parent[x]=findAccount(parent[x],parent); //path compression
        return parent[x];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;//for final list of accounts (required output)
        vector<int> parent(accounts.size(),0); //to find the parent of each person (index-based)
        unordered_map<string,int> mp; //to map each email to its owner
        unordered_map<int,vector<string>> res_map; //to map each owner to the final list of emails
        //mp[email id] = index of the owner
        //res_map[index of owner] = vector of all his emails
        
        for(int i=0;i<accounts.size();i++){
            parent[i]=i;
            for(int j=1;j<accounts[i].size();j++){
                //if the current email (accounts[i][j]) belongs to some other person
                //find and make other person the parent of current person
                if(mp.find(accounts[i][j])!=mp.end()){
                    int x=findAccount(mp[accounts[i][j]],parent), y=findAccount(i,parent);
                    parent[x]=y;
                }
                //if its an unseen email, then map it with the parent of current person
                else mp[accounts[i][j]]=parent[i];
            }
        }
        
        //find the owners and push all their emails in res_map
        for(auto &it: mp){
            int idx=findAccount(it.second,parent);
            res_map[idx].push_back(it.first);
        }
        //find and sort the final list of all emails of a person, then push it into res
        for(auto &it: res_map){
            vector<string> emails=it.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(),accounts[it.first][0]);
            res.push_back(emails);
        }
        return res;
    }
};