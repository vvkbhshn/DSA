//problem link: https://www.interviewbit.com/problems/stepping-numbers/hints/

vector<int> Solution::stepnum(int A, int B) {
    if(A>B) swap(A,B);
    vector<int> res;
    if(A==0) res.push_back(0);
    for(int i=1;i<=9;i++){
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int num=q.front();
			q.pop();
			if(num>B) continue;
			if(num>=A && num<=B) res.push_back(num);
			int lastDigit=num%10;
			if(lastDigit>0) q.push(num*10+lastDigit-1);
			if(lastDigit<9) q.push(num*10+lastDigit+1);
		}
	}
    sort(res.begin(),res.end());
    return res;
}