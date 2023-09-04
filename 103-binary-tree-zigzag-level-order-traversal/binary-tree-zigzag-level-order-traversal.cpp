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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        bool isLeftToRight = false;
        vector<int> level;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*>s;
        s.push(root);
        s.push(NULL);
        while(!s.empty()){
           root = s.front();
           s.pop();
           if(root!=NULL){
            level.push_back(root->val);  
            if(root->left)   
            s.push(root->left);
            if(root->right)
            s.push(root->right);
           }else{
               if(!s.empty()) s.push(NULL);
               if(isLeftToRight){
                   reverse(level.begin(),level.end());
                   }
               ans.push_back(level);
               isLeftToRight = !isLeftToRight;

               level.clear();
           }

        }
        return ans;
        
    }
};