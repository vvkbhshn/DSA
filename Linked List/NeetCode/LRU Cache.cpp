//problem link: https://leetcode.com/problems/lru-cache/

class Node{
    public:
    int key,val;
    Node *prev;
    Node *next;
    Node(int x, int y){
        key=x;
        val=y;
        prev=next=NULL;
    }
};


class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> mp;
    Node *head;
    Node *tail;
    
public:
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) remove(mp[key]);
        mp[key]=new Node(key,value);
        insert(mp[key]);
        if(mp.size()>cap){
            Node *lru=tail->prev;
            remove(lru);            
            mp.erase(lru->key);
        }
    }
        
    void remove(Node *root){
        Node *prevNode=root->prev;
        Node *nextNode=root->next;        
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insert(Node *root){
        Node *prevNode=head;
        Node *nextNode=head->next;        
        prevNode->next=root;
        root->prev=prevNode;        
        root->next=nextNode;
        nextNode->prev=root;
    }          
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */