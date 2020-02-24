#include<stdio.h>
int count=0;

void dfs(int a[10][10],int n,int v[10],int source)
{
	int i;
	count++;
	v[source]=1;
	printf("%d ",source+1);
	for (i=0;i<n;i++)
	{
		if (a[source][i]==1 && v[i]==0)
		{
			dfs(a,n,v,i);
		}
	}
}

void bfs(int a[10][10],int n,int v[10],int source)
{
	int i,q[10],m,r=-1,f=0;
	count++;
	q[++r]=source;
	v[source]=1;
	while (f<=r)
	{
		count++;
		m=q[f++];
		printf("%d ",m+1);
		for (i=0;i<n;i++)
		{
			if (a[m][i]==1 && v[i]==0)
			{
				q[++r]=i;
				v[i]=1;
			}
		}
	}
}



main()
{
	int a[10][10],v[10],n,i,j,source,comp=0;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	
	//Accepting input matrix
	printf("Enter the adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//Accepting source vertex
	printf("Enter the source vertex:");
	scanf("%d",&source);
	source--;
	
	//Converting to undirected graph
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[j][i]==1)
			{
				a[i][j]=1;
			}
		}
	}
	
	for (i=0;i<n;i++)
	{
		v[i]=0;
	}
	
	//To find DFS traversal from source node
	printf("DFS order:\n");
	dfs(a,n,v,source);
	comp++;
	if (count<n)
	{
		printf("\nThe graph is disconnected.The unreachable vertices are:\n");
		for (i=0;i<n;i++)
		{
			if (v[i]==0)
			{
				dfs(a,n,v,i);
				comp++;
			}
		}
		printf("\nThe no. of components are:%d\n",comp);		
	}
	else
	{
		printf("\nGraph is connected.\n");
	}
	
	for (i=0;i<n;i++)
	{
		v[i]=0;
	}
	count=0;
	comp=0;
	
	//To find BFS traversal from source node
	printf("BFS order:\n");
	bfs(a,n,v,source);
	comp++;
	if (count<n)
	{
		printf("\nThe graph is disconnected.The unreachable vertices are:\n");
		for (i=0;i<n;i++)
		{
			if (v[i]==0)
			{
				bfs(a,n,v,i);
				comp++;
			}
		}
		printf("\nThe no. of components are:%d\n",comp);		
	}
	else
	{
		printf("\nGraph is connected.\n");
	}
	
	
	return 0;
}
