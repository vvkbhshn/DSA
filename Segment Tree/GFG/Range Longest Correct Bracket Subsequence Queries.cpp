//problem link: https://practice.geeksforgeeks.org/batch/cip-1/track/P100-Segment-Tree/problem/range-queries-for-longest-correct-bracket-subsequence4719

class Solution{
    public:    
    Node getLongestSequenceUTIL(Node *st, int qs, int qe, int ss, int se, int si){
        if(ss>qe || se<qs) return Node();
        if(ss>=qs && se<=qe) return st[si];
        int mid=(ss+se)/2;
        Node l=getLongestSequenceUTIL(st,qs,qe,ss,mid,2*si+1);
        Node r=getLongestSequenceUTIL(st,qs,qe,mid+1,se,2*si+2);
        int minMatched=min(l.open,r.closed);
        Node res;
        res.open=l.open+r.open-minMatched;
        res.closed=l.closed+r.closed-minMatched;
        res.pairs=l.pairs+r.pairs+minMatched;
        return res;
    }
    
    //Function to returns the maximum length of correct bracket subsequence between starting and ending indexes.
    int getLongestSequence(Node* st, string str, int qs, int qe, int n){
        return 2*getLongestSequenceUTIL(st,qs,qe,0,n-1,0).pairs;
    }
};