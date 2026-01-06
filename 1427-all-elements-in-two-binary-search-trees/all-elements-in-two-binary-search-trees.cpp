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
    vector<int>ans;
    void root1element(TreeNode* root1){
        if(root1==NULL) return;
        ans.push_back(root1->val);
        root1element(root1->left);
        root1element(root1->right);
    }
    void root2element(TreeNode* root2){
        if(root2==NULL) return;
        ans.push_back(root2->val);
        root2element(root2->left);
        root2element(root2->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        root1element(root1);
        root2element(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};