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
    void f(TreeNode* root,vector<int>& q,int level){
        if(root == NULL) return;
        if(q.size() == level)
           q.push_back(root->val);
        f(root->right,q,level+1);
        f(root->left,q,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        // vector<int>q;
        // f(root,q,0);
        // return q;
         vector<int> ans; 
    map<int,int>m;
    queue<pair<TreeNode *,int>>q;
    if(root ==NULL)return ans;
    q.push({root,0});
    while(!q.empty()){
        auto root = q.front();
        q.pop();
        int col = root.second;
         m[col] = root.first->val;
      
        if(root.first->left!=NULL){
                q.push({root.first->left,col+1});
        }
         
            if(root.first->right!=NULL){
                q.push({root.first->right,col+1});
        }
    }
    for(auto it:m){
        ans.push_back(m[it.first]);
    }
return ans;
    }
};