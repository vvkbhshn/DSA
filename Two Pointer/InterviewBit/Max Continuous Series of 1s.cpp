//problem link: https://www.interviewbit.com/problems/max-continuous-series-of-1s/

vector<int> Solution::maxone(vector<int> &A, int B) {
    int n=A.size();
    int start=0;
    int i=0, j=0, cnt=0, maxLen=0;
    while(j<n){
        if(A[j]==0){
            cnt++;
            if(cnt>B){
                while(i<n && A[i]==1) i++;
                i++;  
                cnt--;              
            }
        }
        if(j-i+1>maxLen){
            maxLen=j-i+1;
            start=i;
        }
        j++;
    }
    vector<int> res;
    for(i=start;i<start+maxLen;i++) res.push_back(i);
    return res;
}