
#include <bits/stdc++.h>
using namespace std ;
int fib(int n)
{
    if (n==0 or n ==1){return n;}
    else return fib(n-1) + fib(n-2);
}

//both direction for and back memorization
int fib_oN (int n , int *arr)
{
    if (n ==1 or n==0)return n;

    if (arr[n]!= 0) return arr[n];

    int fibsum = fib_oN(n-1,arr) + fib_oN(n-2,arr);
    arr[n] = fibsum;
    return fibsum;
}
int fib_DP(int n)
{
    int *arr = new int (n+1);
    arr[0] =0;
    arr[1]=1;

    for (int i = 2; i <=n ; ++i) {
        arr[i] = arr[i-1]+arr[i-2];
    }

    int fibsum = arr[n];
    delete[]arr;
    return fibsum;
}
int main ()
{

}