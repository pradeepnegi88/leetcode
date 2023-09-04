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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
void f(TreeNode* root){
    if(root == NULL) return;
    f(root->left);
     if(prev!=NULL && prev->val>root->val){
         if(first == NULL){
             first = prev;
             middle = root;
         }else{
             last  = root;
         }   
     }
     prev = root;
    f(root->right);
}
    void recoverTree(TreeNode* root) {
        f(root);
        if(first && last){
            swap(first->val,last->val);
        }else{
            swap(first->val,middle->val);
        }
    }
};