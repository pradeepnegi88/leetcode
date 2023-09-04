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
public:
void buildMappedIndex( vector<int>& inorder,map<int,int> &m){
        int size = inorder.size();
        for(int i=0;i<size;i++){
            m[inorder[i]]=i;
        }
    }
TreeNode* f(vector<int>& postorder, vector<int>& inorder,map<int,int> &m, int sp,int ep, int si,int ei) 
  {
      if(sp>ep || si>ei) return NULL;
      int startingPre = postorder[ep];
      int rootInorder =  m[startingPre];
      cout<<startingPre<<"Post"<<endl;
      auto root = new TreeNode(startingPre);
      root->left = f(postorder,inorder,m,sp,rootInorder-si+sp-1,si,rootInorder-1);
      root->right = f(postorder,inorder,m,rootInorder+sp-si,ep-1,rootInorder+1,ei);
      return root;
  }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
          map<int,int> m;
        buildMappedIndex(inorder,m);
        auto root = f(postorder,inorder,m,0,postorder.size()-1,0,inorder.size()-1);
        return root;
    }
};