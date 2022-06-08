//problem link: https://www.interviewbit.com/problems/rearrange-array/

void Solution::arrange(vector<int> &arr) {
    int n=arr.size();
    for(int i=0;i<n;i++){
        arr[i]+=(arr[arr[i]]%n)*n;
    }
    for(int i=0;i<n;i++) arr[i]/=n;
}
