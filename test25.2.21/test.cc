class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            vector<pair<TreeNode*,unsigned long long>> arr;
            arr.emplace_back(root,1);
            unsigned long long ans = 0;
            while(arr.size())
            {
                vector<pair<TreeNode*,unsigned long long>> tmp;
                for(auto& e : arr)
                {
                    TreeNode* cur = e.first;
                    unsigned long long index = e.second;
                    if(cur->left){
                        tmp.emplace_back(cur->left,index*2);
                    }
                    if(cur->right)
                    {
                        tmp.emplace_back(cur->right,index*2+1);
                    }
                }
                ans = max(ans,arr.back().second - arr[0].second + 1);
                arr = move(tmp);
            }
            return ans;
        }
    };