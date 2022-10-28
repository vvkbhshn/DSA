//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Trie/problem/most-frequent-word-in-an-array-of-strings3528

struct TrieNode{
    TrieNode* child[26];
    string key;
    int timestamp;
    int count;
    TrieNode(){
        for(int i=0;i<26;i++) child[i]=NULL;
        timestamp=-1;
        count=0;
    }
};

void insert(string &s, TrieNode* root, int time){
    TrieNode* curr=root;
    for(auto c:s){
        int i=c-'a';
        if(curr->child[i]==NULL) curr->child[i]=new TrieNode();
        curr=curr->child[i];
    }
    if(curr->timestamp==-1) curr->timestamp=time;
    curr->key=s;
    curr->count++;
}

void search(TrieNode* root, string &res, int &maxCount, int &maxTime){
    //preorder traversal
    if(root==NULL) return;
    TrieNode* curr=root;
    for(int i=0;i<26;i++){
        if(curr->child[i]!=NULL){
            if(curr->child[i]->count>maxCount || (curr->child[i]->count==maxCount && curr->child[i]->timestamp>maxTime)){
                res=curr->child[i]->key;
                maxCount=curr->child[i]->count;
                maxTime=curr->child[i]->timestamp;
            }
            search(root->child[i],res,maxCount,maxTime);
        }
    }
}


class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n){
        // Method-1:
        // TrieNode *root=new TrieNode();
        // for(int i=0;i<n;i++) insert(arr[i],root,i);
        // string res;
        // int maxCount=0, maxTime=-1;
        // search(root,res,maxCount,maxTime);
        // return res;
        
        // Method-2:
        unordered_map<string,pair<int,int>> mp;
        string res;
        int maxCount=0, maxTime=-1;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()) mp[arr[i]]={1,i};
            else mp[arr[i]].first++;
            int cnt=mp[arr[i]].first, time=mp[arr[i]].second;
            if(cnt>maxCount || (cnt==maxCount && time>maxTime)){
                res=arr[i];
                maxCount=cnt;
                maxTime=time;
            }
        }
        return res;
    }
};