#include<bits/stdc++.h>
using namespace std;
class Prim_graph{
    int **adj;
    int v;
    int edges;
    public:
    Prim_graph(int v,int e){
        this->v=v;
        this->edges = e;
        adj = new int*[v];
        for(int i=0;i<v;i++){
            adj[i] = new int[v];
            for(int j=0;j<v;j++){
                adj[i][j] = 0;
            }
        }
    }
    
    void add_edge(){
        int u,v,w;
        cout<<"Enter the u,v, w\n";
        for(int i=0;i<edges;i++){
            cin>>u>>v>>w;
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }
    void Show_graph(){
    cout<<"The graph is\n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}
    int prim_algo(){
        int dist[v];
        for(int i=0;i<v;i++){
            dist[i] = INT_MAX;
        }
        bool visited[v] = {false};
        dist[0] = 0;
        int result = 0;
        for(int count = 0;count<v;count++){
            int u=-1;
            for(int i=0;i<v;i++){
                if((!visited[i]) && (u==-1||dist[i]<dist[u])){
                    u=i;
                }
            }
            visited[u] = true;
            result += dist[u];
            for(int i=0;i<v;i++){
                if(!visited[i]&&adj[u][i]!=0){
                    dist[i] = min(dist[i],adj[u][i]);
                }
            }
        }
        return result;
    }
    
};

class Edge{
    public:
    int src,dest,wt;
};

class Graph:public Edge{
    public:
    int ed;
    Edge *a;
    int *parent;
    int *rank;
    Edge *mst;
    int v;
    Graph(int v,int e){
        this ->ed = e;
        this->v=v;
        a = new Edge[e];
        mst = new Edge[e];
        parent = new int[v];
        rank = new int[v];
    }
    bool static my_comp(Edge e1,Edge e2){
        return e1.wt<e2.wt;
    }
    void add_edge(){
        cout<<"Enter u,v,w\n";
        for(int i=0;i<ed;i++){
            cin>>src;
            cin>>dest;
            cin>>wt;
            a[i] = {src,dest,wt};
        }
    }
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
        }
    
    void uni(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1]+1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2]+1;
            }
    }
    void Show_graph(){
        cout<<"The graph is\n";
        for(int i=0;i<ed;i++){
            cout<<a[i].src<<" "<<a[i].dest<<" "<<a[i].wt<<"\n";
        }
    }
    int kruskal(){
        for(int i=0;i<v;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        sort(a,a+ed,my_comp);
        int res = 0;
        for(int i=0, s=0;s<v-1;i++){
            Edge f = a[i];
            int x = find(f.src);
            int y= find(f.dest);
            if(x!=y){
                mst[s] = f;
                res += f.wt;
                uni(x,y);
                s++;
            }
            
        }
        return res;
    }
    
};


int main(){
    cout<<"Graph for prim algorithm\n";
    int edg,vert;
    cout<<"Enter the number of edges and vertices in graph\n";
    cin>>edg>>vert;
    Prim_graph p(vert,edg);

    cout<<"Graph for kruskal algorithm\n";
    cout<<"Enter the number of edges and vertices in graph\n";
    cin>>edg>>vert;
    Graph k(vert,edg);
    
    bool flag = true;
    while(flag){
    cout<<"----------------MENU----------------\n";
    cout<<"A.-----------Prim algorithm-----------\n";
    cout<<"1.Add_edges in the graph\n";
    cout<<"2.To calculate the minimum cost \n";
    cout<<"3.To Show graph\n";
    cout<<"4.Exit\n";
    cout<<"B.-----------Kruskal's algorithm-----------\n";
    cout<<"5.Add_edges in the graph\n";
    cout<<"6.To calculate the minimum cost \n";
    cout<<"7.To Show graph\n";
    cout<<"8.Exit\n";
    cout<<"Please enter the correct choice number\n";
    int ch;
    cin>>ch;
    switch(ch){
        case 1:{
            p.add_edge();
            break;
        }
        case 2:{
            cout<<"The minimum cost is "<<p.prim_algo()<<"\n";
            break;}
        case 3:{
            p.Show_graph();
            break;
        }
        case 4:{
            cout<<"Thank you\n";
            flag = false;
            break;}
        case 5:{
            k.add_edge();
            break;
        }
        case 6:{
            cout<<"The minimum cost is : "<<k.kruskal()<<"\n";
            break;
        }
        case 7:{
            k.Show_graph();
            break;
        }
        case 8:{
            cout<<"Thank you\n";
            flag = false;
            break;}
        default:{
            cout<<"Enter the correct choice number\n";
            break;
        }
    }
    }
    return 0;
}




