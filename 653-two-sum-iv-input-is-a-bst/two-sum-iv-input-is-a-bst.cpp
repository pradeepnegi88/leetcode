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
class BSTIterator {
    TreeNode* curr;
    stack<TreeNode*> s;
    bool isReverseInorder = false;
public:

   int inorderTraversal() {
         TreeNode* result=NULL;
         while(curr != NULL || !s.empty()){ 
             if(curr!=NULL){
                 s.push(curr);
                 if(isReverseInorder){
                 curr = curr->right;
                 }else{
                 curr = curr->left;
                 }
             }else{
                 curr = s.top();
                 s.pop();
                 result = curr;
                 if(isReverseInorder){
                 curr = curr->left;
                 }else{
                 curr = curr->right;
                 }
                 break;
             }
         }
         
         return result->val;
   }
    

    BSTIterator(TreeNode* root,bool isReverse) {
      this->curr = root;
      this->isReverseInorder = isReverse;
    }
    
    int next() {
       return inorderTraversal();
    }
    
    bool hasNext() {
        return curr != NULL || !s.empty();
    }
   
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        auto left = BSTIterator(root,false);
        auto right = BSTIterator(root,true);
        int l = left.next();
        int r = right.next();
       while(l<r){
            if(l+r == k){
                return true;
            }
            if(l+r<k){
           l =left.next();
            }else{
           r = right.next();
            }
    
       }
       return false;
        
    }
};