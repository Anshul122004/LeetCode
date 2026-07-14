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

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int cnt=0, ans=0;
        while(root){
            if(!root->left){
                cnt++;
                if(cnt==k) ans=root->val;
                root=root->right;
            }
            else{
                TreeNode* prev=root->left;
                while(prev->right!=NULL&&prev->right!=root){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=root;;
                    root=root->left;
                }
                else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt==k) ans=root->val;
                    root=root->right;
                }
                
            }
        }
        return ans;
    }
};