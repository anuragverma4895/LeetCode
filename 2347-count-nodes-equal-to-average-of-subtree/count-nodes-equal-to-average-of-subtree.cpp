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
    int countofnode(TreeNode* root){
        if(root==NULL) return 0;
        return 1+countofnode(root->left)+countofnode(root->right);
    }
    int sumofnode(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+sumofnode(root->left)+sumofnode(root->right);
    }
    int count=0;
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL) return 0;
        int sum = sumofnode(root);
        int tcount=countofnode(root);
        int a=sum/tcount;
        if(a==root->val){
            count++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return count;

    }
};