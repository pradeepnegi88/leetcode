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

bool f(TreeNode* root, TreeNode* p,vector<TreeNode*> &a){
    if(root == NULL){
        return false;
    }
    a.push_back(root);
    if(root->val == p->val){
        return true;
    }
    bool l = f(root->left,p,a);
    bool r = f(root->right,p,a);
    if(l || r){
        return true;
    }else{
        a.pop_back();
        return false;
    }
}   

TreeNode* f1(TreeNode* root, TreeNode* p, TreeNode* q,bool &pf,bool &qf){
  if(root == NULL ){
      return NULL;
  }
  if( root->val ==p->val){
      pf = true;
      return root;
  }  
  if( root->val ==q->val){
      qf = true;
      return root;
  } 
 

  auto l = f1(root->left,p,q,pf,qf);
  auto r = f1(root->right,p,q,pf,qf);
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


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<TreeNode*> a;
        // vector<TreeNode*> b;
        // f(root,p,a);
        // f(root,q,b);
    
        // int asize = a.size();
        // int bsize = b.size();
        // int mini = min(asize,bsize);
        // TreeNode* prevMatched = 0;
        // for(int i=0;i<mini;i++){
        // if(a[i] == b[i]){
        //     prevMatched = a[i];
        // }
        // }
        // return prevMatched;
        bool pf,qf;
        TreeNode* ans =  f1(root,  p, q,pf,qf);
        if(pf && qf){
            return ans;
        }else{
            return NULL;
        }
    }
};