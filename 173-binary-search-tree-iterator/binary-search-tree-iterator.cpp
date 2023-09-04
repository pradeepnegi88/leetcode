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
public:

   int inorderTraversal() {
         TreeNode* result=NULL;
         while(curr != NULL || !s.empty()){
             if(curr!=NULL){
                 s.push(curr);
                 curr = curr->left;
             }else{
                 curr = s.top();
                 s.pop();
                 result = curr;
                 curr = curr->right;
                 break;
             }
         }
         return result->val;
    }

    BSTIterator(TreeNode* root) {
      this->curr = root;
    }
    
    int next() {
       return inorderTraversal();
    }
    
    bool hasNext() {
        return curr != NULL || !s.empty();
    }
};
//log n balanced tree (left and right difference less than or equal to 1)
//



/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */