

#include <stdio.h>
#include <stdbool.h>

#define V 11

int visited[V] = {0};
void depthFirstTraversal(int graph[][V], int u)
{
    visited[u] = 1;             
    printf("%d ", u);           
    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] == 1 && visited[i] == 0)
            depthFirstTraversal(graph, i);       
    }
}

void addEdge(int[][V], int, int);


int main()
{
    int graph[V][V] = {0} ,i,numberofEdges,x,y;


    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 10);
    addEdge(graph, 3, 9);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 8);
    // printf("Enter The Number of Edges:");
    // scanf("%d",&numberofEdges);
    // for (int i = 0; i < numberofEdges; i++){
    //     printf("Enter the X cordinate:");
    //     scanf("%d",&x);
    //     printf("Enter the Y cordinate:");
    //     scanf("%d",&y);
    //     addEdge(graph,x,y);
    //     printf("\n");
    // depthFirstTraversal(graph, 1);

    // }
    printf("\nDepth first traversal from node 1\n");
    depthFirstTraversal(graph, 1);
    return 0;
}
void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}