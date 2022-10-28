//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/range-min-max-queries4557

PII getMinMaxUTIL(PII *st, int qs, int qe, int ss, int se, int si){
    if(ss>qe || se<qs) return {INT_MAX,INT_MIN};
    if(ss>=qs && se<=qe) return st[si];
    int mid=(ss+se)/2;
    PII l=getMinMaxUTIL(st,qs,qe,ss,mid,2*si+1);
    PII r=getMinMaxUTIL(st,qs,qe,mid+1,se,2*si+2);
    return {min(l.first,r.first),max(l.second,r.second)};
}


//Function to update a value in input array and segment tree.
PII getMinMax(PII *st, int *arr, int n, int qs, int qe){
    return getMinMaxUTIL(st,qs,qe,0,n-1,0);
}

void updateValueUTIL(PII *st, int index, int val, int ss, int se, int si){
    if(index<ss || index>se) return;
    if(ss==se && ss==index) st[si]={val,val};
    if(se>ss){
        int mid=(ss+se)/2;
        updateValueUTIL(st,index,val,ss,mid,2*si+1);
        updateValueUTIL(st,index,val,mid+1,se,2*si+2);
        st[si].first=min(st[2*si+1].first,st[2*si+2].first);
        st[si].second=max(st[2*si+1].second,st[2*si+2].second);
    }
}

//Function to return minimum and maximum of elements in range from index qs (quey start) to qe (query end).
void updateValue(int *arr, PII *st, int n, int index, int new_val){
   arr[index]=new_val;
   updateValueUTIL(st,index,new_val,0,n-1,0);
}