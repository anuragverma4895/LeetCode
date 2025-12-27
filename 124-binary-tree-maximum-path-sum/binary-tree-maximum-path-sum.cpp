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

    int dfs(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        int left_sum=dfs(root->left,ans);
        if(left_sum<0) left_sum=0;
        int right_sum=dfs(root->right,ans);
        if(right_sum<0) right_sum=0;
        ans=max(ans,left_sum+right_sum+root->val);
        return max(left_sum,right_sum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MIN;
        dfs(root,ans);
        return ans;
    }
};