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
    TreeNode* build(vector<int>&postorder,int left,int right,int &postIndex,unordered_map<int,int>&mp){
        if(left>right) return NULL;
        int rootval=postorder[postIndex--];
        TreeNode* root=new TreeNode(rootval);
        int mid=mp[rootval];
        root->right=build(postorder,mid+1,right,postIndex,mp);
        root->left=build(postorder,left,mid-1,postIndex,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        int postIndex=postorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,0,inorder.size()-1,postIndex,mp);
    }
};