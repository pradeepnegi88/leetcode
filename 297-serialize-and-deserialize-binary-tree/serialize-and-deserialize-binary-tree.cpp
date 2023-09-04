/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto root = q.front();
            q.pop();
            if(root == NULL){
                s.append("#,");
            }else{
                s.append(to_string(root->val)+',');
            }
            if(root!=NULL) {
                q.push(root->left);
            q.push(root->right);

                }
        }
        cout<<s;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        queue<TreeNode*>q;
        stringstream s(data);
        string str;
        getline(s,str,',');
        int a = stoi(str);
        auto root = new TreeNode(a);
        q.push(root);
        while(!q.empty()){
            auto root = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                root->left=NULL;
            }else{
               auto node = new TreeNode(stoi(str));
               q.push(node);
               root->left = node;
            }

            getline(s,str,',');
            if(str == "#"){
                root->right=NULL;
            }else{
               auto node = new TreeNode(stoi(str));
               q.push(node);
               root->right = node;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));