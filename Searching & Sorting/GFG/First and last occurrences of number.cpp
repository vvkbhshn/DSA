//problem link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> res(2,-1);
    int l=0, r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x && (mid==0 || arr[mid]!=arr[mid-1])){
            res[0]=mid;
            break;
        }
        else if(arr[mid]<x) l=mid+1;
        else r=mid-1;
    }
    l=0; r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==x && (mid==n-1 || arr[mid]!=arr[mid+1])){
            res[1]=mid;
            break;
        }
        if(arr[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return res;
}