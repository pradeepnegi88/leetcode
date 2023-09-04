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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,double>>q;
        q.push({root,0});
        double maxi=0;

        while(!q.empty()){
           int size = q.size();
           double f=0;
           double l=0;
           for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();
                auto root = p.first;
                auto index = p.second-1;
                if(i == 0){
                    f = index;
                }
                if(i == size-1){
                    l = index;
                }
                if(root->left!=NULL){
                    q.push({root->left,(double)2*index+1});
                }
                if(root->right!=NULL){
                    q.push({root->right,(double)2*index+2});
                }
           }
         maxi = (int)max(maxi,l-f+1);

        }
    return (int)maxi;
 
    }
};