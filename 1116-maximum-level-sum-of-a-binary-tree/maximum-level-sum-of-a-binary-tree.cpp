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
    int maxLevelSum(TreeNode* root) {
        int level=0;
        int finallev=0;
        int result=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<int>ans;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                ans.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
            long sum=accumulate(ans.begin(), ans.end(), 0);
            if(result<sum){
                result=sum;
                finallev=level;
                
            }
        }
        return finallev;
    }
};