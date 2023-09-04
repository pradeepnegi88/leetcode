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
 TreeNode* f(vector<int>& preorder,int &index, int m){
     if(index==preorder.size() || preorder[index]>m) return NULL;
        auto root = new TreeNode(preorder[index]);
        index = index+1;
        root->left = f(preorder,index,root->val);
        root->right = f(preorder,index,m);
        return root;
     }

 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return f(preorder,index,INT_MAX);
    }
};