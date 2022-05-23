//problem link: https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    if(A==0) return res;
    res.push_back({1});
    for(int i=1;i<A;i++){
        vector<int> temp={1};    
        int j=1;
        while(j<=i-1){
            temp.push_back(res.back()[j]+res.back()[j-1]);
            j++;
        }
        temp.push_back(1);
        res.push_back(temp);
    }
    return res;
}
