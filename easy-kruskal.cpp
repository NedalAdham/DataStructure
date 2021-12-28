#include <bits/stdc++.h>
using namespace std ;
void makeset (int n , int parent[])
{
    for (int i = 1; i <=n ; ++i) {
        parent[i] = i;
    }
}
int find (int i , int parent [])
{
    while (parent [i] != i )
    {i=parent[i];}
    return  i ;
}
bool compare (vector <int> a , vector <int> b)
{
    return a[2] < b[2] ;
}
int solve (int N , vector<vector<int>>&edges)
{
    sort (edges.begin() , edges.end() , compare );
    int parent [ N+1] ;
    makeset(N ,parent);
    int cost = 0;
    for (int i = 0; i <edges.size(); ++i) {
        int s = edges[i][0];
        int d = edges[i][1];
        int rs = find(s,parent);
        int rd = find(d,parent);

        if (rs != rd){ // No cyle
            cost += edges[i][2]; // 2 is weight index
            parent[rs] = rd ; // union
        }
    }

    return cost ;
}
