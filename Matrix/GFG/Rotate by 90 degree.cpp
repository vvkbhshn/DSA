//problem link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            swap(matrix[i][j],matrix[n-j-1][n-i-1]);
        }
        reverse(matrix[i].begin(),matrix[i].end());
    }   
}