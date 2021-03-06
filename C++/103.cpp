/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> v;
        vector<vector<int>> res;
        if(root == NULL) return res;
        v.push_back(root);
        bool order = false;
        while(!v.empty())
        {
            vector<TreeNode*> tem_v;
            vector<int> output;
            for(auto it : v)
            {
                output.push_back(it->val);
                if(it->left != NULL)
                    tem_v.push_back(it->left);
                if(it->right != NULL)
                    tem_v.push_back(it->right);
            }
            if(order) reverse(output.begin(), output.end());
            order = !order;
            res.push_back(output);
            v = tem_v;
        }
        return res;
    }
};