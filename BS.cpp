/*/
 #include <iostream>
const int max=100000;
int arr [max] ;
using namespace std;
int binarysearch ( long long l ,long long r , long long target)
{
    long long lolxd = -1;
    while (l<=r){

        long long mid = l+ (r-l) /2 ;
        if (arr [mid] ==  target)
        {
            lolxd = mid;
            r = mid - 1 ;
        }
        else if (arr [mid] < target) l = mid + 1 ;
        else r = mid - 1 ;
    }
    return lolxd ;
}
/*/
/*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main () {
    ios::sync_with_stdio(false);cout.tie(nullptr);cin.tie(nullptr);
    vector<int>vec;
    long long n, q ,x, targets; cin >> n >> q;
    for (long long i = 0; i < n; ++i)
    {
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    while (q--) {
        cin >> targets;
        vector <int>::iterator lower;
        lower = lower_bound(vec.begin(),vec.end(), targets);
        for (long long j = 0; j < n ; ++ j){
            if (targets ==vec[j]) cout<<(lower-vec.begin())<<endl ;
            else {
                cout <<"-1" <<endl;
                break;
            }
        }

    }
}
/*/
/*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
     int n ;int sum =0;
    vector<int>vec ;int arr [100005];
    cin >> n ; //

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i]; //
        sum += arr[i];
        vec.push_back(sum);
    }

    vector<int>::iterator lower;
    int m ; cin >> m ;//

    for (int j = 0; j < m; ++j) {
        int target ;
        cin >> target;//
        lower=lower_bound(vec.begin(),vec.end(),target);
        cout<<lower-vec.begin()+1<<endl;
    }
}
/*/
/*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,i,sum=0;
    cin>>n;
    int v[n];
    std::vector<int> vec(n);

    for(i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
        vec[i]=sum;


    }
    std::vector<int>::iterator low1;

    cin>>m;

    for(i=0;i<m;i++){
        cin>>x;
        low1=lower_bound(vec.begin(),vec.end(),x);
        //int y=*low1;


        cout<<low1-vec.begin()+1<<endl;

    }

}
/*/
/*/
#include <iostream>
const int max=100000;
int arr [max] ;
using namespace std;
int binarysearch ( long long l ,long long r , long long target)
{
    long long lolxd = -1;
    while (l<=r){

        long long mid = l+ (r-l) /2 ;
        if (arr [mid] ==  target)
        {
            lolxd = mid;
            r = mid - 1 ;
        }
        else if (arr [mid] < target) l = mid + 1 ;
        else r = mid - 1 ;
    }
    return lolxd ;
}

int main ()
{
    int n ; cin >>n ;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int t ; cin >> t;
    while (t--){
        int l ; int r ; cin >> l >> r;
        cout << binarysearch(l , r ,)
    }

}
/*/
/*/
#include <iostream>
#include <math.h>
using  namespace std ;
int main ()
{
    int t ; cin >> t ;int ctn = 0 ;
    while (t--)
    {
        int a , b ; cin >> a >> b ;
        while (!b){
            for (int i = 0; i < (1<<5); ++i) {
                a=a / pow(2,i);
                ctn++;
            }

        }


    }
    cout <<ctn ;
}
/*/
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;
int main()
{
    int sh ; cin >>sh ;
    cout<<sh*2;
}