//problem link: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

vector<int> Solution::lszero(vector<int> &A) {
    vector<int> res;
    int n=A.size();
    unordered_map<int,int> mp;
    mp[0]=-1;
    int sum=0, maxLen=0;
    pair<int,int> p;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(mp.find(sum)!=mp.end()){
            if(i-mp[sum]>maxLen){
                maxLen=i-mp[sum];
                p={mp[sum]+1,i};
            }
        }
        else mp[sum]=i;
    }
    if(maxLen==0) return res;
    for(int i=p.first;i<=p.second;i++) res.push_back(A[i]);
    return res;
}