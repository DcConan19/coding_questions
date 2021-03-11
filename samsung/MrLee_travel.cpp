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
int ans=INT_MAX;
int n;
vector<vector<int>> adj(12,vector<int>(12));
vector<bool> vis(12,0);
void dfs(int cityCount, int currentCity, int costTillNow)
{

    if ((cityCount == n) && adj[currentCity][0] != 0)
    {
        if (ans > costTillNow + adj[currentCity][0])
        {
            ans = costTillNow + adj[currentCity][0];
            return;
        }
    }

    for (int i = 0; i < n ; i++)
    {
        if (!vis[i] && adj[currentCity][i] != 0)
        {
            vis[i] = true;
            dfs(cityCount + 1, i, costTillNow + adj[currentCity][i]);
            vis[i] = false;
        }
    }
}
void solve()
{

    cin>>n;
    vis.clear();
    adj.clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>adj[i][j];
        }
    }
    vis[0] = true;
    dfs(1, 0, 0);

    cout<<ans<<endl;
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
    cin >> t;
    ll x = 1;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Scenario #" << i << ":" << endl;
        solve();
        // cout << solve() << endl;
    }
    return 0;
}