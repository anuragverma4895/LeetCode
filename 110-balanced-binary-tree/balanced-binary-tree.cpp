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
    // //  TC= O(n^2);
    // int height(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return max(height(root->left),height(root->right))+1;
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root==NULL) return true;
    //     int left_tree=height(root->left);
    //     int right_tree=height(root->right);
    //     if(abs(left_tree-right_tree)>1) return false;
    //     return isBalanced(root->left) && isBalanced(root->right);
    // }


    // other method O(n);
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int left=height(root->left);
        if(left==-1) return -1;
        int right=height(root->right);
        if(right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root){
        return height(root)>=0;
    }
};