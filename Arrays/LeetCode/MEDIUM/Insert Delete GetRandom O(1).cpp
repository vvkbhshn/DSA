//problem link: https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> mp;
public:
    RandomizedSet() {        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()) return false;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;
        int idx=mp[val];
        swap(arr[idx],arr[arr.size()-1]);
        mp[arr[idx]]=idx;
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */