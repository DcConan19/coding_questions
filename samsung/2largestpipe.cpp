// A Recursive C program to solve minimum sum partition
// problem.
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum
vector<vector<int>> dp(100,vector<int> (100,-1));
int findMinRec(int arr[], int i, int sumCalculated, int sumTotal)
{
    // If we have reached last element. Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated. Return absolute difference
    // of two sums.
    if (i == 0)
        return abs((sumTotal - sumCalculated) - sumCalculated);

    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    if(dp[i][sumCalculated]!=-1){
        return dp[i][sumCalculated];
    }
    return dp[i][sumCalculated] = min(findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal),
                                    findMinRec(arr, i - 1, sumCalculated, sumTotal));
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];

    // Compute result using recursive function
    int d= findMinRec(arr, n, 0, sumTotal);
    cout<<(sumTotal+d)/2<<endl;
    return d;
}

// Driver program to test above function
int main()
{
    int arr[] = {1, 2, 3, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMin(arr, n);
    return 0;
}
