#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int m[5][5],ti,tj,count=0;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j <5; j++)
        {
            if(m[i][j] == 1) {
                ti = i+1;
                tj = j+1;
            }
        }
    }
    count = abs(ti-3) + abs(tj-3);
    cout<<count<<endl;
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
