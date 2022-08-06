//problem link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> res;
    	if(root==NULL) return res;
    	bool rev=false;
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    	    int n=q.size();
    	    stack<int> s;
    	    for(int i=0;i<n;i++){
    	        Node* curr=q.front();
    	        q.pop();
    	        if(rev) s.push(curr->data);
    	        else res.push_back(curr->data);
    	        if(curr->left) q.push(curr->left);
    	        if(curr->right) q.push(curr->right);
    	    }
    	    if(rev){
    	        while(!s.empty()){
    	            res.push_back(s.top());
    	            s.pop();
    	        }
    	    }
    	    rev=!rev;
    	}
    	return res;
    }
};