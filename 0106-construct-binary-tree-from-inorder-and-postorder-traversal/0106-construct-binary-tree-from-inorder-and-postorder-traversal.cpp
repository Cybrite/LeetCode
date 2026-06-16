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
    unordered_map<int,int> inorderMap;

    TreeNode* build(vector<int>& postorder, int postEnd, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];
        int rightSize = inEnd - mid;

        root->left = build(postorder, postEnd - rightSize - 1, inStart, mid-1);
        root->right = build(postorder, postEnd - 1, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return build(postorder, postorder.size()-1, 0, inorder.size()-1);
    }
};