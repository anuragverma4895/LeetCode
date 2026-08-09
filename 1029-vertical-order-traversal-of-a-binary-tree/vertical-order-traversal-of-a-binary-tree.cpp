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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (root == NULL)
            return {};

        map<int, map<int, multiset<int>>> mp; // map<col , map<row, multiset<node>>> ;
        // [x][y] = {1,2,3}

        queue<pair<TreeNode*, pair<int, int>>> q;
        // Node , {x,y}

        q.push({root, {0, 0}});

        while (q.size()) {
            auto c = q.front();
            q.pop();
            TreeNode* c_node = c.first;
            pair<int, int> c_coor = c.second; // {x,y}

            mp[c_coor.first][c_coor.second].insert(c_node->val);

            if (c_node->left != NULL) {
                q.push({c_node->left, {c_coor.first - 1, c_coor.second + 1}});
            }

            if (c_node->right != NULL) {
                q.push({c_node->right, {c_coor.first + 1, c_coor.second + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto x : mp){  // x -> int ,  map<int,multiset<int>> ;
            vector<int> temp;
            for(auto y : x.second){ // y->int ,  multiset<int>
                for(auto z: y.second){
                    temp.push_back(z);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};