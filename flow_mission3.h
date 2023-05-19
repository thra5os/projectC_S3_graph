#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 14

int min(int a, int b) ;

void fillArray(int i_graph[N][N], FILE * file);

void initialize(int i_graph[N][N], unsigned int ui_sizeGraph);

void printGraph(int i_graph[N][N], unsigned int ui_sizeGraph);

int findPath(int source, int destination, int residualGraph[N][N], int visited[N], int flow) ;

int fordFulkerson(int graph[N][N], int source, int destination) ;

