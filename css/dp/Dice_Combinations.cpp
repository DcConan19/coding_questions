#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : " << arg1 << endl;
    //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
// unordered_set<int> s;
int mod=1e9+7;
int size=1e6+1;
vector<int> dp;
int rec(ll n){
    if(n<0 ){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    ll sum=0;
    for(int i=1;i<=6;i++){
        // if(n-i > 6 ){
        //     dp[n]=0;
        //     continue;
        // }
        sum=(sum+rec(n-i))%mod;
    }
    dp[n]=sum%mod;
    return dp[n];
}
void solve()
{
    ll n;
    cin>>n;
    dp.assign(n+1,-1);
    
    cout<<rec(n)<<endl;
//     for (int i = 1; i <= n; i++)
//     {
//         trace(i, dp[i]);
//     }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1 ;
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