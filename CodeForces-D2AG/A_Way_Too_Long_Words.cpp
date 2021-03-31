#include<bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{   
    int n; 
    string str;
    cin>>str;
    n = str.length() -2;
    if(str.length()>10) {
        cout<<str[0]<<n<<str[n+1]<<endl;
        // return;
    }
    else
        cout<<str<<endl;
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
        // cout <<
        solve();
        // cout << solve() << endl;
    }
    return 0;
}