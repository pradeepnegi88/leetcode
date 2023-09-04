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

    int f(TreeNode* root, int& maxi){
        if(root == NULL) return 0;
        int left = max(0,f(root->left,maxi));
        int right = max(0,f(root->right,maxi));
        maxi = max(maxi,left+right+root->val);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
          stack<TreeNode*> s;
        TreeNode* pre ;
        unordered_map<TreeNode*, int> m; 
        auto curr = root;
        int maxi = -1e9;
        // f(root,maxi);
        // return maxi;
        while(curr != NULL || !s.empty()){
             if(curr!=NULL){
                 s.push(curr);
                 curr = curr->left;
             }else{
                 curr = s.top();
             if(curr->right!=NULL && curr->right!=pre){
                  curr = curr->right;
              }else{
                int left =0;
                int right =0;
                if(m.find(curr->left) != m.end()){ 
                   left =  max(0,m[curr->left]);
                 }
                if(m.find(curr->right) != m.end()){
                   right =   max(0,m[curr->right]);
                 }

                maxi = max(maxi,left+right+curr->val);
                m[curr] = curr->val + max(left, right);                          
                s.pop();
                pre = curr;
                curr = NULL;
              }
             }
         }
         return maxi;
    }
};