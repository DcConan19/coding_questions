// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool issafe(int x, int y, int n,int m)
    {
        if (x >= 0 && x <n && y >= 0 && y < m)
        {
            return true;
        }
        return false;
    }
    int minStepToReachTarget(vector<vector<int>> &adj, int x,int y, int n,int m)
    {
        // Code here
        bool vis[n][m];
        memset(vis, false, sizeof(vis));
        // cout<<x<<" "<<y<<endl;
        vector<vector<int>> dis(n, vector<int>(m,-1));
        queue<pair<int, int>> q;
        // cout<<KnightPos[0]<<" "<<KnightPos[1]<<endl;
        if (adj[x][y] == 0){
            return -1;
        }
        q.push({x,y});
        vis[x][y] = 1;
        dis[x][y] = 1;
        int disx[] = {-1, 0, 1, 0};
        int disy[] = {0, 1, 0, -1};
        int ans=-1;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int a = p.first;
            int b = p.second;
            // cout<<x<<" "<<y<<endl;
            // if (x == TargetPos[0] && y == TargetPos[1])
            // {
            //     return dis[x][y];
            // }
            // ans=max(ans,dis[a][b]);
            ans=dis[a][b];
            vis[a][b]=1;
            for (int i = 0; i < 4; i++)
            {
                int u = a + disx[i];
                int v = b + disy[i];
                // cout<<u<<" "<<v<<endl;
                if (issafe(u, v, n,m) && !vis[u][v] && adj[u][v]==1)
                {
                    // cout<<u<<" "<<v<<endl;
                    q.push({u, v});
                    vis[u][v] = 1;
                    dis[u][v] = 1 + dis[a][b];
                }
            }
        }
        return  ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n,m;
        cin >>n>>m;
      vector<vector<int>> adj(n,vector<int>(m)); 
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              cin>>adj[i][j];
          }
      }
      int x,y;
      cin>>x>>y;
      x--;y--;
        Solution obj;
        int ans = obj.minStepToReachTarget(adj,x,y,n,m);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends