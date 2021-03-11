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
ll min(ll a, ll b){
    if( a < b ){
        return a;
    }
    return b;
}
void solve()
{
 
 ll n , e , h , a , b, c;
 cin>>n>>e>>h>>a>>b>>c;
 vector<int> v(7,INT_MAX);
 ll ans=1e12+7;
  if(2*n<=e){
    //   trace(a * n);
      ans = min(ans, a * n);
  }
  if(3*n<=h){
    ans=min(ans,n*b);
    // trace(b*n);
  }
  if(min(e,h)>=n){
      ans=min(ans,n*c);
    //  trace(c* n,ans);
  }
//   if ( (e/2) + (h/3) >=n )
//   {
//       int pr = INT_MAX;
//       for (int i = 1; i <= e / 2; i++)
//       {
//           int ac;
//           if ( h/3 + i >= n)
//           {
//               ac = i * a + (n - i) * b;
//             //   trace(i, n - i, ac);
//               pr = min(ac, pr);
//           }
//       }
//     //   trace(pr);
//       ans = min(pr, ans);
//   }
  
//   if(1){
//    int pr=INT_MAX;
//   for(int i=1;i<=e/2;i++){
//       int ac;
//     if(min(e-i*2,h)+i >=n){
//        ac=i*a+(n-i)*c;
//     //    trace(i, n - i , ac);
//        pr=min(ac,pr);
//     }
//   }
// //   trace(pr);
//   ans=min(pr,ans);
// }
//   if(1){
//       int pr = INT_MAX;
//       for (int i = 1; i <= h / 3; i++)
//       {
//           int ac;
//           if (min(h - i * 3, e) + i >= n)
//           {
//               ac = i * b + (n - i) * c;
//             //   trace(i, n - i, ac);
//               pr = min(ac, pr);
//           }
//       }
//       //   trace(pr);
//       ans = min(pr, ans);
//   }
// //   int i=0,na,nb,nc;
//   int p=0;
//   while(i<3 && n >0){
//      if(a==min(a,min(b,c))){
//          na=e/2;
//          na=na>=n?n:na;
//          p+=na*a;
//          n-=na;
//          e=e/2;
//          a=1e6+9;
//      }
//      else if (b == min(a, min(b, c))){
//          nb = h / 3;
//          nb = nb >= n ? n : nb;
//          p += nb * b;
//          n -= nb;
//          h = h/3;
//          b = 1e6 + 9;
//      }
//      else if (c == min(a, min(b, c))){
//          nc = e>h?h:e;
//          nc = nc >= n ? n : nc;
//          p += nc * c;
//          n -= nc;
//          e = e - nc;
//          h = h - nc;
//          c = 1e6 + 9;
//      }
//      i++;
//   }
//   if(n>0){
//       p=INT_MAX;
//   }
//   ans=min(ans,p);
//   if(1){
//       ll pr = 1e12 + 7;
//       for(ll i=0;i<=e/2;i++){
//           for(ll j=0;j<=h/3;j++){
//               ll ac=0;
//               if(i+j+min(e-i*2,h-j*3)==n){
//                   ac = i * a + j * b + min(e - i * 2, h - j * 3) * c;
//                 //   trace(i, j, n - i - j, ac);
//                   pr = min(ac, pr);
//               }
//           }
//       }
//       ans=min(pr,ans);
//   }
  ans = ans == 1e12 + 7 ? -1 : ans;
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