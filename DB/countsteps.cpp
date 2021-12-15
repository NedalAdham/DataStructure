#include <bits/stdc++.h>
using namespace std ;
int countsteps (int n)
{
    if (n==0 || n==1)return 1;
    return countsteps(n-1)+countsteps(n-2);
}

// n steps
//k max here 2
int countsteps_dP (int n , int k)
{
int dp[n+1];
dp[0]=1;
    for (int i = 1; i <=n ; ++i) {
        int ans = 0;
        for (int j = 1; j <= k ; ++j) {
            if(i-j >= 0)ans+=dp[i-j];
        }
        dp[i] = ans;

    }
    return dp[n];
}
int main ()
{
cout<<countsteps_dP(3,3);
}
