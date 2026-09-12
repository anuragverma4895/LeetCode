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
// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root==NULL) return;
//         flatten(root->left);
//         flatten(root->right);
//         TreeNode* p=root->right;
//         root->right=root->left;
//         root->left=NULL;

//         TreeNode* curr=root;
//         while(curr->right){
//             curr=curr->right;
//         }
//         curr->right=p;
//     }
// };


class Solution {
public:
    void build(TreeNode* root, TreeNode*&prev){
        if(root==NULL) return;
        build(root->right,prev);
        build(root->left,prev);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    void flatten(TreeNode* root){
        TreeNode* prev=NULL;
        build(root,prev);
    }
};