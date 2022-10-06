//problem link: https://www.interviewbit.com/problems/justified-text/

string leftJustify(vector<string> &A, int start, int end, int B){
    string res;
	for(int i=start;i<=end;i++){
		if(res.empty()) res=A[i];
		else res+=" "+A[i];
	}
	while(res.length()<B) res+=' ';
    return res;
}

string middleJustify(vector<string> &A, int start, int end, int cnt, int B){
    string res;    
    int numSpaces=(B-cnt)/(end-start);
    int extraSpaces=(B-cnt)%(end-start);
    for(int i=start;i<end;i++){
        res+=A[i];
        if(extraSpaces){
            res+=' ';
            extraSpaces--;
        }
        for(int j=0;j<numSpaces;j++) res+=' ';
    }
    res+=A[end];
    return res;
}

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> res;
    if(A.empty()) return res;
    int n=A.size();
    int cnt=0;
    int i=0, j=0;
    while(i<n && j<n){
        if(cnt+(j-i)+A[j].length()>B){
            if(j-i==1) res.push_back(leftJustify(A,i,j-1,B));
            else res.push_back(middleJustify(A,i,j-1,cnt,B));
            i=j;
			cnt=0;			
        }
        cnt+=A[j].length();
		j++;
    }	
	res.push_back(leftJustify(A,i,n-1,B));
    return res;
}