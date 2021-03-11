// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool issafe(int x, int y, int n)
    {
        if (x >= 1 && x <= n && y >= 1 && y <= n)
        {
            return true;
        }
        return false;
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        // Code here
        bool vis[n + 1][n + 1];
        memset(vis, false, sizeof(vis));
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, -1));
        queue<pair<int, int>> q;
        // cout<<KnightPos[0]<<" "<<KnightPos[1]<<endl;
        q.push({KnightPos[0], KnightPos[1]});
        vis[KnightPos[0]][KnightPos[1]] = 1;
        dis[KnightPos[0]][KnightPos[1]] = 0;
        int disx[] = {-1, -1, 1, 1, 2, 2, -2, -2};
        int disy[] = {2, -2, 2, -2, 1, -1, 1, -1};
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            // cout<<x<<" "<<y<<endl;
            if (x == TargetPos[0] && y == TargetPos[1])
            {
                return dis[x][y];
            }
            for (int i = 0; i < 8; i++)
            {
                int u = x + disx[i];
                int v = y + disy[i];
                // cout<<u<<" "<<v<<endl;
                if (issafe(u, v, n) && !vis[u][v])
                {
                    // cout<<u<<" "<<v<<endl;
                    q.push({u, v});
                    vis[u][v] = 1;
                    dis[u][v] = 1 + dis[x][y];
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends