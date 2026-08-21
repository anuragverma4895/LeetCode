/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         if (root == NULL)
//             return {};

//         map<int, map<int, multiset<int>>> mp; // map<col , map<row,
//         multiset<node>>> ;
//         // [x][y] = {1,2,3}

//         queue<pair<TreeNode*, pair<int, int>>> q;
//         // Node , {x,y}

//         q.push({root, {0, 0}});

//         while (q.size()) {
//             auto c = q.front();
//             q.pop();
//             TreeNode* c_node = c.first;
//             pair<int, int> c_coor = c.second; // {x,y}

//             mp[c_coor.first][c_coor.second].insert(c_node->val);

//             if (c_node->left != NULL) {
//                 q.push({c_node->left, {c_coor.first - 1, c_coor.second +
//                 1}});
//             }

//             if (c_node->right != NULL) {
//                 q.push({c_node->right, {c_coor.first + 1, c_coor.second +
//                 1}});
//             }
//         }
//         vector<vector<int>> ans;
//         for(auto x : mp){  // x -> int ,  map<int,multiset<int>> ;
//             vector<int> temp;
//             for(auto y : x.second){ // y->int ,  multiset<int>
//                 for(auto z: y.second){
//                     temp.push_back(z);
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };


// // revision
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         if (root == NULL)
//             return {};

//         map<int, map<int, multiset<int>>> nodes;

//         queue<pair<TreeNode*, pair<int, int>>> q;

//         q.push({root, {0, 0}});

//         while (!q.empty()) {
//             auto p = q.front();
//             q.pop();

//             TreeNode* node = p.first;
//             int x = p.second.first;
//             int y = p.second.second;

//             nodes[x][y].insert(node->val);

//             if (node->left) {
//                 q.push({node->left, {x - 1, y + 1}});
//             }

//             if (node->right) {
//                 q.push({node->right, {x + 1, y + 1}});
//             }
//         }

//         vector<vector<int>> ans;

//         for (auto x : nodes) {
//             vector<int> temp;
//             for (auto y : x.second) {
//                 for (auto z : y.second) {
//                     temp.push_back(z);
//                 }
//             }

//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };


// revision
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p=q.front();
                TreeNode* curr=p.first;
                q.pop();
                int x=p.second.first;
                int y=p.second.second;
                nodes[x][y].insert(curr->val);
                if(curr->left) q.push({curr->left,{x-1,y+1}});
                if(curr->right) q.push({curr->right,{x+1,y+1}});
            }
        }
        for(auto x:nodes){
            vector<int>temp;
            for(auto y:x.second){
                for(auto z:y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};
