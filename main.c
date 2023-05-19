
#include "flow.h"

int main() {
    FILE *file;
    file = fopen("network.txt","r");

    int graph[N][N];
    initialize(graph,N);
    fillArray(graph,file);
    int source = 0;
    int destination = N-1;
    printGraph(graph,N);
    // Appeler l'algorithme de Ford-Fulkerson pour trouver le flux maximal dans le graphe
    int maxFlow = fordFulkerson(graph, source, destination);
    // Afficher le flux maximal
    printf("Flux maximal : %d\n", maxFlow);
    return 0;
}
