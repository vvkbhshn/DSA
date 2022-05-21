//problem link: https://www.interviewbit.com/problems/add-one-to-number/

vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    vector<int> res(n);
    int carry=1;
    for(int i=n-1;i>=0;i--){
        int sum=A[i]+carry;
        res[n-1-i]=sum%10;
        carry=sum/10;
    }
    if(carry==1) res.push_back(1);

    int idx=-1;
    for(int i=res.size()-1;i>=0;i--){
        if(res[i]>0){
            idx=i;
            break;
        }
    }
    res.erase(res.begin()+idx+1,res.end());
    reverse(res.begin(),res.end());
    return res;
}