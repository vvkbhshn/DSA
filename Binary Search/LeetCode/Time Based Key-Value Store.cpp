//problem link: https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
    
private:
    unordered_map<string,vector<pair<string,int>>> mp;
    
public:
    
    TimeMap() {  
              
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        int l=0, r=mp[key].size()-1,mid;
        string res="";
        while(l<=r){
            mid=l+(r-l)/2;
            if(mp[key][mid].second>timestamp) r=mid-1;
            else{
                res=mp[key][mid].first;
                l=mid+1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */