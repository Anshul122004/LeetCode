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
    TreeNode* structTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart,int inEnd, map<int,int>& inmap){
        if(preStart>preEnd||inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inroot=inmap[root->val];
        int numLeft=inroot-inStart;
        root->left=structTree(preorder, preStart+1, preStart+numLeft, inorder, inStart, inroot-1,inmap);
        root->right=structTree(preorder, preStart+numLeft+1 ,preEnd, inorder, inroot+1, inEnd,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        for(int i=0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        TreeNode* root=structTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1,inmap);
        return root;
    }
};