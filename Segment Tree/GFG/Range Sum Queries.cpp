//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/range-sum-queries2353

void updateValueUTIL(ll *st, int index, int diff, int ss, int se, int si){
    if(index<ss || index>se) return;
    st[si]+=diff;
    if(se>ss){
        int mid=(ss+se)/2;
        updateValueUTIL(st,index,diff,ss,mid,2*si+1);
        updateValueUTIL(st,index,diff,mid+1,se,2*si+2);
    }
}

//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val){
    int diff=new_val-arr[index];
    arr[index]=new_val;
    updateValueUTIL(st,index,diff,0,n-1,0);
}

ll getSumUTIL(ll *st, int qs, int qe, int ss, int se, int si){
    if(ss>qe || se<qs) return 0;
    if(ss>=qs && se<=qe) return st[si];
    int mid=(ss+se)/2;
    return getSumUTIL(st,qs,qe,ss,mid,2*si+1)+getSumUTIL(st,qs,qe,mid+1,se,2*si+2);
}

//Function to return sum of elements in range from index qs (query start) to qe (query end).
ll getsum(ll *st, int n, int l, int r){
    // add code here
    return getSumUTIL(st,l,r,0,n-1,0);
}