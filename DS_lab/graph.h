#ifndef GRAPH_H
#define GRAPH_H

struct _Graph {
    int **adjacencyMatrix;
    int numberOfVertices;
    int numberOfEdges;
    char *vertices;
};

typedef struct _Graph* Graph;



int **get2dArray(int rows, int cols);
void printGraphMatrix(Graph g);
Graph createGraphAdjacencyMatrix();

#endif