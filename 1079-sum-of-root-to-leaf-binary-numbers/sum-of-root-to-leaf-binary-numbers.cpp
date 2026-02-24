/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void findallroot(TreeNode* root,string s,vector<string>&v){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            v.push_back(s);
            return;
        }
        findallroot(root->left,s,v);
        findallroot(root->right,s,v);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string>v;
        string s="";
        findallroot(root,s,v);
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int a=stoi(v[i],nullptr,2);
            sum+=a;
        }
        return sum;
    }
};