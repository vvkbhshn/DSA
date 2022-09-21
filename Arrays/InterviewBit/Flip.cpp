//problem link: https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    int n=A.size();
    vector<int> res;
    int maxSoFar=0, currMax=0;
    int l=0;
    for(int i=0;i<n;i++){
        if(A[i]=='1') currMax--;
        else currMax++;
        if(currMax>maxSoFar){
            maxSoFar=currMax;
            res={l+1,i+1};
        }
        if(currMax<0){
            currMax=0;
            l=i+1;
        }
    }
    return res;
}
