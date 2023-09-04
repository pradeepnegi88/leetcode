/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void linkParentEachNode(TreeNode* root,unordered_map<TreeNode* ,TreeNode*> &m){
   queue<TreeNode*>q;
   q.push(root);
   while(!q.empty()){
     auto root = q.front();
     q.pop();
     if(root->left) {
         m[root->left] = root;
         q.push(root->left);
     }
      if(root->right) {
         m[root->right]=root;
         q.push(root->right);
     }
   }
}
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode* ,TreeNode* > m;
//         linkParentEachNode(root,m);
//         unordered_map<TreeNode* ,bool> visited;
//         queue<TreeNode*>q;
//         q.push(target);
//         visited[target] = true;
//         int level = 0;
//         while(!q.empty()){
//               if(level++ == k) break;
//               int size = q.size();
//               for(int i=0;i<size;i++){
//                 auto root = q.front();
//                 q.pop();
//                 if(root->left && !visited[root->left]) {
//                     q.push(root->left);
//                     visited[root->left] = true;

//                 }
//                 if(root->right && !visited[root->right]) {
//                     q.push(root->right);
//                     visited[root->right] = true;

//                 }
//                  if(m[root] && !visited[m[root]]) {
//                      q.push(m[root]);
//                      visited[m[root]] = true;
//                 }

//               }
//         }
//         vector<int> a;
//         while(!q.empty()){
//             auto z = q.front();
//             q.pop();
//             a.push_back(z->val);
//         }
//   return a;
//     }

void down(TreeNode* root, TreeNode* target,vector<int> &ans,int k){
    if(root == NULL || k<0 || root == target) return;
    if(k==0){
        ans.push_back(root->val);
    }
    down(root->left,target,ans,k-1);
    down(root->right,target,ans,k-1);
}

int findUpper(TreeNode* root, TreeNode* target,vector<int> &ans,int k){
    if(root == NULL) return -1;

     if(root->val == target->val){
         down(root,NULL,ans,k);
         return 1;
     } 

     int left =findUpper(root->left,target,ans,k);
     if(left!=-1){
        down(root,root->left,ans,k-left);
        return left+1;
     }
     int right =findUpper(root->right,target,ans,k);
       if(right!=-1){
        down(root,root->right,ans,k-right);
        return right+1;
     }
     return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    vector<int> ans;
findUpper(root,target,ans,k);
return ans;
}
};
