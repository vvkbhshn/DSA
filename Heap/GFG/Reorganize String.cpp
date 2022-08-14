//problem link: https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        string res="";
        int freq[26]={0};
        for(auto c:s) freq[c-'a']++;
        priority_queue<pair<int,char>> q;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                if(freq[i]>(n+1)/2) return res;
                q.push({freq[i],(char)('a'+i)});
            }
        }
        pair<int,char> p={0,'.'};
        while(!q.empty()){
            auto curr=q.top();
            q.pop();
            res+=curr.second;
            curr.first--;
            if(p.first>0) q.push(p);
            if(curr.first>0) p=curr;
            else p={0,'.'};            
        }
        return res;
    }
};