//problem link: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int lo=0, mid=0, hi=n-1;
        while(mid<=hi){
            if(a[mid]==0) swap(a[mid++],a[lo++]);
            else if(a[mid]==1) mid++;
            else if(a[mid]==2) swap(a[mid],a[hi--]);
        }
    }    
};