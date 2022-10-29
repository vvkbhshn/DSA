//problem link: https://www.interviewbit.com/problems/anagrams/

string calcHash(const string &s){
    int freq[26]={0};
    for(auto c:s) freq[c-'a']++;
    string res="";
    for(int i=0;i<26;i++) res+=to_string(freq[i])+"-";
    return res;
}

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> res;
    unordered_map<string,vector<int>> mp;
    for(int i=0;i<A.size();i++){
        string s=calcHash(A[i]);
        mp[s].push_back(i+1);
    }
    for(auto &p:mp) res.push_back(p.second);
    return res;
}