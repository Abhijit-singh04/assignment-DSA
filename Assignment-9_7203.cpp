#include<bits/stdc++.h>
using namespace std;
class Topological{
    public:
    vector<int> *adj;
    int *degree;
    int v;
    int edges;
    Topological(){
     cout<<"Enter the number of vertices\n";
     int V;
     cin>>V;
    //  degree = new int[v];
     this->v = V;
     degree = new int[v];
     cout<<"Enter the number of edges in your graph\n";
     int e;
     cin>>e;
     this->edges = e;
     adj = new vector<int>[v]; 
     for(int i=0;i<v;i++){
         degree[i] = 0;
     }
    }
    void add_edge(){
        cout<<"Enter the U,V for edges\n";
        for(int i=0;i<edges;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
    }
    void display_graph(){
        for(int i=0;i<v;i++){
            cout<<i<<" -> ";
            for(auto a:adj[i]){
                cout<<a<<" -> ";
            }
            cout<<"\n";
        }
    }
    void calculate_degree(){
        for(int i=0;i<v;i++){
            for(auto k:adj[i]){
                degree[k]++;
            }
        }
    }
    void show_topological_order(){
        queue<int> q;
        for(int i=0;i<v;i++){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout<<u<<" --> ";
            for(auto d:adj[u]){
                degree[d] --;
                if(degree[d] ==0){
                    q.push(d);
                }
            }
            
        }
    }
};
int main(){
    Topological t;
    bool flag = true;
    // t.add_edge();
    // t.display_graph();
    // t.show_topological_order();
    while(flag){
    cout<<"-------MENU--------\n";
    cout<<"1.Add edge in the graph\n";
    cout<<"2.Display the graph\n";
    cout<<"3.Calcute the indegree of every vertices\n";
    cout<<"4.Show topological order of the graph\n";
    cout<<"5.Exit\n";
    int ch;
    cout<<"Enter the number of choice\n";
    cin>>ch;
    switch(ch){
        case 1:{
            t.add_edge();
            break;
        }
        case 2:{
            t.display_graph();
            break;
        }
        case 3:{
            t.calculate_degree();
            cout<<"The degree of every vertices is successfully calculated :-)\n";
            break;
        }
        case 4:{
            t.show_topological_order();
            cout<<"\n";
            break;
        }
        case 5:{
            flag = false;
            cout<<"Thank you :-)\n";
            break;
        }
        default :{
            cout<<"Enter the correct choice\n";
            break;
        }
    }
    }
    
    return 0;
}



