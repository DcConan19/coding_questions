#include<bits/stdc++.h>
using namespace std;
    string getDayOfWeek(int d, int m, int y)
    {
        // code here
        int arr[] = {-1, 5, 3, 1, 0};
        int month[] = {-1, 3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
        int leapmonth[] = {-1, 3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
        vector<string> v = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int t[] = {11, 12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        // Convert months array
        for (int i = 0; i < 12; i++)
        {
            int ans = t[i] * 2.6 - 0.2;
            t[i] = ans % 7;
        }

        // Continue Algo
        if (m < 3)
            y -= 1;

        int day = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
        return v[day];
    }


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int d, m, y;

        cin >> d >> m >> y;

        cout << getDayOfWeek(d, m, y) << endl;
    }
    return 0;
} // } Driver Code Ends