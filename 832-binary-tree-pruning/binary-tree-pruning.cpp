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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        // if(root->left && root->left->val==0){
        //     root->left=NULL;
        // }
        // }else if(root->right && root->right->val==0){
        //     root->right=NULL;
        // }
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(root->left && root->left->val==0 && root->left->left==NULL && root->left->right==NULL){
            root->left=NULL;
        }
        if(root->right && root->right->val==0 && root->right->left==NULL && root->right->right==NULL){
            root->right=NULL;
        }
        if(root->val==0 && root->left==NULL && root->right==NULL)
            return NULL;
        return root;
    }
};