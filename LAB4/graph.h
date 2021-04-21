#pragma once

typedef struct Edge_t { // we define our edge
    struct Vertex_t* pointsTo;
    struct Vertex_t* pointsFrom;
    float weight;
    struct Edge_t* next;
}Edge;

typedef struct Vertex_t {     // we define a vertex
    int Name;
    int size;
    float distance;
    int x;
    int y;
    Edge* headEdge;
    struct Vertex_t* PI;
}Vertex;

typedef struct AdjList {
    Vertex* head;
}AdjList;

typedef struct Graph_t { // we define our edge
    AdjList* Adj_List;
    int vertices;
}Graph;


typedef struct Node_t {     // we define a node element
    Vertex* data;
    struct Node_t* next;
    struct Node_t* prev;
} Node;

typedef struct list_element_t { // we define our linked-list element
    int count;
    Node* head;
    Node* tail;
} List;

Node* createNode();
List* createLinkedList();
int insert(List* list, Node* z);
Node* search(List* list, Vertex* key);
Node* delete(List* list, Node* z);
void  freeList(List* list);
Vertex* createVertex(int x, int y);
Graph* createGraph(int vertices);
void printGraph(Graph*);
int getNumVertices(Graph* graph);

void addDirectedEdge(Vertex* v1, Vertex* v2, float weight);
void addUndirectedEdge(Vertex* v1, Vertex* v2, float weight);

int getNumEdges(Graph* graph);
int hasEdge(Vertex* v1, Vertex* v2);
void display(List* list);

List* getNeighbors(Graph* graph, Vertex* vertex);
List* getInNeighbors(Graph* graph, Vertex* vertex); 
List* getOutNeighbors(Graph* graph, Vertex* vertex);

int bellmanford(Graph* graph, Vertex* source);
void printBellmanFord(Graph* graph);
void createMap();