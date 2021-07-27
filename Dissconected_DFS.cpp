/////////////////// DFS Disconnected ////////////////
void print_DisconectedDfs(vector<vector<int>>v,int sv , vector<bool >&visited)
{
    cout << sv <<endl ;
    visited[sv] = true;
    int n = v. size() ;
    for (int i = 0; i < n ; ++i)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            print_DisconectedDfs(v, i , visited);
        }
    }
}
void DFS_disconnected (vector<vector<int>> matrix)
{

    int n = matrix . size() ;
    vector <bool>visited(n,false);
    int count = 0 ;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
        {
            count ++ ;
            print_DisconectedDfs(matrix,i,visited);
        }
    }

    cout << "NO of connected components is " << count <<endl ;

}

int main()
{
    int n,e ;
    cin >> n >> e ;
    vector<vector<int> > matrix (n,vector<int>(n,0));
    for (int i = 0; i < e ; ++i)
    {
        int fv , sv ;
        cin >> fv >> sv ;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }
    vector <bool>visited(n,false);

    DFS_disconnected(matrix);

}