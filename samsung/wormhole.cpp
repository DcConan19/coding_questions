#include <iostream>
using namespace std;

int ans, mask[10], w[10][5], n;

int distance(int sx, int sy, int dx, int dy)
{
    return abs(sx - dx)+abs(sy - dy) ;
    // return (xd + yd);
}

void cal(int sx, int sy, int dx, int dy, int dis)
{

    ans = min(ans, distance(sx, sy, dx, dy) + dis);

    for (int i = 0; i < n; i++)
    {
        if (mask[i] == 0)
        {
            mask[i] = 1;
            int temp = distance(sx, sy, w[i][0], w[i][1]) + dis + w[i][4];
            cal(w[i][2], w[i][3], dx, dy, temp);
            temp = distance(sx, sy, w[i][2], w[i][3]) + dis + w[i][4];
            cal(w[i][0], w[i][1], dx, dy, temp);
            mask[i] = 0;
        }
    }
}
int main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {

        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        cin >> n;
        // cout<<n<<endl;
        for (int i = 0; i < n; i++)
        {
            mask[i] = 0;
            for (int j = 0; j <5; j++)
            {
                cin >> w[i][j];
                // cout<<w[i][j]<<" ";
            }
            // cout<<endl;
        }
        ans = 999999;
        cal(sx, sy, dx, dy, 0);
        cout << ans << endl;
    }
    return 0;
}