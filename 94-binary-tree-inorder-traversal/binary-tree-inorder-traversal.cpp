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


void inorderf(TreeNode* root,vector<int> &inorder){
    if(root == NULL) return;
    inorderf(root->left,inorder);
    inorder.push_back(root->val);
    inorderf(root->right,inorder);
}


class Solution {
public:
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> inorder;
    //     stack<TreeNode*> s;
    //     //  inorderf(root,inorder);
    //      TreeNode*  curr = root;
    //      while(curr != NULL || !s.empty()){
    //          if(curr!=NULL){
    //              s.push(curr);
    //              curr = curr->left;
    //          }else{
    //              curr = s.top();
    //              s.pop();
    //              inorder.push_back(curr->val);
    //              curr = curr->right;
    //          }
    //      }
    //      return inorder;
    // }

    TreeNode* findExtremeRight(TreeNode* root,TreeNode* curr){
        while(root->right!=NULL && root->right!=curr){
            root = root->right;
        }
        return root;
    }
      //morris approach
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
         TreeNode*  curr = root;
         while(curr != NULL ){
             auto l = curr->left;
             if(l == NULL){
               inorder.push_back(curr->val);
               curr = curr->right;
             }else{
                  auto link = findExtremeRight(l,curr);
                  if(link->right!=curr){
                   link->right = curr;
                   curr = l;
                  }else{
                   link->right=NULL;
                    inorder.push_back(curr->val);

                   curr=curr->right;
                  }
             }
         }
         return inorder;
    }
};