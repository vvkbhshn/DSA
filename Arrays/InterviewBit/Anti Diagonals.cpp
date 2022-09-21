//problem link: https://www.interviewbit.com/problems/anti-diagonals/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>> res;
    int i=0,j=0;
    while(i<n && j<n){
        int x=i, y=j;
        vector<int> temp;
        while(x<n && y>=0){
            temp.push_back(A[x][y]);
            x++;
            y--;
        }
        res.push_back(temp);
        if(j<n-1) j++;
        else i++;
    }
    return res;
}
