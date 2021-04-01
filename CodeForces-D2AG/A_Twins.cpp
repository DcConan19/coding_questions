#include<bits/stdc++.h>
using namespace std;
#define ll long long int



void solve()
{
   int n;
   cin>>n;
   vector<int> arr(n);
   int sum=0;
   for(int i=0;i<n;i++) {
       cin>>arr[i];
       sum+=arr[i];
   }
   sort(arr.begin(),arr.end(), greater<int> ());
   int ans=0;
   int s=0;
   for(int i=0;i<n;i++){
       s+=arr[i];
       ans=i+1;
       if(s>sum/2){
           break;
       }
   }
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