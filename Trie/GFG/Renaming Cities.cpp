
//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Trie/problem/renaming-cities28581833

class Solution
{
    public:
    
    void insert(Node *root, string &s){
        Node* curr=root;
        string res="";
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(!flag) res+=s[i];
            if(curr->mp.find(s[i])==curr->mp.end()){
                curr->mp[s[i]]=newNode();
                flag=true;
            }
            curr=curr->mp[s[i]];
            
        }
        curr->count1++;
        if(curr->isEndOfWord) cout<<res<<" "<<curr->count1<<'\n';
        else cout<<res<<'\n';
        curr->isEndOfWord=true;
    }
    
    void check(string *arr, int n){
        Node *root=newNode();
        for(int i=0;i<n;i++){
            insert(root,arr[i]);
        }
    }

};

