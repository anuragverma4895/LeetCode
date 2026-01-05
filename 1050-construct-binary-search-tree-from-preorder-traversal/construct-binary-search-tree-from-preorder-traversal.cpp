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
    int i=0;

    TreeNode* build(vector<int>&arr, int bound){
        if(i==arr.size() || arr[i]>bound) return NULL;
        TreeNode* root=new TreeNode(arr[i++]);
        root->left=build(arr,root->val);
        root->right=build(arr,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,INT_MAX);
    }
};