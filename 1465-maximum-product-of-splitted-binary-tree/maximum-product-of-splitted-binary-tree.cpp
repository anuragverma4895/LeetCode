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
    long totalsum = 0;
    long ans=LONG_MIN;
    int total(TreeNode * root) {
        if (root == NULL)
            return 0;
        long l=total(root->left);
        long r=total(root->right);
        long sub= root->val+ l+r;
        ans=max(sub*(totalsum-sub),ans);
        return sub;
    }
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;
        totalsum=total(root);
        total(root);
        return ans%1000000007;
    }
};