class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root) q.push(root);
        while(q.size())
        {
            int curNum = q.size();
            res.push_back({});
            for(int i = 0; i < curNum; i++)
            {
                auto node = q.front();
                res.back().push_back(node->val); q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
        }
        return res;
    }
};