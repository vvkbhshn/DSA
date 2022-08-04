//problem link: https://practice.geeksforgeeks.org/problems/searching-in-an-array-where-adjacent-differ-by-at-most-k0456/1

int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n){
        if(arr[i]==x) return i;
        i=i+max(1,abs(arr[i]-x)/k);
    }
    return -1;
} 