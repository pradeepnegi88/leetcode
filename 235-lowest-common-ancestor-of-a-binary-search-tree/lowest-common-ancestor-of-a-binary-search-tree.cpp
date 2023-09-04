/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {


public:

TreeNode* f1(TreeNode* root, TreeNode* p, TreeNode* q){
  if(root == NULL || root->val ==p->val || root->val ==q->val){
      return root;
  }
 

  auto l = f1(root->left,p,q);
  auto r = f1(root->right,p,q);
  if(l == NULL && r == NULL){
      return NULL;
  }else if(l==NULL && r!=NULL){
      return r;
  }else if(l!=NULL && r==NULL){
       return l;
  }else{
      return root;
  }

}
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f1(root,p,q);
    }
};