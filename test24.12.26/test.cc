class Solution {
public:
    priority_queue<int> heap;
    void dfs(TreeNode* root,int k)
    {
        if(root == nullptr) return;
        heap.push(root->val);
        if(heap.size() > k) heap.pop();
        kthSmallest(root->left,k);
        kthSmallest(root->right,k);

    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return heap.top();
    }
};