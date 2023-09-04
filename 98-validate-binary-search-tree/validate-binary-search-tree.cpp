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
    bool f(TreeNode* root, long long int min, long long int max){
        if(root == NULL) return true;
        if(root->val<max && root->val>min){
            bool left = true;
            bool right = true;
           left =  f(root->left,min,root->val);
           right = f(root->right,root->val,max);
          return (left && right);
        }else{
           return  false;
        }

    }
    bool isValidBST(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
                long long int min = -1000000000000, max = 1000000000000;

        return f(root,min,max);
    }
};