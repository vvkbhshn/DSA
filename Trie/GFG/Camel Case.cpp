//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Trie/problem/camel-case04234120

struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    vector<string> words;
    TrieNode(){
        for(int i=0;i<26;i++) child[i]=NULL;
        isEnd=false;
    }
};

bool insert(TrieNode *root, string &s, string &pat){
    TrieNode* curr=root;
    string abbr="";
    bool isValid=false;
    for(auto c:s){
        if(c>='A' && c<='Z'){
            abbr+=c;
            // if(abbr.back()!=pat[abbr.size()-1]) return false;
            if(!isValid && abbr==pat) isValid=true;
            int i=c-'A';
            if(curr->child[i]==NULL) curr->child[i]=new TrieNode();
            curr=curr->child[i];
        }
    }
    curr->isEnd=true;
    if(isValid) curr->words.push_back(s);
    return isValid;
}

void search(TrieNode *root){
    TrieNode* curr=root;
    if(!curr->words.empty()){
        sort(curr->words.begin(),curr->words.end());
        for(auto &s:curr->words) cout<<s<<" ";
    }
    for(int i=0;i<26;i++){
        if(curr->child[i]!=NULL) search(curr->child[i]);
    }
}

class Solution{
    public:
    void findAllWords(vector<string> dict, string pattern){
        TrieNode* root=new TrieNode();
        map<string,vector<string>> mp;
        bool ok=false;
        for(auto &s:dict){
            if(insert(root,s,pattern)) ok=true;
        }
        if(!ok) cout<<"No match found";
        else search(root);
    }
};