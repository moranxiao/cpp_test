//A*算法一定要保证有解，才能加快搜索速度，否则会降低速度
/*
步骤：
1.判断是否有解
2.无解则开始进行A*算法
*/
#include <iostream>
#include <cstring>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int g[3][3];
unordered_map<string,pair<string,char>> path;

int distance(string s)
{
    int res = 0;
    for(int i = 0; i < 8; i++)
    {
        if(s[i] == 'x') continue;
        int t = s[i] - '1';
        res += t/3 - i/3 + t%3 - i%3;
    }
    return res;
}
// pair<int,pair<string,int>>

void astar(const string& start,const string& end)
{
    int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
    char move[] = "urdl";
    
    priority_queue<pair<int,pair<string,int>>, \
    vector<pair<int,pair<string,int>>> , \
    greater<pair<int,pair<string,int>>> > heap;
    
    heap.push({-1,{start,0}});
    path[start];
    
    while(!heap.empty())
    {
        string s = heap.top().second.first;
        int d = heap.top().second.second;
        heap.pop();
        int t = s.find('x');
        int x = t/3, y = t%3;
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a > 2 || a < 0 || b > 2 || b < 0) continue;
            string tmp = s;
            swap(tmp[a*3+b],tmp[t]);
            if(path.count(tmp)) continue;
            path[tmp] = {s,move[i]};
            if(tmp == end) return;
            int dist = d + 1 + distance(tmp);
            heap.push({dist,{tmp,d+1}});
        }
    }
}

int main()
{
    string start,s;
    for(int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
        if(c != 'x')
            s += c;
    }
    int counter = 0;
    for(int i = 0; i < 8; i++)
    {
        for(int j = i; j < 8; j++)
        {
            if(s[i] > s[j])
                counter++;
        }
    }
    if(counter & 1) cout << "unsolvable" << endl;
    else
    {
        string end = "12345678x";
        astar(start,end);
        string res;
        while(start != end)
        {
            res += path[end].second;
            end = path[end].first;
        }
        reverse(res.begin(),res.end());
        cout << res << endl;
    }
    return 0;
}