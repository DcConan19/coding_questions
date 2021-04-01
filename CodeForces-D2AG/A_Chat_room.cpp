#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    string str, s = "hello"; 
    int dex=0, key=0;
    cin>>str;
    for (int i=0; i< str.length(); i++) {
        if (str[i] == s[dex]) {
            dex++;
            key++;
            if (key == 5) {
                break;
            }
            // cout<<str2<<endl;
        }
    }
    
    if (key == 5) {
        cout << "YES"<<endl;
    }
    else {
        cout << "NO"<<endl;
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
