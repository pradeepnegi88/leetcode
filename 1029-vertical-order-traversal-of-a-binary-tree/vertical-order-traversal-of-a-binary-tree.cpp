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
#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        unordered_map<int,unordered_map<int,multiset<int>>> m;
        q.push({root,{0,0}});
        int minic = int(1e8);
        int maxic = int(-1e8);
        vector<vector<int>> ans;
        while(!q.empty()){
         auto root = q.front();
         q.pop();
         int col = root.second.first;
         int level = root.second.second;
            if(m.count(col) == 1 && m[col].count(level)==1){
                auto p = m[col][level];
                p.insert(root.first->val);
                m[col][level] = p;
            }
            else{
              m[col][level] =  multiset<int>({root.first->val});
            }
         minic = min(minic,col);
         maxic = max(maxic,col);
         if(root.first->left!=NULL){
          q.push({root.first->left,{col-1,level+1}});
         } 
         if(root.first->right!=NULL){
         q.push({root.first->right,{col+1,level+1}});
         } 
        }
        vector<int> a;
        for(int i=minic;i<=maxic;i++){
            for(int j=0;j<m[i].size();j++){
             a.insert(a.end(),m[i][j].begin(),m[i][j].end());
            }
            cout<<endl;
            ans.push_back(a);
            a.clear();
        }
        return ans;
    }
};