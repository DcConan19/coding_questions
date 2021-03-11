#include <bits/stdc++.h>
using namespace std;
#define ll long long int

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
// unordered_set<int> s;

// function generate all prime number less then N in O(n)
ll bfs(vector<int> adj[], int n, int d, int src)
{
    vector<int> dis(n + 1, -1);
    vector<int> vis(n + 1, 0);
    queue<int> q;
    // int d;
    // cin >> d;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty())
    {
        int v = q.front();
        // cout << v << " ";
        q.pop();
        for (int u : adj[v])
        {
            // if (u == n)
            // {
            // 	cout << dis[v] + 1 << endl;
            // 	return ;
            // }
            if (!vis[u])
            {
                q.push(u);
                vis[u] = 1;
                dis[u] = dis[v] + 1;
            }
        }
    }
    // cout << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << src << ":" << i << " -> " << dis[i] << endl;
        if (dis[i] == d)
        {
            ans++;
        }
    }
    return ans;
}
void solve()
{
    int n, m;
    // cout << n << endl;
    cin >> n >> m;
    cout<<n<<" "<<m<<endl;
    // vector<int> adj[n + 1];
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);
    // }
    // ll q;
    // cin >> q;
    // // cout << q << endl;
    // while (q--)
    // {
    //     int src, d;
    //     cin >> src >> d;
    //     cout << bfs(adj, n, d, src) << endl;
    // }
}
int main()
{
// #ifndef ONLINE_JUDGE
//     // for getting input from input.txt
//     freopen("input.txt", "r", stdin);
//     // for writing output to output.txt
//     freopen("output.txt", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // SieveOfEratosthenes(1000000);
    // seive();
    ll t = 1;
    // cin >> t;
    ll x = 1;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Scenario #" << i << ":" << endl;
        solve();
        // cout << solve() << endl;
    }
    return 0;
}