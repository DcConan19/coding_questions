#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct s
{
    int distance;
    int start;
    int ending;
};
struct fn
{
    bool operator()(s const &a, s const &b)
    {
        if (a.distance != b.distance)
        {
            return a.distance < b.distance;
        }
        return a.start < b.start;
    }
};
int main()
{
    int n;
    cin >> n;
    int mat[n] = {0};
    priority_queue<s, vector<s>, fn> q;
    struct s temp;
    int l = 1, r = n, coun = 1;
    q.push({n, l, r});
    while (!q.empty())
    {
        temp = q.top();
        q.pop();
        int left = temp.start;
        int right = temp.ending;
        int mid = (left + right) / 2;
        if (temp.distance > 0)
        {
            if (right > mid)
            {
                q.push({right - mid, mid + 1, right}); // first push right child then left
            }
            if (left < mid)
            {
                q.push({mid - left, left, mid - 1});
            }
        }
        mat[mid - 1] = coun;
        coun++;
        for (int i = 0; i < n; i++)
        {
            if (mat[i] == 0)
            {
                cout << "_"
                     << " ";
            }
            else
            {
                cout << "X"
                     << " ";
            }
        }
        cout << endl;
    }
}