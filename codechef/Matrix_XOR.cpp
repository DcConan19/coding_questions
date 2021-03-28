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

// ll min(ll a , ll b ){
//     if(a<b){
//         return a;
//     }
//     else if(b<a){
//         return b;
//     }
//     else
//     return a;
// }
void solve()
{
   int n , m ;
   ll k;
   cin>>n>>m>>k;
   ll xo=0;
    if(n==1 ){
        ll sum=0;
        for(int i= 1 ; i<=m ;i++){
          sum=k+1+i;
          xo=xo^sum;
        }
        cout<<xo<<endl;
        return ;
   }
   if ( m == 1)
   {
       ll sum = 0;
       for (int i = 1; i <= n; i++)
       {
           sum = k + 1 + i;
           xo = xo ^ sum;
       }
       cout << xo << endl;
       return ;
   }
   int c=1;
   for(int i=1;i<=n+m-1;i++){
       if (i < m)
       {
           int a = min(n, c);
           trace(c,i, m,a);
           
           if (a % 2 == 1)
           {
               xo = xo ^ (i + 1 + k);
           }
           c=a+1;
        }
        else if (i== m)
        {
            int a = min(n, c);
            trace(c, i,m, a);
            if (a % 2 == 1)
            {
                xo = xo ^ (i + 1 + k);
            }
            c=a-1;
            
        }
        else if(i>m){
            int a = c;
            trace(c-1, i,m,a);
        

            if (a % 2 == 1)
            {
                xo = xo ^ (i + 1 + k);
            }
            c=a-1;
        }
        
   }
//    cout<<(3^5^8^10)<<endl;
   cout<<xo<<endl;
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