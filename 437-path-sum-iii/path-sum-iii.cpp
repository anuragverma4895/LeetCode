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

    int totalpath(TreeNode* root, long long target){
        if(root==NULL) return 0;
        long long count=0;
        if(root->val==target) count++;
        count+=totalpath(root->left,target-root->val);
        count+=totalpath(root->right,target-root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return totalpath(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};