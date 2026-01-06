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

    void path(TreeNode* root, int target, vector<int>temp,int sum,vector<vector<int>>&ans){
        if(root==NULL) return;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                ans.push_back(temp);
            }
        }
        path(root->left,target,temp,sum,ans);
        path(root->right,target,temp,sum,ans);
    }    

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        path(root,targetSum,temp,sum,ans);
        return ans;
    }
};