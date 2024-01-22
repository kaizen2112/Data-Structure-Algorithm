#include <bits/stdc++.h>
using namespace std;

const int n = 10000;
int wt[n], val[n];
int dp[n][n];

int knapsack(int ind, int W)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notake = 0 + knapsack(ind - 1, W);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + knapsack(ind - 1, W - wt[ind]);

    int ans = max(notake, take);

    return dp[ind][W] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int noOfitem, TotW;
    cin >> noOfitem >> TotW;
    for (int i = 0; i < noOfitem; i++)
    {
        cin >> wt[i] >> val[i];
    }
    int ans = knapsack(noOfitem - 1, TotW);
    cout << ans;
    return 0;
}
/*
3 4
4 1
5 2
1 3
*/