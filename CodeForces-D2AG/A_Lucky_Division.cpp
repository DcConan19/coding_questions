#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int n;
    cin>>n;
    if (n%4==0){
        cout<<"YES"<<endl;
    }
    else if (n%7==0) {
        cout<<"YES"<<endl;
    }
    else if (n%47==0) {
        cout<<"YES"<<endl;
    }
    else if (n%477 == 0){
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
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
        solve();
    }
    return 0;
}