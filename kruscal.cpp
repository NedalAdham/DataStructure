#include <bits/stdc++.h>
using namespace std ;

    /*/
    spanning tree 1) connected 2)Acyclic 3)n nodes => n-1 edge
    to convert graph to tree you need to delete edges
    edges = nodes - k       k = no of connected component
    MIN spanning tree => sum of weights should be minimum => MST

     kruskal prims algos are used to calc MST

    **************************************************************
    **************************************************************


    ***** kruskal *****
   (easy)                                  1)sort edges by weight
   (graph cycle detection => disjoint set) 2)pick the sorted where safe acycle (edge not make cycle) if equal pick any one

    Disjoint set Algo for kruskal
    a)make set => creat set with one element => parent [i] = i
    b)union => takes two sets and merge them into one => parent[a] = b
    c)find => return a representative element for that set => if same no found on same set then overlap be found

     example

     union (4,5) = {4*,5}  find(4) = 4 , find(2) = 5
     union (6,7) = {6*,7}  find(6) = 6 , find(7) = 6
     union (5*,6)= {4 , 5 ,6 , 7} representative either 4 or 6 as from above
     I choose the representing element =>*

     NOTE : ser ean component => if 2 element lies on the same set that means they
     lie in the same connected component

        makeset(i){
          parent[i] = i;
        }
        find(i){
         while(parent[i]!=i){
            i = parent[i];
         }
         return i;
        }
        union(x,y){
          a = find(x);
          b = find(y);
          parent[b] = a;
        }
        MST_kruskal(graph)
        {
        for each vertix {make set}
        sort the edge in as
        MST = EMPTY SET

        for each edge (u , v)
        {
        x = findset (u)
        y= find set (v)

        if (X!=y)
        {
        MST = MST Union {(u,v)}
        Union (x,y)
        }
        return MST
        }
        }
     /*/
    class edge{

    public:

        int s;
        int d;
        int w;
        edge(){}
        edge(int src,int des,int wei){

            s=src;
            d=des;
            w=wei;
        }
    };

    bool compare(edge e1,edge e2){
        return e1.w<e2.w;
    }

    int findparent(int i,int* parent ){

        if(parent[i]==i)
            return i;
        return findparent(parent[i],parent);
    }
    class graph{
    public:
        int e,n;
        edge* v;
        graph(int n,int e){
            this->n=n;
            this->e=e;
            v=new edge[e];
            for(int i=0;i<e;i++)
            {
                int x,y,w;
                cout<<"ENTER VERTICES AND WEIGHT OF EDGE "<<i+1<<" :	";
                cin>>x>>y>>w;
                edge e(x,y,w);
                v[i]=e;
            }
        }


        edge* unionfind(){

            int* parent=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            sort(v,v+e,compare);
            edge* output;
            output=new edge[n-1];
            int count=0,i=0;
            while(count!=n-1){
                edge c=v[i];
                int sourceparent=findparent(v[i].s,parent);
                int desparent=findparent(v[i].d,parent);
                if(sourceparent!=desparent){
                    output[count]=c;
                    parent[sourceparent]=desparent;
                    count++;
                }
                i++;
            }

            int sum=0;
            cout<<endl<<"-------MST-------\n";
            for(int i=0;i<n-1;i++){
                cout<<output[i].s<<"	"<<output[i].d<<"	"<<output[i].w<<endl;
                sum+=output[i].w;
            }
            cout<<"\nWEIGHT OF MST IS "<<sum;
            return output;
        }
    };

    int main(){
        int n,e;
        cout<<"KRUSKAL'S ALGORITHM\nENTER NUMBER OF VERTICES :	";
        cin>>n;
        cout<<"ENTER NUMBER OF EDGEES :	";
        cin>>e;
        graph g(n,e);
        edge* mst=g.unionfind();
    }
