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
 bool f(TreeNode* l,TreeNode* r){
     if(r ==NULL||l==NULL){
         return r==l;
     }
     if(r->val != l->val){
         return false;
     }
     int lt =  f(l->left,r->right);
     int rt = f(l->right,r->left);
     return (lt && rt);
 }   
public:
    bool isSymmetric(TreeNode* root) {
        return f(root->left,root->right);
    }
};