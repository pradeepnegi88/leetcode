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

int f(TreeNode* root,int &maxi){
    if(root == NULL) return 0;
    int left = f(root->left,maxi);
    int right = f(root->right,maxi);
    maxi = max(maxi,left+right);
    return 1+max(left,right);
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre ;
        unordered_map<TreeNode*, int> m; 
        auto curr = root;
        int maxi = 0;
                 f(root,maxi);

        // while(curr != NULL || !s.empty()){
        //      if(curr!=NULL){
        //          s.push(curr);
        //          curr = curr->left;
        //      }else{
        //          curr = s.top();
        

        //      if(curr->right!=NULL && curr->right!=pre){
        //           curr = curr->right;
        //       }else{
        //            int left =0;
        //          int right =0;
        //          if(m.find(curr->left) != m.end()){ 
        //            left =  m[curr->left];
        //              }
        //           if(m.find(curr->right) != m.end()){
        //            right =   m[curr->right];
        //            }

        //             maxi = max(maxi,left+right);
        //             m[curr] = 1 + max(left, right);                          
        //              s.pop();
        //           pre = curr;
        //           curr = NULL;
        //       }
        //      }
        //  }
        return maxi;
    }
};