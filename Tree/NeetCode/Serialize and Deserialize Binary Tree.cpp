//problem link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
private:
    int index=0;    
public:    
    void preorder(TreeNode *root, string &res){
        if(root==NULL){
            res+="# ";
            return;
        }
        res+=to_string(root->val)+' ';
        preorder(root->left,res);
        preorder(root->right,res);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        preorder(root,res);
        return res;
    }
    
    TreeNode* deserialize_helper(string &data){
        if(data[index]==' ') index++;
        string temp="";
        if(data[index]=='#'){
            index++;
            return NULL;
        }
        while(isdigit(data[index]) || data[index]=='-'){
            temp+=data[index];
            index++;
        } 
        int val=stoi(temp);
        TreeNode *root=new TreeNode(val);
        root->left=deserialize_helper(data);
        root->right=deserialize_helper(data);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //to pass as reference for less momory usage
        return deserialize_helper(data);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));