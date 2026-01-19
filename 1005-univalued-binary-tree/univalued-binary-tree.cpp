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
    // BFS
    // bool isUnivalTree(TreeNode* root) {
    //     vector<int>ans;
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     while(q.size()){
    //         TreeNode* curr=q.front();
    //         q.pop();
    //         ans.push_back(curr->val);
    //         if(curr->left){
    //             q.push(curr->left);
    //         }
    //         if(curr->right){
    //             q.push(curr->right);
    //         }
    //     }
    //     for(int i=1;i<ans.size();i++){
    //         if(ans[i-1]!=ans[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // DFS
    bool dfs(TreeNode* root, int val){
        if(root==NULL) return true;
        if(root->val!=val){
            return false;
        }
        return dfs(root->left,val) && dfs(root->right,val);
    }
    bool isUnivalTree(TreeNode* root){
        return dfs(root,root->val);
    }
};