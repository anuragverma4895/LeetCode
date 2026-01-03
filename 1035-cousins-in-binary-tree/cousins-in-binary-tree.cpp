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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            bool fx=false,fy=false;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->val==x) fx=true;
                if(curr->val==y) fy=true;
                if(curr->left && curr->right){
                    int a=curr->left->val;
                    int b=curr->right->val;
                    if((a==x && b==y)||(a==y && b==x)){
                        return false;
                    }
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(fx && fy) return true;
            if(fx || fy) return false;
        }
        return false;
    }
};