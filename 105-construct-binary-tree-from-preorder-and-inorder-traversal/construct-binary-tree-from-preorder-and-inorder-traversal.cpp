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
 TreeNode* f(vector<int>& preorder, vector<int>& inorder,map<int,int> &m, int sp,int ep,int si,int ei) 
  {
      if(sp>ep || si>ei) return NULL;
      int startingPre = preorder[sp];
      int rootInorder =  m[startingPre];
      auto root = new TreeNode(startingPre);
      root->left = f(preorder,inorder,m,sp+1,sp+rootInorder-si,si,rootInorder-1);
      root->right = f(preorder,inorder,m,sp+rootInorder+1-si,ep,rootInorder+1,ei);
      return root;
  }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        buildMappedIndex(inorder,m);
        auto root = f(preorder,inorder,m,0,preorder.size()-1,0,inorder.size()-1);
        return root;
  
}
};