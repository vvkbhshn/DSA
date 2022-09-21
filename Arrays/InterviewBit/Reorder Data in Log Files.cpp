//problem link: https://www.interviewbit.com/problems/reorder-data-in-log-files/

bool myCmp(string &s1, string &s2){
    string a=s1.substr(s1.find('-'));
    string b=s2.substr(s2.find('-'));
    if(a==b) return s1<s2;
    else return a<b; 
}

vector<string> Solution::reorderLogs(vector<string> &A) {
    vector<string> logs, digitLogs;
    for(auto &s:A){
        if(isdigit(s.back())) digitLogs.push_back(s);
        else logs.push_back(s);
    }
    sort(logs.begin(),logs.end(),myCmp);
    logs.insert(logs.end(),digitLogs.begin(),digitLogs.end());
    return logs;
}