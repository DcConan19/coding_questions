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
    ll d=0;
    ll n;
    cin>>n;
    // cout<<n<<endl;
    int x=n;
    while(x>0){
        x=x/2;
        d++;
    }
    ll a=pow(2,d)-1;
    ll b=pow(2,d)-1;
    int f=1;
    for(int i=d-1;i>=0;i--){
        if( n & ( 1 << (i))){
            if(f){
                f=0;
                a=a & ~ (1 << (i));
            }else{
                b = b & ~ (1 << (i));
            }
        }
        // trace(i,n & (1 << (i)));
    }
    cout<<a*b<<endl;
    //  cout<< (n &(1 << 1))<<endl;
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
    for (int i = 1; i <= t; i++)
    {
        // cout << "Scenario #" << i << ":" << endl;
        solve();
        // cout << solve() << endl;
    }
    return 0;
}