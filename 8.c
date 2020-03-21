#include<stdio.h>
#include<stdlib.h>

void prims(int g[20][20], int n)
{
	int vt[20],v[20],e[20],min,u1,v1;
	int ne=1,i,j,cost=0;
	vt[0]=1;
	for (i=1;i<n;i++)
	{
		vt[i]=0;
	}
	v[0]=0;
	for (i=1;i<n;i++)
	{
		v[i]=1;
	}
	printf("Minimum spanning tree edges:\n");
	while (ne<n)
	{
		min=999;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (g[i][j]<min)
				{
					if (i!=j && vt[i]==1 && v[j]==1)
					{
						min=g[i][j];
						u1=i;
						v1=j;
					}
				}
			}
		}
		cost+=min;
		vt[v1]=1;
		v[v1]=0;
		ne++;
		printf("Edge from vertex %d to %d\n",u1+1,v1+1);
		
	}
	printf("The weight of the minimum spanning tree is %d",cost);
}
int main()
{
	int n,g[20][20],i,j;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	prims(g,n);
}
