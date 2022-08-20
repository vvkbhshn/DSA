//problem link: https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end()) return "";
        int idx=-1;
        int lo=0, hi=mp[key].size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(mp[key][mid].first<=timestamp){
                idx=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return (idx==-1) ? "" : mp[key][idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */