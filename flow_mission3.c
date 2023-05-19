#include "flow.h"

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
void initialize(int i_graph[N][N], unsigned int ui_sizeGraph)
{
    for (int i = 0; i < ui_sizeGraph; i++)
    {
        for (int j = 0; j < ui_sizeGraph; j++)
        {
            i_graph[i][j] = 0;
        }
    }
}
void printGraph(int i_graph[N][N], unsigned int ui_sizeGraph) {
    printf("\n");
    for (int i = 0; i < ui_sizeGraph; i++) {
        for (int j = 0; j < ui_sizeGraph; j++) {
            printf("%d\t", i_graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
void fillArray(int i_graph[N][N], FILE * file)
{
    int i_bowLeft; i_bowLeft = 0;

    int i_bowRight; i_bowRight = 0;

    int i_value; i_value = 0;

    while (1)
    {
        if (fscanf(file, "%d", &i_bowLeft) != EOF)
        {

        } else break;

        if (fscanf(file, "%d", &i_bowRight) != EOF)
        {

        } else break ;

        if (fscanf(file, "%d", &i_value) != EOF)
        {

        } else break;

        //printf("arc g = %d\t", i_bowLeft);
        //printf("arc d = %d\n\n", i_bowRight);

        i_graph[i_bowRight][i_bowLeft] = i_value;
        i_graph[i_bowLeft][i_bowRight] = i_value;
    }
}

// Fonction récursive pour trouver un chemin augmentant dans le graphe résiduel
int findPath(int source, int destination, int residualGraph[N][N], int visited[N], int flow) {
    // Si on a atteint la destination, on renvoie le flux courant
    if (source == destination) {
        return flow;
    }
    visited[source] = 1;
    for (int i = 0; i < N; i++) {
        // Si l'arc existe dans le graphe résiduel et que le sommet n'a pas été visité
        if (residualGraph[source][i] > 0 && visited[i] == 0) {
            // Chercher un chemin augmentant récursivement
            int currentFlow = findPath(i, destination, residualGraph, visited, min(flow, residualGraph[source][i]));
            // Si un chemin augmentant a été trouvé
            if (currentFlow > 0) {
                // Mettre à jour le graphe résiduel et renvoyer le flux courant
                residualGraph[source][i] -= currentFlow;
                residualGraph[i][source] += currentFlow;

                printf("un autre chemin augmentant  a été trouvé, nouveau graphe résiduel :");
                printGraph(residualGraph,N);
                return currentFlow;
            }
        }
    }
    return 0;
}

// Fonction principale de l'algorithme de Ford-Fulkerson
int fordFulkerson(int graph[N][N], int source, int destination) {
    // Initialiser le graphe résiduel avec les mêmes capacités que le graphe d'entrée
    int residualGraph[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            residualGraph[i][j] = graph[i][j];
        }
    }
    // Initialiser le flux maximal à 0
    int maxFlow = 0;
    // Tant qu'il existe un chemin augmentant dans le graphe résiduel
    while (1) {
        // Initialiser le tableau visited pour marquer les sommets visités
        int visited[N] = {0};
        // Chercher un chemin augmentant dans le graphe résiduel
        int flow = findPath(source, destination, residualGraph, visited, INT_MAX);
        // Si aucun chemin augmentant n'a été trouvé, sortir de la boucle
        if (flow == 0) {
            break;
        }
        // Ajouter le flux courant au flux maximal
        maxFlow += flow;
    }
    // Renvoyer le flux maximal
    return maxFlow;
}


