//problem link: https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {        
        // Method-1: [Greedy] 
        int counter[26]={0};
        int maxCount=0, numMaxCount=0;
        for(auto c:tasks){
            counter[c-'A']++;
            if(counter[c-'A']==maxCount) numMaxCount++;
            else if(counter[c-'A']>maxCount){
                maxCount=counter[c-'A'];
                numMaxCount=1;
            }
        }
        int partCount=maxCount-1;
        int partLength=n-(numMaxCount-1);
        int emptySlots=partCount*partLength;
        int availableTasks=tasks.size()-maxCount*numMaxCount;
        int idles=max(0,emptySlots-availableTasks);
        return tasks.size()+idles;
        
        // Method-2: [Heap]
        // int counter[26]={0};
        // for(auto c:tasks) counter[c-'A']++;
        // priority_queue<int> pq;
        // for(int i=0;i<26;i++){
        //     if(counter[i]>0) pq.push(counter[i]);
        // }
        // unordered_map<int,int> aux;
        // int time=0;
        // while(!pq.empty() || !aux.empty()){
        //     int key=time-(n+1);
        //     if(aux.find(key)!=aux.end()){
        //         pq.push(aux[key]);
        //         aux.erase(key);
        //     }
        //     if(!pq.empty()){
        //         int cnt=pq.top();
        //         pq.pop();
        //         if(cnt>1) aux[time]=cnt-1;
        //     }
        //     time++;
        // }
        // return time;           
    }
};