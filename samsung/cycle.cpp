// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int src, vector<bool> &vis, vector<bool> &revis, vector<int> adj[])
    {
        if (!vis[src])
        {
            vis[src] = true;
            revis[src] = true;
            for (int i : adj[src])
            {
                if (!vis[i] && dfs(i, vis, revis, adj))
                    return true;
                else if (revis[i] == true)
                    return true;
            }
        }
        revis[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V, false);
        vector<bool> revis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (dfs(i, vis, revis, adj))
            {
                return true;
            }
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends