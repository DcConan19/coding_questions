#include<bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    string str, str_m;
    cin>>str;
    for (int i=0; i<str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    for (auto k: str) {
        if(k != 'a' && k != 'o' && k != 'y' && k != 'e' && k != 'u' and k != 'i') {
            str_m.push_back('.');
            str_m.push_back(k);
        }
    }
    cout<<str_m<<endl;
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