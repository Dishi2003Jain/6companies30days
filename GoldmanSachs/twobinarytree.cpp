class Solution {
public:
    void insert(TreeNode* root , vector<int> &ans){
        if(root==NULL) return;
        if(root->left)  insert(root->left,ans);
        if(root->right)  insert(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vct;
        insert(root1,vct);
        insert(root2,vct);
        sort(vct.begin(),vct.end());
        return vct;
    }
};