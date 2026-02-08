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
   int height(TreeNode* root,bool &valid){
    if(root==NULL) return 0;

    int left=height(root->left,valid);
    int right=height(root->right,valid);

    if(abs(right-left)>1) valid=false;
     
     return 1+max(left,right);
   }
    bool isBalanced(TreeNode* root) {
        bool valid=true;
        height(root,valid);
        return valid;
    }
};