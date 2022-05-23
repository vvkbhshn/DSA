//problem link: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

vector<int> Solution::getRow(int k) {

    vector <int> ans;
    int c = 1;
    for (int i = 1; i <= k+1; i++) {
        ans.push_back(c);
        c = c*(k+1-i) / i;
    }
    return ans;
    
    
    // vector<int> A(k+1,0),B(k+1,0);
    // for(int i=0;i<=k;i++){
    //     B[0]=1;
    //     int j=1;
    //     while(j<=i){
    //         B[j]=A[j]+A[j-1];
    //         j++;
    //     }
    //     A=B;
    // }
    // return A;
}
