//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/range-gcd-queries3654

class Solution{
    public:    
    int findRangeGcdUTIL(int st[], int qs, int qe, int ss, int se, int si){
        if(ss>qe || se<qs) return 0;
        if(ss>=qs && se<=qe) return st[si];
        int mid=(ss+se)/2;
        int l=findRangeGcdUTIL(st,qs,qe,ss,mid,2*si+1);
        int r=findRangeGcdUTIL(st,qs,qe,mid+1,se,2*si+2);
        return gcd(l,r);
    }
    
    //Function to find gcd of given range.
    int findRangeGcd(int l, int r, int st[], int n){
        return findRangeGcdUTIL(st,l,r,0,n-1,0);
    }
    
    void updateValueUTIL(int st[], int index, int val, int ss, int se, int si){
        if(index<ss || index>se) return;
        if(ss==se && ss==index) st[si]=val;
        if(se>ss){
            int mid=(ss+se)/2;
            updateValueUTIL(st,index,val,ss,mid,2*si+1);
            updateValueUTIL(st,index,val,mid+1,se,2*si+2);
            st[si]=gcd(st[2*si+1],st[2*si+2]);
        }
    }
    
    //Function to update a value in input array and segment tree.
    void updateValue(int index, int new_val, int *arr, int st[], int n){
        arr[index]=new_val;
        updateValueUTIL(st,index,new_val,0,n-1,0);
    }
};