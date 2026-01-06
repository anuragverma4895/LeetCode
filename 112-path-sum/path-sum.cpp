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
    bool path(TreeNode* root, int target, int sum){
        if(root==NULL) return false;
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==target) return true;
        }
        if(path(root->left,target,sum))return true;;
        if(path(root->right,target,sum))return true;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        return path(root,targetSum,sum);
    }
};