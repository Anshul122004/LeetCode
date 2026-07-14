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
    bool isValidBST(TreeNode* root) {
        return inordercheckBST(root);
    }
    long long prev=LONG_MIN;
    bool inordercheckBST(TreeNode* root){
        if(!root) return true;
        if(!inordercheckBST(root->left)) return false;
        if(root->val<=prev) return false;
        prev=root->val;
        return inordercheckBST(root->right);
    }
};