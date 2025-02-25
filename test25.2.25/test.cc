class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            queue<int> q;
            vector<int> d(numCourses,0);
            vector<vector<int>> edge(numCourses);
            for(auto& e : prerequisites)
            {
                d[e[0]]++;
                edge[e[1]].push_back(e[0]);
            }
            for(size_t i = 0; i < numCourses; i++)
            {
                if(d[i] == 0) q.push(i);
            }
            int count = 0;
            while(q.size())
            {
                count++;
                int t = q.front();
                q.pop();
                for(auto e : edge[t])
                {
                    d[e]--;
                    if(d[e] == 0) q.push(e);
                }
            } 
            if(count == numCourses) return true;
            return false;
        }
    };