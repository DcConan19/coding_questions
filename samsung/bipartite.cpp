// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isBipartite(int n, vector<int> adj[])
    {
        // Code here
        vector<int> vis(n, 0);
        vector<int> col(n, -1);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                col[i] = 0;
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    for (int it : adj[u])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                            col[it] = 1 ^ col[u];
                        }
                        else
                        {
                            if (col[it] == col[u])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (col[i] == 0)
            {
                cout << i << " ";
            }
        }
        cout << endl;
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends