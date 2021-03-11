#include <iostream>
using namespace std;

// recursive function to generate scores
int getmaxscore(int arr[], int l, int r, int n)
{
    int mscore = 0;
    for (int i = l + 1; i < r; i++)
    {

        // to permute through all cases
        int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n);
        if (l == 0 && r == n)
            cs = cs + arr[i];
        else
            cs = cs + (arr[l] * arr[r]);

        if (cs > mscore)
            mscore = cs;
    }
    return mscore;
}

int main() // driver function
{
    int n = 4; // no of balloons

    // assigning scores to each balloon 1-based indexing
    // arr[0]=1 because to calculate score when no
    //             balloons are left after popping
    // arr[5]=1 because to calculate score when no
    //             balloons are left after popping
    // scores of balloons are assigned from 1 to 4 i.e 1 to n
    int arr[] = {1, 1, 2, 3, 4, 1};

    /* for input input arr[n+2],  
      arr[0]=1 && arr[n+1]=1 
      cin>>n; 
      for(int i=1;i<=n;i++) 
         cin>>arr[i]; */

    cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n";

    return 0;
}