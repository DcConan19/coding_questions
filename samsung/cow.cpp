#include <bits/stdc++.h>
using namespace std;
int ans;
void aggcow(int n, int c, int a[], int l, int h)
{
    if (h >= l)
    {
        int mid = (h + l) / 2;
        // cout<<l<<" "<<mid<<" "<<h<<endl;
        int k = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] - a[k] >= mid)
            {
                cnt++;
                k = i;
            }
        }
        // cout<<cnt<<endl;
        if (cnt >= c)
        {
            ans = mid;
            aggcow(n, c, a, mid + 1, h);
        }
        else
        {
            //cout<<mid<<"is to high"<<endl;
            aggcow(n, c, a, l, mid - 1);
        }
    }
    else
        return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        aggcow(n, c, a, 0, 10e9);
        cout << ans << endl;
    }
}