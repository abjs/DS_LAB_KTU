#include <stdio.h>
#include <stdbool.h>
#define V 11

// ====== Stack and its functions ====== //
const int stackSize = 100;
int stack[100];
int top = -1;
void stackPush(int);
int stackPop();
bool stackEmpty();
void depthFirstTraversal(int graph[][V], int u)
{
    int visited[V] = {0};
    stackPush(u);
    int curr_node;
    while (!stackEmpty())
    {
        curr_node = stackPop();
        if (visited[curr_node] == 0)
        {
            printf("%d -> ", curr_node);
            visited[curr_node] = 1;
        }
        for (int i = 0; i < V; i++)
            if (graph[curr_node][i] == 1 && visited[i] == 0)
                stackPush(i);
    }
}
void addEdge(int[][V], int, int);
void printAdjacencyMatrix(int[][V]);
int main()
{
    int graph[V][V] = {0} ,i,numberofEdges,x,y;
    // addEdge(graph, 1, 2);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 3);
    // addEdge(graph, 2, 5);
    // addEdge(graph, 2, 7);
    // addEdge(graph, 2, 8);
    // addEdge(graph, 3, 4);
    // addEdge(graph, 3, 10);
    // addEdge(graph, 3, 9);
    // addEdge(graph, 5, 6);
    // addEdge(graph, 5, 7);
    // addEdge(graph, 5, 8);
    // addEdge(graph, 7, 8);
    printf("Enter The Number of Edges:");
    scanf("%d",&numberofEdges);
    for (int i = 0; i < numberofEdges; i++){
        printf("Enter the X cordinate:");
        scanf("%d",&x);
        printf("Enter the Y cordinate:");
        scanf("%d",&y);
        addEdge(graph,x,y);
        printf("\n");
        printAdjacencyMatrix(graph);
    }
    printf("\nAdjacency matrix\n");
    printAdjacencyMatrix(graph);
    printf("\nDepth first traversal from node 1\n");
    depthFirstTraversal(graph, 1);
    printf("\n");
    return 0;
}

void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void stackPush(int data)
{
    if (top == stackSize - 1)
        return;

    stack[++top] = data;
}

int stackPop()
{
    if (stackEmpty())
        return -1;
    return stack[top--];
}

bool stackEmpty()
{
    return top == -1;
}

// function to print adjacency matrix
void printAdjacencyMatrix(int graph[][V])
{
    for (int k = 0; k <= V; k++)
        printf("%3d ", k);
    printf("\n");
    for (int k = 0; k <= V; k++)
        printf("____");
    printf("\n");
    for (int i = 0; i < V; i++)
    {
        printf("%2d|", i + 1);
        for (int j = 0; j < V; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}