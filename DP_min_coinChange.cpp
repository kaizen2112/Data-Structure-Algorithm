#include <bits/stdc++.h>
using namespace std;

const int n = 1e4;
int dp[n][n];

int func(int ind, int T, vector<int> &coins)
{
    if (ind == 0)
    {
        if (T % coins[0] == 0)
            return T / coins[0];
        else
            return 1e9;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int notake = 0 + func(ind - 1, T, coins);

    int take = INT_MAX;
    if (coins[ind] <= T)
        take = 1 + func(ind, T - coins[ind], coins);

    int ans = min(notake, take);

    return dp[ind][T] = ans;
}

int minimumCoinChange(vector<int> &coin, int T)
{
    int n = coin.size();
    int ans = func(n - 1, T, coin);
    if (ans >= 1e9)
        return -1;

    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int target;
    cin >> target;

    int ans = minimumCoinChange(coins, target);
    cout << ans;

    return 0;
}

/*
3
1 2 5
11
*/
