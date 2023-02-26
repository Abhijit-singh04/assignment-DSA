// Tour operator organizes guided bus trips across the Maharashtra. Tourists may have different
// preferences. Tour operator offers a choice from many different routes. Every day the bus
// moves from starting city S to another city F as chosen by client. On this way, the tourists can
// see the sights alongside the route travelled from S to F. Client may have preference to choose
// route. There is a restriction on the routes that the tourists may choose from, the bus has to
// take a short route from S to F or a route having one distance unit longer than the minimal
// distance. Two routes from S to F are considered different if there is at least one road from a
// city A to a city B which is part of one route, but not of the other route.


#include<bits/stdc++.h>
using namespace std;
class Bus{	
	public:
	int** adj;
	int n;
	Bus(){
		int N;
		cout<<"Enter the number of cities\n";
		cin>>N;
		this->n=N;
        adj = new int*[n];
	        for(int i=0;i<n;i++){
		        adj[i] = new int[n];
			        for(int j=0;j<n;j++){
				        adj[i][j] = 0;
		            }
	            }
	       }	
	
void add_paths(){
	cout<<"Enter the number of roads betweeen cities\n";
	int roads;
	cin>>roads;
	cout<<"Enter the roads of cities starting from m and k and having distance d\n";
	for(int i=0;i<roads;i++){
		int m, k,d;
		cin>>m>>k>>d;
		adj[m][k] = d;
		adj[k][m] = d;
}
}
int dijkstra(int s,int final){
		int dist[n];
		bool visited[n];
		for(int i=0;i<n;i++){
		dist[i] = INT_MAX;
		visited[i] = false;	
    }
		dist[s] =0;
		for(int count = 0;count<n-1;count++){
		int u=-1;
		for(int i=0;i<n;i++){		
			if(!visited[i] && (u==-1||dist[i]<dist[u])){
					u=i;
				}
	        }
		visited[u] = true;
		for(int j=0;j<n;j++){
			if(adj[u][j]!=0 && !visited[j]){
				dist[j]	 = min(dist[j],dist[u]	+ adj[u][j]);
		    }
	    }
    }
	cout<<"The minimum distance betweeen "<<s<<" and destination "<<final<<" is\n";
	cout<<dist[final]<<"\n";
    }
};

int main(){
    cout<<"Welcome to abc tour and travels\n";
	Bus b;
	bool flag = true;
	while(flag){
	cout<<"-------Menu--------\n";
	cout<<"1.Enter the cities to visit with their distance\n";
	cout<<"2.To get the minimum distance between two cities\n";
	cout<<"3.To end the journey\n";
	cout<<"Enter the correct choice number\n";
	int ch;
	cin>>ch;
	switch(ch){
	    case 1:{
	        b.add_paths();
	        break;
	    }
	    case 2:{
	        cout<<"Enter the starting and destination cities\n";
	        int start , dest;
	        cin>>start>>dest;
	        b.dijkstra(start,dest);
	        break;
	    }
	    case 3:{
	        cout<<"Thank you\n";
	        flag =false;
	        break;
	    }
	    default:{
	        cout<<"Enter the correct choce\n";
	        break;
	    }
	}
	}
	return 0;
}




