//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Trie/problem/search-query-for-strings5049

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key){
    TrieNode* curr=root;
    for(char c:key){
        int index=c-'a';
        if(curr->children[index]==NULL) curr->children[index]=new TrieNode();
        curr=curr->children[index];
    }
    curr->isEndOfWord=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key){
    TrieNode* curr=root;
    for(char c:key){
        int index=c-'a';
        if(curr->children[index]==NULL) return false;
        curr=curr->children[index];
    }
    return curr->isEndOfWord;
}