#include<bits/stdc++.h>

using namespace std;
#define ll long long int

void solve()
{
    string str1, str2;
    int flag=0; 
    cin>>str1>>str2;
    for (int i=0; i<str1.length(); i++) {
        str1[i] = tolower(str1[i]);
    }
    for (int i=0; i<str2.length(); i++) {
        str2[i] = tolower(str2[i]);
    }

    // comparing 
    for (int i=0; i < str1.length(); i++) {
        if(str1[i]<str2[i]) {
            flag = -1;
            break;
        }
        else if(str1[i]>str2[i]) {
            flag = 1;
            break;
        }
    }
    cout<<flag;     
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
        // cout << 
        solve();
        // cout << solve() << endl;
    }
    return 0;
}