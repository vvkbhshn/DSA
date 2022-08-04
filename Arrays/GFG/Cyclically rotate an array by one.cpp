//problem link: https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1

void rotate(int arr[], int n)
{
    int prev=arr[0];
    for(int i=1;i<n;i++){
        int curr=arr[i];
        arr[i]=prev;
        prev=curr;
    }
    arr[0]=prev;
}