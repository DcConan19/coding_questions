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

// function generate all prime number less then N in O(n)
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        // int x;
        // cin >> x;
        // m[x]++;
    }
    sort(v.begin(), v.end());
    int ans = -1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            ans = i;
            break;
        }
    }
    if (ans == -1)
    {
        cout << 0 << endl;
        return;
    }
    cout << n - ans << endl;
    // if (m.size() == 1)
    // {
    // 	cout << 0 << endl;
    // 	return;
    // }
    // int ans = 0;
    // int x = 1;
    // for (auto i : m)
    // {
    // 	if (x == 1)
    // 	{
    // 		continue;
    // 	}
    // 	x++;
    // 	ans += i.second;
    // }
    // cout << ans << endl;
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
    while (t--)
    {
        solve();
        // cout << solve() << endl;
        // cout << "Done in " << clock() / CLOCKS_PER_SEC << "sec" << endl;
        // cout << "Case #" << x << ": " << solve() << endl;
        x++;
    }
    return 0;
}