class Transaction{
public:
    string name;
    int time;
    int amount;
    string city;
    int index;
};

Transaction findDetails(string s, int idx){
    Transaction curr;
    string temp="";
    int i=0, cnt=0;
    while(i<s.length()){
        if(s[i]==',' || i==s.length()-1){
            if(cnt==0) curr.name=temp;
            else if(cnt==1) curr.time=stoi(temp);
            else if(cnt==2) curr.amount=stoi(temp);
            else curr.city=temp;
            cnt++;
            temp="";
        }
        else temp+=s[i];
        i++;
    }
    curr.index=idx;
    return curr;
}


class Solution {
public:
    vector<string> invalidTransactions(vector<string>& A) {
        int n=A.size();
        vector<string> res;
        vector<bool> valid(n,true);
        vector<Transaction> v(n);
        // unordered_map<int,vector<Transaction>> mp;
        for(int i=0;i<n;i++){
            v[i]=findDetails(A[i],i);
            // mp[v[i].time].push_back(v[i]);
        }
        for(int i=0;i<n;i++){
            if(v[i].amount>1000) valid[i]=false;
        }
        for(int i=0;i<n;i++){            
            
            // int t=v[i].time;
            // for(int j=t-60;j<=t+60;j++){                              
            //     if(!mp[j].empty()){
            //         for(auto temp:mp[j]){
            //             if(v[i].name==temp.name && abs(v[i].time-temp.time)<=60 &&                                                v[i].city!=temp.city){                            
            //                     valid[i]=valid[temp.index]=false;
            //             }
            //         }
            //     }
            // }
            
            for(int j=i+1;j<n;j++){
                if(v[i].name==v[j].name && abs(v[i].time-v[j].time)<=60 && v[i].city!=v[j].city){
                    valid[i]=valid[j]=false;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!valid[i]) res.push_back(A[i]);
        }
        return res;
    }
};