//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/largest-sum-contiguous-subarray-in-range1248

/*
struct node {
    int sum, prefixSum, suffixSum, maxSubArraySum;
    node() {
        sum = prefixSum = suffixSum = maxSubArraySum = INT_MIN;
    }
};
*/

void updateUTIL(node tree[], int index, int val, int ss, int se, int si){
    if(index<ss || index>se) return;
    if(ss==se && ss==index){
        tree[si].sum=val;
        tree[si].prefixSum=val;
        tree[si].suffixSum=val;
        tree[si].maxSubArraySum=val;
    }
    if(se>ss){
        int mid=(ss+se)/2;
        updateUTIL(tree,index,val,ss,mid,2*si+1);
        updateUTIL(tree,index,val,mid+1,se,2*si+2);
        node l=tree[2*si+1], r=tree[2*si+2];
        tree[si].sum=l.sum+r.sum;
        tree[si].prefixSum=max(l.prefixSum, l.sum+r.prefixSum);
        tree[si].suffixSum=max(r.suffixSum, l.suffixSum+r.sum);
        tree[si].maxSubArraySum=max({tree[si].prefixSum,tree[si].suffixSum,l.suffixSum+r.prefixSum,
                                l.maxSubArraySum,r.maxSubArraySum});
    }
}

void update(int arr[], node tree[], int n, int index, int new_value) {
    arr[index-1]=new_value;
    updateUTIL(tree,index-1,new_value,0,n-1,0);
}

node getSum(node tree[], int qs, int qe, int ss, int se, int si){
    if(ss>qe || se<qs) return node();
    if(ss>=qs && se<=qe) return tree[si];
    int mid=(ss+se)/2;
    if(qe<=mid) return getSum(tree,qs,qe,ss,mid,2*si+1);
    if(qs>mid) return getSum(tree,qs,qe,mid+1,se,2*si+2);
    node l=getSum(tree,qs,qe,ss,mid,2*si+1);
    node r=getSum(tree,qs,qe,mid+1,se,2*si+2);
    node res=node();
    res.sum=l.sum+r.sum;
    res.prefixSum=max(l.prefixSum, l.sum+r.prefixSum);
    res.suffixSum=max(r.suffixSum, l.suffixSum+r.sum);
    res.maxSubArraySum=max({res.prefixSum,res.suffixSum,l.suffixSum+r.prefixSum,
                            l.maxSubArraySum,r.maxSubArraySum});
    return res;
}

// l and r are the range given in the problem
int query(int arr[], node tree[], int n, int l, int r) {
    return getSum(tree,l-1,r-1,0,n-1,0).maxSubArraySum;
}