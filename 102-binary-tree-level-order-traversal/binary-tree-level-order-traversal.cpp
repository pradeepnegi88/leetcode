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
 void childQueue(TreeNode* root,queue<TreeNode*> &p,queue<TreeNode*> &c,vector<vector<int>> &ans){
     auto curr = root;
     p.push(curr);
     vector<int> a;   

     while(!p.empty()){
      curr = p.front();
      a.push_back(curr->val);
      p.pop();
      if(curr->left!=NULL){
          c.push(curr->left);
      }
      if(curr->right!=NULL){
          c.push(curr->right);
      }
      if(p.empty()){
          swap(p,c);
          ans.push_back(a);
          a.clear();
      }
     }
 }

  void marker(TreeNode* root,queue<TreeNode*> &p,vector<vector<int>> &ans){
     auto curr = root;
     p.push(curr);
     p.push(NULL);
     vector<int> a;   
     while(!p.empty()){
      curr = p.front();
      p.pop();
      if(curr != NULL){
        a.push_back(curr->val);
        if(curr->left!=NULL){
            p.push(curr->left);
            }
            if(curr->right!=NULL){
            p.push(curr->right);
            }
      }else{
          if(!p.empty()) p.push(NULL);
          ans.push_back(a);
          a.clear();
      }
     }
 }
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> p;
        // queue<TreeNode*> c;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        // childQueue(root,p,c,ans);
        marker(root,p,ans);
        // p.push(root);
        // vector<int> a;
        // while(!p.empty()){
        //  int size = p.size();
        //  for(int i = 0;i<size;i++){
        //     auto curr = p.front();
        //     a.push_back(curr->val);
        //     p.pop();
        //     if(curr->left!=NULL){
        //         p.push(curr->left);
        //     }
        //     if(curr->right!=NULL){
        //         p.push(curr->right);
        //     }
        //  }
        //  ans.push_back(a);
        //  a.clear();
        // }

        return ans;
    }
};