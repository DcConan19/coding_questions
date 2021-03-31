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

vector<ll> arr;
int maxint = 1e9 + 1;
ll rec(ll n, ll sum)
{
    vector<int> dp(sum + 1, maxint);
    dp[0] = 0;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] <= i)
            {
                dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
            }
        }
    }
    return dp[sum] >= maxint ? -1 : dp[sum];
}
void solve()
{
    ll n, sum;
    cin >> n >> sum;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //  for(int i=0;i<=n;i++){
    //      for(int j=0;j<=sum;j++){
    //          dp[i][j]=-1;
    //      }
    //  }
    //  cout<<dp[n][sum]<<endl;
    cout << rec(n, sum);
    //  dp[n][sum]=dp[n][sum]==maxint?-1:dp[n][sum];
    // //  cout << dp[n][sum];
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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