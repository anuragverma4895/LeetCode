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
    int prev = -1e9, cnt = 0, mx = 0;
    vector<int> ans;

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(root->val == prev) cnt++;
        else cnt = 1;
        if(cnt > mx){
            mx = cnt;
            ans.clear();
            ans.push_back(root->val);
        }else if(cnt == mx){
            ans.push_back(root->val);
        }
        prev = root->val;
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};