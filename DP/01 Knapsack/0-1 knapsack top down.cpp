#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;
    int wt[n];
    int profit[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            // i-1 because dp array start from 0 and we have n start from 1 to n so for checking through weight array
            // we have to check i-1 Position
            // in dp[i][-]  if i==1 that man i==0 in weight array so.
            else if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], profit[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }

    cout << dp[n][w] << endl;
    return 0;
}