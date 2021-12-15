#include <bits/stdc++.h>
using namespace std ;
int minsteps_BruteForce(int n)
{
    if (n<=1)return 0;

    int x = minsteps_BruteForce(n-1);
    int y , z ;
    y = z = INT_MAX;
    if (n%2 == 0){y = minsteps_BruteForce(n/2);}
    if (n%3 == 0){z = minsteps_BruteForce(n/3);}

    int ans = min (x,min(y,z))+1;
    return ans;
}
//////////////////
int help (int n , int *ans)
{
    if (n<=1)return 0;
    if (ans[n] != -1)
        return ans[n];

    int x = help(n-1,ans);
    int y , z ;
    y = z = INT_MAX;
    if (n%2 == 0){y = help(n/2 ,ans);}
    if (n%3 == 0){z = help(n/3,ans);}


    int minstepsmemorization = min (x,min(y,z))+1;
    ans [n] = minstepsmemorization ;
    return minstepsmemorization;
}
int minsteps_Memorization(int n)
{
    int *arr = new int [n+1] ;
    for (int i = 0; i <n ; ++i) {
        arr[n] = -1 ;
    }
    return help(n-1 , arr);
}
/////////////
// dp[i] = (i => 1)
// dp [n] = (n=>1)
int minsteps_Itirative_bottomUp(int n)
{
    int *dp = new int [n+1] ;
    dp[0]=0;
    dp[1]=0;
    for (int i = 2; i <= n ; ++i) {
        int x = dp[i-1];
        int y , z ;
        y = z = INT_MAX;
        if (i%2 == 0){y = dp[i/2];}
        if (i%3 == 0){z = dp[i/3];}

        dp[i] = min (x , min (y,z)) + 1 ;
    }
    return dp[n];
}
int main ()
{
   cout<< minsteps_Itirative_bottomUp(95);
}