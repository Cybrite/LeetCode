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

    TreeNode* build(vector<int>& preorder, int preStart, int inStart, int inEnd){
        if(inStart > inEnd) return NULL;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderMap[rootVal];
        int leftSize = mid - inStart;

        root->left = build(preorder, preStart+1, inStart, mid-1);
        root->right = build(preorder, preStart + leftSize + 1, mid + 1, inEnd);

        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return build(preorder, 0, 0, inorder.size()-1);
    }
};