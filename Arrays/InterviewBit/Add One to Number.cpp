//problem link: https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    vector<int> res;
    int carry=1, idx=-1;
    for(int i=0;i<n;i++){
        if(A[i]==0) idx=i;
        else break;
    }
    for(int i=n-1;i>idx;i--){
        int sum=A[i]+carry;
        carry=sum/10;
        sum=sum%10;
        res.push_back(sum);
    }
    if(carry==1) res.push_back(1);
    reverse(res.begin(),res.end());
    return res;
}