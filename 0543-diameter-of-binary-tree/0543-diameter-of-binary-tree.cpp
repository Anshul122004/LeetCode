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
    int diameter=0;
    int height(TreeNode* root){
        if(!root) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        int len=lh+rh;
        diameter=max(diameter,len);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return diameter;
    }
}; 