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
    bool checkTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int left, right;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                left=0, right=0;
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    left=node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    right=node->right->val;
                    q.push(node->right);
                }
                if((node->left||node->right)&&node->val!=left+right) return false;
            }
        }
        return true;
    }
};