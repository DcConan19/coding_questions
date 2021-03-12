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

void solve()
{
   ll p , a , b ,c;
   cin>>p>>a>>b>>c;
   ll a1=0,a2=0,a3=0;
   if(a<p)
   {
      a=p%a==0?a*(p/a) : a*(p/a + 1);
      a1=a-p;
   }else{
      a1=a-p;
   }
   if (b < p)
   {
      b= p % b == 0 ? b *(p / b) : b *(p / b + 1);
       a2 = b - p;
   }
   else
   {
       a2 = b - p;
   }
   if (c < p)
   {
      c= p % c == 0 ? c *(p / c) : c *(p /c + 1);
       a3 = c - p;
   }
   else
   {
       a3 = c - p;
   }
//    trace(a,b,c);
   cout<<min(a1,min(a2,a3))<<endl;
   return;
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