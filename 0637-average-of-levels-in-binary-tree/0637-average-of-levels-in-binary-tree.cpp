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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};

        vector<double> res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            double lsum = 0;
            int lsize = q.size();

            for(int i=0; i<lsize; i++){
                TreeNode* temp = q.front();
                q.pop();

                lsum += temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            res.push_back(lsum/lsize);
        }

        return res;
    }
};