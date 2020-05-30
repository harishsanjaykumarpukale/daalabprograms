/*
Traveling Salesman Problem
Hamiltonian tour optimization problem with branch and bound
Works for graphs for which a solution exists - the graph should be small
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//temporarySolution holds the partial solutions during processing
//optimalSolution holds the best solution encountered
int optimalSolution[20],temporarySolution[20];
//inintially all the vertices are unmarked
int marked[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//sum holds the best solution distance encountered and tempSum holds partial solution distances
//tempcount holds the number of elements added into temporarySolution array
int tempcount = 0, sum = INT_MAX, tempsum;

//function - minEdge: returns the value of minimum distance edge incident on vertex v
int minEdge (int arr[][20], int n, int v)
{
    int min = INT_MAX;
    for (int i=0;i<n;i++)
        if (arr[v][i]!=0&& marked[i]==0 && arr[v][i]<min)
            min = arr[v][i];
    return min;
}
//function - sumTwoMin: returns the sum of two minimum elements in the array for our problem
int sumTwoMin (int arr[][20], int n, int ele)
{
    int min = 10000000, minSum = INT_MAX;
    for (int i=0;i<n;i++)
    {
        if (arr[ele][i]!=0&&minSum>(min+arr[ele][i]))
        {
            minSum = min+arr[ele][i];
            if (arr[ele][i]<min)
                min = arr[ele][i];
        }
    }
    return minSum;
}

//function-lowerbound: computes the lowerbound for unmarked vertices
int lowerbound (int graph[][20], int n)
{
    int lb = 0;
    for (int i=0;i<n;i++)
    {
        //compute only for the unmarked vertices
        if (marked[i]==0)
            lb += sumTwoMin(graph,n,i);
    }
    return lb;
}
//function - TSP
void TSP (int graph[][20], int n, int source)
{
    //add the source to temporary solution array
    tempcount++;
    temporarySolution[tempcount-1] = source;
    //mark the source
    marked[source] = 1;
    //if it is the root node
    if (tempcount == 1)
        tempsum = 0;
    //if all the vertices have been visited - then path will be found if present
    if (tempcount == n && graph[source][temporarySolution[0]]!=0)
    {//if all vertices added and there is an edge from the last vertex to the initial vertex
        tempsum+=graph[source][temporarySolution[0]];//this is the total path cost
        if (tempsum<sum )//if it is a better path
        {//copy the temporary solution into optimal solution array
            for (int i=0;i<n;i++)
                optimalSolution[i] = temporarySolution[i];
            //update the global sum
            sum = tempsum;
        }
        tempsum -= graph[source][temporarySolution[0]];//undo changes to global variable before returning
    }
    else{//if none of the two conditions are satisfied, branch from the "source"(vertex in question)
    for (int i =0;i<n;i++)
    {
        if (marked[i]==0 && graph[source][i] != 0)//unmarked and edge exists
        {
            //get a bound
            marked[i] = 1;
            tempsum += graph[source][i];//add the edge to temporary sum
            //compute lowerbound with ceil mimicked by adding 1 and performing integer division
            int bound = tempsum + (lowerbound(graph,n)+1+minEdge(graph,n,source)+minEdge(graph,n,temporarySolution[0]))/2;
            //find for source and end too note: <2*tempsum/2 = tempsum>
            if (bound<sum)//promising node
                TSP(graph,n,i);
            tempsum -= graph[source][i];//remove the edge from tempsum before returning
            marked[i] = 0;//undo the changes to global variables before proceeding further
        }
    }
    }//undo the changes to global variables before returning
    marked[source]=0;
    tempcount--;
}

//function-main
int main ()
{
    //get the input of a graph
    int n;
    printf ("Enter number of vertices in the graph:");
    scanf ("%d", &n);
    int graph[20][20];
    printf ("Enter the distance matrix of the graph:\n");
    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf ("%d", &graph[i][j]);
    //end of graph input
    //Works for small graphs for which a solution exists
    TSP(graph,n,0);
    printf ("\nShortest path:");
    for (int i =0;i<n;i++)
        printf ("\n%d",optimalSolution[i]);
    printf ("\nshortest path distance:%d",sum);
    return 0;
}
//end of program
/* 
some matrices to test with 

0 10 17 7
10 0 6 2
17 6 0 8
7 2 8 0

0 4 1 6 0
4 0 6 3 0
1 6 0 6 2
6 3 6 0 5
0 0 2 5 0

0 10 15 20  
10 0 35 25  
15 35 0 30 
20 25 30 0 

0 3 4 2 7
3 0 4 6 3
4 4 0 5 8
2 6 5 0 6
7 3 8 6 0

0 20 30 10 11
15 0 16 4 2
3 5 0 2 4
19 6 18 0 3
16 4 7 16 0

0 5 0 6 5 4
5 0 2 4 3 0
0 2 0 1 0 0
6 4 1 0 7 0
5 3 0 7 0 3
4 0 0 0 3 0
*/
