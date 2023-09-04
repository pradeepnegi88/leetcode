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
bool f(TreeNode* p,TreeNode* q){
       if(p == NULL || q==NULL){
           return p==q;
       }
       if(p->val == q->val){
          if(!f(p->left,q->left)) return false;
          if(!f(p->right,q->right)) return false;
       }else{
           return false;
       }
    return true;
} 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //  return f(p,q);
        stack<TreeNode*> s;
      if(p == NULL && q == NULL) return true;

       if (p == NULL || q == NULL || p->val != q->val) 
       return false;


         while(p != NULL || !s.empty() || q!=NULL){
             if(p!=NULL && q!=NULL){
                if(p->val != q->val) return false;

                 s.push(p);
                 s.push(q);
               if ((p->left == NULL || q->left == NULL) && (p->left != q->left)) 
                return false;

                 p = p->left;
                 q = q->left;
            
             }else{
                 p = s.top();
                 s.pop();

                 q = s.top();
                  s.pop();

                if(p->val != q->val) return false;
              if ((p->right == NULL || q->right == NULL) && (p->right != q->right)) 
              return false;

                 p = p->right;
                 q = q->right;
             }
         }
         return true;
    }
};