//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/range-lcm-queries3348

ll getLcmUtil(ll *st, int qs, int qe, int ss, int se, int si){
    if(ss>qe || se<qs) return 1;
    if(ss>=qs && se<=qe) return st[si];
    int mid=(ss+se)/2;
    ll l=getLcmUtil(st,qs,qe,ss,mid,2*si+1);
    ll r=getLcmUtil(st,qs,qe,mid+1,se,2*si+2);
    return LCM(l,r);
}

//Function to find LCM of given range.
ll getLCM(ll *st, int *arr, int n, int qs, int qe){
    return getLcmUtil(st,qs,qe,0,n-1,0);
}

void updateValueUtil(ll *st, int index, int val, int ss, int se, int si){
    if(index<ss || index>se) return;
    if(ss==se && ss==index) st[si]=val;
    if(se>ss){
        int mid=(ss+se)/2;
        updateValueUtil(st,index,val,ss,mid,2*si+1);
        updateValueUtil(st,index,val,mid+1,se,2*si+2);
        st[si]=LCM(st[2*si+1],st[2*si+2]);
    }
}

//Function to update a value in input array and segment tree.
void updateValue(int *arr, ll *st, int n, int index, int new_val){
    arr[index]=new_val;
    updateValueUtil(st,index,new_val,0,n-1,0);
}