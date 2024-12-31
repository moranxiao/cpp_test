class Solution {
public:
    TreeNode* dfs(TreeNode* root)
    {
        TreeNode* right = root->right;
        TreeNode* rightTail = nullptr,*leftTail = nullptr;
        if(root->right) rightTail = dfs(root->right);
        if(root->left)
        {
            leftTail = dfs(root->left);

            root->right = root->left;
            leftTail->right = right;
            root->left = nullptr;
        }
        if(rightTail) return rightTail;
        else if(leftTail) return leftTail;
        return root;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
    }
};