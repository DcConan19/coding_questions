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
const int INF = 1000000000;

struct Edge
{
    int w = INF, to = -1;
    bool operator<(Edge const &other) const
    {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};

void solve()
{
    int n, m,k;
   cin>>n>>m>>k;
   vector<pair<int,int>> adj[n+1];
//    vector<vector<Edge>> adj;
   for(int i=0;i<m;i++)
   {
       int u,v,wt;
       cin>>u>>v>>wt;
    //    Edge e;
    //    e.w=wt;
    //    e.to=v;
       adj[u].push_back({wt,v});
       adj[v].push_back({wt,u});
   }
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> vis(n+1,0);
   pq.push({0,1});
    // vis[1]=1;
    int total=0;
            while (!pq.empty())
            {
               auto p = pq.top();
                pq.pop();
                int x = p.second;
                // Checking for cycle
                if (vis[x] == true)
                    continue;
                // cout<<x<<" ";
                total += p.first;
                vis[x] = true;
                for (int i = 0; i < adj[x].size(); ++i)
                {
                    int y = adj[x][i].second;
                    if (vis[y] == 0)
                        pq.push(adj[x][i]);
                }
            }
        

   cout << total << endl;
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