#include <bits/stdc++.h>
using namespace std ;
void DFSprint ( vector<vector<int> > v , int starti , vector<bool>&visited )
{
    //recursion , pass reference //
// recursion on adjacent vertex of strati
//DFS => DEPTH FIRST SEARCH
    cout << starti <<endl ;
    visited [starti] = true ;
    int size  =  v . size() ;
    for (int i = 0; i < size; ++i) {
        if (v[starti][i] == 1 and visited [i] == false) {
            DFSprint(v, i ,visited);
        }
    }
}

void BFSprint ( vector<vector<int> > v , int starti )
{


    int size  =  v . size() ;
    vector <bool> visited (size , false) ;
    queue <int> q ;
    q.push(starti);
    visited [starti] = true ;
    while (!q.empty())
    {
        int currentvertix  =q.front() ;
        q.pop();
        cout << currentvertix <<endl;
        for (int i = 0; i < size ; ++i) {
            if (v [currentvertix][i] and !visited[i])
            {
                q.push(i);
                visited[i] = true ;
            }
        }
    }
}


int main()
{
    int vertix , edge;
    cin >> vertix >> edge ;
    vector<vector<int> > matrix (vertix , vector<int>(vertix,0)) ;
    for (int i = 1; i <= edge ; ++i) {
        int fv , sv ;
        cin >> fv >> sv ;
        matrix[fv][sv] = 1 ;
        matrix[sv][fv] = 1 ;
    }

    vector <bool> visited (vertix , false) ;

    cout<<"DFS"<<endl ;
    DFSprint (matrix , 0 , visited) ;
    cout << "-------------"<<endl ;
    cout << "BFS"<<endl;
    BFSprint(matrix ,0) ;
}
