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

 #include <bits/stdc++.h>
class Solution {
public:
    // vector<int> preorderTraversal(TreeNode* root) {
    //    // Write your code here.
    // stack<pair<TreeNode*, int>> s;
    // vector<int> pre;
    // vector<int> inorder;
    // vector<int> post;
    // if(root == NULL) return pre;
    // s.push({root, 0});
    // while (!s.empty()) {
    //     auto &curr = s.top();
    //     int &state = curr.second;
    //     if (state == 0) {
    //         pre.push_back(curr.first->val);
    //         state++;
    //         if (curr.first->left != NULL) {
    //             s.push({curr.first->left, 0});
    //         }
    //     } else if (state == 1) {
    //         inorder.push_back(curr.first->val);
    //         state++;
    //         if (curr.first->right != NULL) {
    //             s.push({curr.first->right, 0});
    //         }
    //     } else {
    //         post.push_back(curr.first->val);
    //         s.pop();
    //     }
    // }
    // return pre;
    // }
// void  preorder(TreeNode* root, vector<int> &pre)  {
//     if(root == NULL) return;
//     pre.push_back(root->val);
//     preorder( root->left,pre);
//     preorder(root->right,pre);
// } 

vector<int> preorderTraversal(TreeNode* root) {
       // Write your code here.
    vector<int> pre;
    stack<TreeNode*> s;
    // preorder(root,pre);

    auto curr = root;
    while( curr != NULL || !s.empty()){
        if(curr!=NULL){
         s.push(curr);
         pre.push_back(curr->val);
         curr = curr->left;
        }else{
           curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }
    return pre;
    }
};

