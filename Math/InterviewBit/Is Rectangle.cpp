//problem link: https://www.interviewbit.com/problems/is-rectangle/

int Solution::solve(int A, int B, int C, int D) {
    int arr[]={A,B,C,D};
    sort(arr,arr+4);
    if(arr[0]==arr[1] && arr[2]==arr[3]) return 1;
    return 0;
}
