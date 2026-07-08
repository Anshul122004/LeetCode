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
    TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, int start){
        queue<TreeNode*> q;
        q.push({root});
        TreeNode* res = nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                res=node;
            }
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* res=markParent(root, parent, start);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        int time=0;
        q.push({res});
        visited[res]=true;
        while(!q.empty()){
            int size=q.size();
            bool spread=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&!visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                    spread=true;
                }
                if(node->right&&!visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                    spread=true;
                }
                if(parent[node]&&!visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                    spread=true;
                }
            }
            if(spread){
                time++;
            }
        }
        return time;
    }
};