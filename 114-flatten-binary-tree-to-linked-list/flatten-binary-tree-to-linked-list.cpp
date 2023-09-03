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
        TreeNode* prev = NULL;

public:
   void f(TreeNode* root){
       if(root == NULL) return;
       f(root->right);
       f(root->left);
       root->right = prev;
       root->left = NULL;
       prev = root;
   }
    void flatten(TreeNode* root) {
            // f(root);    
        //    stack<TreeNode*> s;
        //    if(root == NULL) return;
        //    auto curr = root;
        //     s.push(curr);
        //     while(!s.empty()){
        //         curr = s.top();
        //         s.pop();
        //         if(curr->right!=NULL)
        //         s.push(curr->right);
        //         if(curr->left!=NULL)
        //         s.push(curr->left);
        //         if(!s.empty()){
        //             curr->right = s.top();
        //         }
        //         curr->left = NULL;
        //     }
        auto curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                auto prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    
    }
};