//problem link: https://www.interviewbit.com/problems/array-sum/

vector<int> Solution::addArrays(vector<int> &A, vector<int> &B) {
    vector<int> res;
    int m=A.size(), n=B.size();
    int i=m-1,j=n-1,carry=0;
    while(i>=0 || j>=0 || carry>0){
        int sum=carry;
        if(i>=0) sum+=A[i--];
        if(j>=0) sum+=B[j--];
        res.push_back(sum%10);
        carry=sum/10;
    }
    reverse(res.begin(),res.end());
    return res;
}
