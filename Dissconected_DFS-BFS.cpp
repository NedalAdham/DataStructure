#include <bits/stdc++.h>



using namespace std ;

void BFSprint ( vector<vector<int> > v , int starti , vector<bool>&visited )
 {
    //ref cause am changing visited array
    int size  =  v . size() ;

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
void disconnected_BFS(vector<vector<int>> matrix) {

    int n = matrix .size();
    vector <bool> visited (n , false) ;
    int count =0;
    for (int i = 0; i < n ; ++i) {
        if (!visited[i])
        {
            count++;
            BFSprint(matrix ,i ,visited);
        }
    }
    cout << "NO of connected components is " << count <<endl ;
}

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

void disconnected_DFS(vector<vector<int>> matrix)
{
    //just DFS over non visited vertex on visited array
    int n = matrix .size();
    vector <bool> visited (n , false) ;
    int count =0;
    for (int i = 0; i < n ; ++i) {
        if (!visited[i])
        {
            count++;
            DFSprint(matrix ,i ,visited);
        }
    }
    cout << "NO of connected components is " << count <<endl ;
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



    vector <bool>visited(vertix,false);
    cout<<"DFS"<<endl ;
    disconnected_DFS(matrix);
    cout<<"---------------"<<endl;


    cout<<"BFS"<<endl ;
    disconnected_BFS(matrix);



}
