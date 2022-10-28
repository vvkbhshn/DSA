//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Trie/problem/trie-insert-and-search0651

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL) curr->children[index]=new TrieNode();
        curr=curr->children[index];
    }
    curr->isLeaf=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    TrieNode* curr=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(curr->children[index]==NULL) return false;
        curr=curr->children[index];
    }
    return curr->isLeaf;
}