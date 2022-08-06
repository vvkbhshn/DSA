//problem link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if(root==NULL) return res;
        unordered_map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int left_idx=0, right_idx=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto p=q.front();
                q.pop();
                Node *curr=p.first;
                int index=p.second;
                if(mp.find(index)==mp.end()){
                    mp[index]=curr->data;
                    left_idx=min(left_idx,index);
                    right_idx=max(right_idx,index);
                }
                if(curr->left) q.push({curr->left,index-1});
                if(curr->right) q.push({curr->right,index+1});
            }
        }
        for(int i=left_idx; i<=right_idx; i++){
            res.push_back(mp[i]);
        }
        return res;
    }
};  