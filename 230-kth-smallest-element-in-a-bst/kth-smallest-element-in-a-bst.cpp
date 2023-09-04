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
    int kthSmallest(TreeNode* root, int k) {
        
        int count = 0;
        stack<TreeNode*> s;
        auto curr = root;
        s.push(curr);
        while(!s.empty()){
            if(curr!=NULL){
               s.push(curr);
               curr = curr->left;
            }else{
               count = count+1;
               curr = s.top();
               s.pop();
               if(count==k) break;
               curr = curr->right;
            }
        }
        return curr->val;
    }
};