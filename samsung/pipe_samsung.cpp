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
void bfs(vector<vector<int>> &arr, int n, int m, int x, int y, int l)
{
    vector<vector<int>> vis(n, std::vector<int>(m, 0));
    vector<vector<int>> dis(n, std::vector<int>(m, 21));
    queue<pair<int, pair<int, int>>> q;
    // int d;
    // cin >> d;
    q.push({x, {y, 1}});
    vis[x][y] = 1;
    dis[x][y] = 1;
    // vis[src] = 1;
    // dis[src] = 0;
    while (!q.empty())
    {
        auto temp = q.front();
        // cout << v << " ";
        q.pop();
        int a = temp.first;
        int b = temp.second.first;
        int d = temp.second.second;
        if (arr[a][b] == 1 || arr[a][b] == 2 || arr[a][b] == 4 || arr[a][b] == 7)
        {
            if (a - 1 >= 0 && a < n && b >= 0 && b < m && vis[a - 1][b] == 0 && (arr[a - 1][b] == 1 || arr[a - 1][b] == 3 || arr[a - 1][b] == 6 || arr[a - 1][b] == 7))
            {
                q.push({a - 1, {b, d + 1}});
                vis[a - 1][b] = 1;
                dis[a - 1][b] = d + 1;
            }
        }
        if (arr[a][b] == 1 || arr[a][b] == 3 || arr[a][b] == 4 || arr[a][b] == 5)
        {
            if (a >= 0 && a < n && b + 1 >= 0 && b + 1 < m && vis[a][b + 1] == 0 && (arr[a][b + 1] == 1 || arr[a][b + 1] == 3 || arr[a][b + 1] == 6 || arr[a][b + 1] == 7))
            {
                q.push({a, {b + 1, d + 1}});
                vis[a][b + 1] = 1;
                dis[a][b + 1] = d + 1;
            }
        }
        if (arr[a][b] == 1 || arr[a][b] == 2 || arr[a][b] == 6 || arr[a][b] == 5)
        {
            if (a + 1 >= 0 && a + 1 < n && b >= 0 && b < m && vis[a + 1][b] == 0 && (arr[a + 1][b] == 1 || arr[a + 1][b] == 3 || arr[a + 1][b] == 6 || arr[a + 1][b] == 7))
            {
                q.push({a + 1, {b, d + 1}});
                vis[a + 1][b] = 1;
                dis[a + 1][b] = d + 1;
            }
        }
        if (arr[a][b] == 1 || arr[a][b] == 3 || arr[a][b] == 7 || arr[a][b] == 6)
        {
            if (a >= 0 && a < n && b - 1 >= 0 && b - 1 < m && vis[a][b - 1] == 0 && (arr[a][b - 1] == 1 || arr[a][b - 1] == 3 || arr[a][b - 1] == 6 || arr[a][b - 1] == 7))
            {
                q.push({a, {b - 1, d + 1}});
                vis[a][b - 1] = 1;
                dis[a][b - 1] = d + 1;
            }
        }
    }
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] <= l)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
void solve()
{
    int n, m, x, y, l;
    // cout << n << endl;
    cin >> n >> m >> x >> y >> l;
    vector<vector<int>> arr(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
   if(arr[x][y]==0)
   {
       cout<<0<<endl;
       return;
   }
    bfs(arr, n, m, x, y, l);
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // 	freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // 	freopen("output.txt", "w", stdout);
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