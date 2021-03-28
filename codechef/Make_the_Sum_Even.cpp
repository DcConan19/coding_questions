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
int ans;

void solve()
{
    ll n ;
    cin>>n;
    vector<int> arr(n);
    ll ne=0,no=0;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] %2==1 ){
            no++;
            no=no%2;
        }else if(arr[i]==2){
            ne++;
        }
        sum+=arr[i];
    }
    int ans=INT_MAX;
    // rec(arr,n,sum,0);
    // trace(no, ne, sum);
    // no = no - 2* (no/2);
    if(sum%2==0){
        cout<<0<<endl;
        return;
    }
    else if(no>ne){
        cout<<-1<<endl;
        return;
    }
    cout<<no<<endl;
    // cout<<ans<<endl;

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1 ;
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