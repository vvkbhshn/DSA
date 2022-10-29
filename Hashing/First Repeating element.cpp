//problem link: https://www.interviewbit.com/problems/first-repeating-element/

int Solution::solve(vector<int> &A) {
    int n=A.size();
    int minIndex=INT_MAX, res=-1;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(A[i])!=mp.end()){
            if(mp[A[i]]<minIndex){
                minIndex=mp[A[i]];
                res=A[i];
            }
        }
        else mp[A[i]]=i;
    }
    return res;    
}
