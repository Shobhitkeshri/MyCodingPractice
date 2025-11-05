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
    void path(TreeNode* root,int targetSum, vector<int> &singleArr,vector<vector<int>> &ans){
        if(root==NULL)return ;
        
        singleArr.push_back(root->val);
        targetSum-=root->val;

        if(root->left==NULL && root->right==NULL){
            if(targetSum==0){
                ans.push_back(singleArr);
            }
        }
        else{
            path(root->left,targetSum,singleArr,ans);
            path(root->right,targetSum,singleArr,ans);
        }
        singleArr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> singleArr;
        path(root,targetSum,singleArr,ans);
        return ans;
    }
};