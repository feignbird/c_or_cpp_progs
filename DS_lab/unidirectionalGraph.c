#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

/*

Representations of graph:

Graph shown using Vertices, edges
        b---c
      / |  /|  
    a   | / |
      \ |/  |
        d---e


Graph shown using adjacency matrix
  a, b, c, d, e
a 0  1  0  1  0
b 1  0  1  1  0
c 0  1  0  1  1
d 1  1  1  0  1
e 0  0  1  1  0

*/


int **get2dArray(int rows, int cols){
    int **matrix = (int **)calloc(rows, sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)calloc(cols, sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}


void printGraphMatrix(Graph g){
    printf("     ");
    for(int i=0; i<g->numberOfVertices; i++)
        printf("  %c  ", g->vertices[i]);
    printf("\n");
    for(int j=0; j<g->numberOfVertices; j++){
        printf("  %c  ", g->vertices[j]);
        for(int k=0; k<g->numberOfVertices; k++){
            printf("  %d  ", g->adjacencyMatrix[j][k]);
        }
        printf("\n");
    }
}


Graph createGraphAdjacencyMatrix(){
    Graph graph = (Graph)malloc(sizeof(struct _Graph));
    printf("\nEnter total number of vertices in the graph: ");
    scanf("%d", &(graph->numberOfVertices));
    // printf("\nEnter total number of edges in the graph: ");
    // scanf("%d", &N_EDGES);
    printf("\nEnter vertices characters: ");
    graph->vertices = (char*)calloc(graph->numberOfVertices, sizeof(char));
    for(int i=0; i<graph->numberOfVertices; i++){
        printf("\n\tEnter vertex %d letter (single letter values only): ", i);
        scanf(" %c", &(graph->vertices[i]));
    }
    graph->adjacencyMatrix = get2dArray(graph->numberOfVertices, graph->numberOfVertices);

    short graphType = 1;
    printf("\nType of graph: "
        "\n1. Undirected" 
        "\n2. Directed"
        "\nEnter 1 or 2: ");
    scanf("%hd", &graphType);
    printf("\n");
    short option;
    for(int j=0; j<graph->numberOfVertices; j++){
        for(int k=0; k<graph->numberOfVertices; k++){
            if (graphType == 1 && (j>k || j==k)){
                if (graph->adjacencyMatrix[k][j] != 1)
                    graph->adjacencyMatrix[k][j] = 0;
                graph->adjacencyMatrix[j][k] = graph->adjacencyMatrix[k][j];
                continue;
            }
            printf("\nIs vertex '%c' is connected to '%c' (0 for No)/(1 for Yes) :", graph->vertices[j], graph->vertices[k]);
            scanf("%hd", &option);
            graph->adjacencyMatrix[j][k] = (option!=0?1:0);
        }
    }
    return graph;
}



int main(){
    Graph g = createGraphAdjacencyMatrix();
    printGraphMatrix(g);
    return 0;
}