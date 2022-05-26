//problem link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
    
//Function to find the minimum number of platforms required at the
//railway station such that no train waits.
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr,arr+n);
    sort(dep,dep+n);
    int res=1, count=1;
    int i=1, j=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        res=max(res,count);
    }
    return res;
}