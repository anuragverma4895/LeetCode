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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};