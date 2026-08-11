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
// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         if(root==NULL) return 0;
//         unsigned long long ans=0;
//         queue<pair<TreeNode*,unsigned long long>>q;
//         q.push({root,0ll});
//         while(q.size()){
//             unsigned long long sz=q.size();
//             unsigned long long left=0;
//             unsigned long long right=0;
//             for(int i=0;i<sz;i++){
//                 TreeNode* curr=q.front().first;
//                 unsigned long long num=q.front().second;
//                 q.pop();
//                 if(i==0) left=num;
//                 if(i==sz-1) right=num;
//                 if(curr->left!=NULL)
//                     q.push({curr->left,2ull*num+1});
//                 if(curr->right!=NULL)
//                     q.push({curr->right,2ull*num+2}); 
//             }
//             ans=max(ans,right-left+1);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0ull});
        int ans=0;
        while(q.size()){
            unsigned long long sz=q.size();
            unsigned long long first=0;
            unsigned long long last=0;
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front().first;
                unsigned long long index=q.front().second;
                q.pop();
                if(i==0) first=index;
                if(i==sz-1) last=index;
                if(curr->left) q.push({curr->left,2ull*index+1});
                if(curr->right) q.push({curr->right,2ull*index+2});
            }
            ans=max(ans,int(last-first+1));
        }
        return ans;
    }
};




























