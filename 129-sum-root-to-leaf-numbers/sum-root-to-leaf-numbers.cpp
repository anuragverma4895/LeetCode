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
    void sumpath(TreeNode* root, string s, int &sum){
        if(root==NULL) return;
        s+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=stoi(s);
        }
        sumpath(root->left,s,sum);
        sumpath(root->right,s,sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        string s="";
        sumpath(root,s,sum);
        return sum;
    }
};