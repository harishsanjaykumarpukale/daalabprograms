#include<stdio.h>
#define INFINITY 999

void prims(int n,int cost[10][10],int source){
	int v[10]; // keeps track to nodes visited and not
       	int d[10]; // keeps latest shortest distance from source
        int i, j; //index variables
        int vertex[10]; //keeps track of nearest node to spanning tree
        int u, least, sum=0;

	//1. Initialisation
        for(i=1;i<=n;i++){
		v[i] = 0; //initialially none of the nodes are visited
		d[i] = cost[source][i]; //distance from source to ith node
		vertex[i] = source; //nearest node to spanning tree
	}
	
	v[source] = 1; //mark source node as visited

	//2. n iteration
	for(i=1;i<n;i++){
		least = INFINITY;

		//2a) Find u and d(u) such that d(u) is least and it's not visited
		for(j=1; j<=n; j++){
			if(v[j] == 0 && d[j] < least){
				least = d[j];
				u = j;// store the node for further use of updating distances 
			}
		}

		//2b) mark node u as visited
		v[u] = 1; // mark the vertex u (i.e vertex at least distance from tree ) as visted 
		sum += d[u]; 
		printf("%d --> %d = %d Total Sum = %d\n\n",vertex[u],u,d[u],sum);

		//2c) update d[] array. Explore paths through node u.
		for(j=1;j<=n;j++){
			if(v[j] == 0 && d[j] >  cost[u][j]){
				d[j] = cost[u][j]; //update the distance
				vertex[j] = u;  // update nearest node
			}
		}
	}

	printf("Total cost: %d",sum);
}


int main(){
	int n; //no. of nodes
	int cost[10][10]; //Adjacency matrix of graph
	int source; //source node
	int i, j; //index variables
	printf("Enter n (no. of nodes):");
	scanf("%d", &n);
	printf("Enter cost matrix:(use 999 as infinity)\n");
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			scanf("%d", &cost[i][j]);
	printf("Enter Source: ");
	scanf("%d", &source);
	prims(n, cost, source);
	return 0;
}

