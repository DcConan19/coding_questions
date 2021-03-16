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
void solve()
{

   int n, m , k;
   cin>>n>>m>>k;
   int arr[n][m];
   unordered_map<string, int> ump;
   for(int i=0;i<n;i++){
       string temp="";
       for(int j=0;j<m;j++){
           cin>>arr[i][j];
           if(arr[i][j]==1){
               temp.push_back('1');
           }else{
               temp.push_back('0');
           }
       }
       ump[temp]++;
   }
   int ans=INT_MIN;
   for (auto it : ump ){
       string s = it.first;
       int nz=0;
       for(char ch : s){
           if(ch=='0'){
               nz++;
           }
       }
       if(nz<=k && (nz-k)%2==0){
           ans=max(ans,ump[s]);
       }
   }
   ans=ans==INT_MIN?0:ans;
   cout<<ans<<endl;

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