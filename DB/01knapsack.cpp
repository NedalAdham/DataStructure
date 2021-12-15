;
int knapsack01 ( vector <int> &price , vector <int> &wts ,int w)
{
    int n = price.size() ;
    int dp [n+1][w+1];
    for (int i = 0; i <= n ; ++i) {
        for (int j = 0; j <= w ; ++j) {
            if (i==0 or j == 0)dp[i][j]=0;
            else if (wts[i-1] > j)dp[i][j] = dp[i-1][j];
            else
            {
                int inc = price[i-1]+dp[i-1][j-wts[i-1]];
                int exl = dp[i-1][j];
                dp[i][j] = max (inc , exl) ;
            }
        }
    }
}