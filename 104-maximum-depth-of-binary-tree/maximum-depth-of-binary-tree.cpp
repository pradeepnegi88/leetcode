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
int f(TreeNode* root){
  if(root == NULL){
      return 0;
  }
  int left = 0;
  int right  =0;
  if(root->left!=NULL){
    left = f(root->left);
  }
   if(root->right!=NULL){
    right = f(root->right);
  }
  return 1+max(left,right);
}

int marker(TreeNode* root){
  int count =0;
  if(root == NULL) return count;
  stack<TreeNode*> s;
  s.push(root);
  s.push(NULL);
  while(!s.empty()){
    auto curr = s.top();
    s.pop();
    if(curr!=NULL){
     if(curr->left!=NULL){
       s.push(curr->left);
     }
    if(curr->right!=NULL){
       s.push(curr->right);
     }
    }else{
            count++;

    if(!s.empty()) {
      s.push(NULL);
      }
    }

  }
  return count;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // return f(root);
        // return marker(root);
        if(root == NULL){
            return 0;
        }
        queue<TreeNode*> p;
         p.push(root);
         int count = 0;
         while(!p.empty()){
         int size = p.size();
         for(int i = 0;i<size;i++){
            auto curr = p.front();
            p.pop();
            if(curr->left!=NULL){
                p.push(curr->left);
            }
            if(curr->right!=NULL){
                p.push(curr->right);
            }
         }
            count ++;
        }
        return count;
    }
};