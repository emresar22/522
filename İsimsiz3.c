#include "types.h"

// Graf Oluþturma
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    graph->adj_lists = (CityNode**)malloc(vertices * sizeof(CityNode*));
    graph->visited = (int*)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Þehirler arasý baðlantý (Kenar - Edge) ekleme
void addEdge(Graph* graph, int src, int dest) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    newNode->city_id = dest;
    newNode->next = graph->adj_lists[src];
    graph->adj_lists[src] = newNode;
}

// Sondan 2. rakam tek olduðu için: DFS Algoritmasý
void DFS(Graph* graph, int vertex) {
    CityNode* adjList = graph->adj_lists[vertex];
    CityNode* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Þehir %d ziyaret edildi.\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->city_id;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}
