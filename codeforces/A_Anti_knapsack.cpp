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
bool rec(int v[],int n, int k,vector<vector<int>> &dp,vector<int> &ans){
    if(k==0){
        true;
    }
    if(n==0){
        return false;
    }
   if(dp[n][k]!=-1){
       return dp[n][k];
   }

    if(v[n-1]<=k){
        dp[n][k]=rec(v,n-1,k-v[n-1],dp,ans) ||  rec(v,n-1,k,dp,ans);
        if(dp[n][k]==1){
            ans.push_back(v[n-1]);
        }
        return dp[n][k];
    }else{
        dp[n][k]=rec(v,n-1,k,dp,ans);
        // ans.push_back(v[n-1]);
        return dp[n][k];
    }
}
void solve()
{
    int n, k;
    // cout << n << endl;
    cin >> n >> k;
    // trace(n,k);
   vector<int> ans;
    int v[n];
    for(int i=1;i<=n;i++){
         v[i-1]=i;
    }
    vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
    rec(v,n,k,dp,ans);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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