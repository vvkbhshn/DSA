//problem link: https://www.interviewbit.com/problems/4-sum/

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n=A.size();
    sort(A.begin(),A.end());
    vector<vector<int>> res;
    for(int i=0;i+3<n;i++){
        if(i>0 && A[i]==A[i-1]) continue;
        for(int j=i+1;j+2<n;j++){
            if(j>i+1 && A[j]==A[j-1]) continue;
            int l=j+1, r=n-1;
            int reqSum=B-A[i]-A[j];
            while(l<r){
                int sum=A[l]+A[r];
                if(sum<reqSum) l++;
                else if(sum>reqSum) r--;
                else{
                    res.push_back({A[i],A[j],A[l],A[r]});
                    while(l<r && A[l+1]==A[l]) l++;
                    while(l<r && A[r-1]==A[r]) r--;
                    l++;
                    r--;
                }
            }
        }
    }
    return res;
}
