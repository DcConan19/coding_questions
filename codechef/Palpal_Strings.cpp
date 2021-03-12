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
bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
void allPalPartUtil(vector<vector<string>> &allPart, vector<string> &currPart,
                    int start, int n, string str)
{
    // If 'start' has reached len
    if (start >= n)
    {
        allPart.push_back(currPart);
        return;
    }

    // Pick all possible ending points for substrings
    for (int i = start; i < n; i++)
    {
        // If substring str[start..i] is palindrome
        if (isPalindrome(str, start, i))
        {
            // Add the substring to result
            currPart.push_back(str.substr(start, i - start + 1));

            // Recur for remaining remaining substring
            allPalPartUtil(allPart, currPart, i + 1, n, str);

            // Remove substring str[start..i] from current
            // partition
            currPart.pop_back();
        }
    }
}
void solve()
{
    string str;
    cin>>str;
    int n = str.length();
    vector<int> freq(26,0);
    for(int i=0;i<n;i++)
    {
        freq[str[i]-'a']++;
    }
    if(n<4)
    {
        cout<<"NO"<<endl;
        return;
    }
    int o=0,e=0,o3=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]==1)
        {
            o++;
        }
        else if(freq[i]!=0 && freq[i]%2==0)
        {
          e++;
        }
        else if(freq[i]!=1 && freq[i]%2)
        {
            o3++;
        }
    }
    // if(n==2)
    // {
    //     sort()
    // }
    trace(o,e,o3);
    if((o3>0 || e>0 ) && o==0)
    {
        cout<<"YES"<<endl;
    }
    else if ( o <= e)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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