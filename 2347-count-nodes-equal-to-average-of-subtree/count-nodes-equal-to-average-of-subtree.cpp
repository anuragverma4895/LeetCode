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

    // // method 01, TC= O(n^2)
    // int countofnode(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return 1+countofnode(root->left)+countofnode(root->right);
    // }
    // int sumofnode(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return root->val+sumofnode(root->left)+sumofnode(root->right);
    // }
    // int count=0;
    // int averageOfSubtree(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int sum = sumofnode(root);
    //     int tcount=countofnode(root);
    //     int a=sum/tcount;
    //     if(a==root->val){
    //         count++;
    //     }
    //     averageOfSubtree(root->left);
    //     averageOfSubtree(root->right);
    //     return count;
    // }

    // method 02, TC=O(n)
    int ans=0;
    pair<int,int>dfs(TreeNode* root){
        if(root==NULL) return {0,0};
        auto l=dfs(root->left);
        auto r=dfs(root->right);
        int sum=root->val+l.first+r.first;
        int count=1+l.second+r.second;
        if(sum/count==root->val){
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root){
        dfs(root);
        return ans;
    }
};