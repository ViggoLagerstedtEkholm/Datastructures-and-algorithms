#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

Vertex* createVertex(int x, int y) {
    Vertex* aVertex = (Vertex*)malloc(sizeof(Vertex));
    if (aVertex != NULL) {
        aVertex->size = 0;
        aVertex->headEdge = NULL;
        aVertex->x = x;
        aVertex->y = y;
    }
    return aVertex;
}

Graph* createGraph(int vertices) {

    Graph* aGraph = (Graph*)malloc(sizeof(Graph));
    assert(aGraph != NULL);
    aGraph->vertices = vertices;

    aGraph->Adj_List = (AdjList*)malloc(vertices * sizeof(AdjList));

    for (int i = 0; i < vertices; i++) {

        Vertex* v1 = createVertex(0, 0);
        v1->Name = i;
        assert(aGraph->Adj_List != NULL);

        aGraph->Adj_List[i].head = v1;
    }

    return aGraph;
}


void printGraph(Graph* graph)
{
    int v;
    for (v = 0; v < graph->vertices; ++v)
    {
        Vertex* adjacencyVertex = graph->Adj_List[v].head;
        printf("\n Adjacency list of vertex %d head \n", v);
   
        printf("-> %d", adjacencyVertex->Name);
        Edge* edgeInVertex = adjacencyVertex->headEdge;

        for (int i = 0; i < adjacencyVertex->size; i++) {
            if (edgeInVertex != NULL) 
            {
                printf(" -> Edge to -> %d \n", edgeInVertex->pointsTo->Name);
                edgeInVertex = edgeInVertex->next;
            }
        }
        
        printf("\n");
    }
}

int getNumVertices(Graph* graph) {
    return graph->vertices;
}

Edge* createEdge() {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    assert(edge != NULL);
    edge->pointsFrom = NULL;
    edge->pointsTo = NULL;
    edge->next = NULL;
    return edge;
}

void addDirectedEdge(Vertex* v1, Vertex* v2, float weight) {

    Edge* edgeBetweenV1AndV2 = createEdge();

    edgeBetweenV1AndV2->pointsTo = v2;
    edgeBetweenV1AndV2->pointsFrom = v1;
    edgeBetweenV1AndV2->weight = weight;

    if (v1->headEdge == NULL) {
        v1->headEdge = edgeBetweenV1AndV2;
    }
    else {
        edgeBetweenV1AndV2->next = v1->headEdge;
        v1->headEdge = edgeBetweenV1AndV2;
    }

    v1->size++;
}

void addUndirectedEdge(Vertex* v1, Vertex* v2, float weight) {
    addDirectedEdge(v1, v2, weight);
    addDirectedEdge(v2, v1, weight);
}

int getNumEdges(Graph* graph) {

    int numberOfEdges = 0;

    for (int i = 0; i < graph->vertices; i++) {
        numberOfEdges = numberOfEdges + graph->Adj_List[i].head->size;
    }

    return numberOfEdges;
}

int hasEdge(Vertex* v1, Vertex* v2) {

    int hasEdge = 0;

    Edge* edge = v1->headEdge;
    
    for (int i = 0; i < v1->size; i++) {
        if (edge->pointsTo == v2) {
            hasEdge = 1;
        }
        edge = edge->next;
    }
    if (v2 != NULL) {
        Edge* edge2 = v2->headEdge;

    for (int i = 0; i < v2->size; i++) {
        if (edge2->pointsTo == v1) {
            hasEdge = 1;
        }
        edge2 = edge2->next;
        }
    }

    return hasEdge;
}

List* getNeighbors(Graph* graph, Vertex* vertex) 
{
    List* list = createLinkedList();

    for (int j = 0; j < graph->vertices; j++)
    {
        int verticesSize = graph->Adj_List[j].head->size;

        Edge* edge = graph->Adj_List[j].head->headEdge;

        for (int i = 0; i < verticesSize; i++)
        {
            Node* node = createNode();

            if (edge->pointsFrom == vertex )
            {
                node->data = edge->pointsTo;
                if (search(list, node->data) == NULL) {
                    insert(list, node);
                }
            }
            if(edge->pointsTo == vertex)
            {
                node->data = edge->pointsFrom;
                if (search(list, node->data) == NULL) {
                    insert(list, node);
                }
            }
            edge = edge->next;

        }
    }

    return list;
}


List* getInNeighbors(Graph* graph, Vertex* vertex) {

    List* list = createLinkedList();

    for (int j = 0; j < graph->vertices; j++)
    {
        int verticesSize = graph->Adj_List[j].head->size;
        Edge* edge = graph->Adj_List[j].head->headEdge;

        //Add data.
        Node* node = createNode();
        node->data = graph->Adj_List[j].head;

        for (int i = 0; i < verticesSize; i++)
        {
            if (edge->pointsTo == vertex) {
                insert(list, node);
            }
            edge = edge->next;
        }
    }
    return list;
}


List* getOutNeighbors(Graph* graph, Vertex* vertex) {

    List* list = createLinkedList();

    for (int j = 0; j < graph->vertices; j++)
    {
        int verticesSize = graph->Adj_List[j].head->size;
        Edge* edge = graph->Adj_List[j].head->headEdge;
        
        for (int i = 0; i < verticesSize; i++)
        {
            Node* node = createNode();

            if (edge->pointsFrom == vertex) {
                node->data = edge->pointsTo;
                insert(list, node);
            }
            edge = edge->next;
            node = node->next;
        }
    }
    return list;
}

int bellmanford(Graph* graph, Vertex* source) {
    int hasCycle = 0;
    for (int i = 0; i < graph->vertices; i++) {
        graph->Adj_List[i].head->PI = NULL;
        graph->Adj_List[i].head->distance = (float)INT_MAX;
    }

    source->distance = 0;

    for (int i = 0; i < graph->vertices - 1; i++)
    {
        for (int i = 0; i < graph->vertices; i++)
        {
            Vertex* u = graph->Adj_List[i].head;
            Edge* edgeBetweenUandV = u->headEdge;

            while (edgeBetweenUandV != NULL) {
                float weight = edgeBetweenUandV->weight;

                if (edgeBetweenUandV->pointsTo->distance > edgeBetweenUandV->pointsFrom->distance + weight)
                {
                    edgeBetweenUandV->pointsTo->distance = edgeBetweenUandV->pointsFrom->distance + weight;
                    edgeBetweenUandV->pointsTo->PI = edgeBetweenUandV->pointsFrom;
                }

                edgeBetweenUandV = edgeBetweenUandV->next;
            }
        }
    }

    for (int i = 0; i < graph->vertices; i++)
    {
        Vertex* u = graph->Adj_List[i].head;
        Edge* edgeBetweenUandV = u->headEdge;

        while (edgeBetweenUandV != NULL) {
            float weight = edgeBetweenUandV->weight;

            //Relax
            if (edgeBetweenUandV->pointsTo->distance > edgeBetweenUandV->pointsFrom->distance + weight)
            {
                return hasCycle = 1;
            }

            edgeBetweenUandV = edgeBetweenUandV->next;
        }
    }
    return hasCycle;
}

void printBellmanFord(Graph* graph) {
    printf("Distance from source to vertex \n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d \t\t %f\n", i, graph->Adj_List[i].head->distance);
    }
}

void createMap(Graph* graph) {
    const int width = 10;
    const int height = 10;

    int map[10][10] = { 0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , -1, -1, -1, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, -1 , 0, 0, 0, 0,
                        0, -1, -1, -1, -1, -1 , 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0 , 0, 0, 0, 0 };

    Vertex* vArr[10][10];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            printf("%d ", map[x][y]);
        }
        printf("\n");
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            vArr[x][y] = createVertex(-1, -1);
        }
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            //The (x,y) we're on is a wall, don't add edges...
            if (map[x][y] != -1) {
                //Is the top neighbor out of bounds?
                int isBottomY = y - 1 < 0 ? 1 : 0;

                //Is the bottom neighbor out of bounds?
                int isTopY = y + 1 > height - 1 ? 1 : 0;

                //Is the left neighbor out of bounds?
                int isLeftMinX = x - 1 < 0 ? 1 : 0;

                //Is the right neighbor out of bounds?
                int isRightMaxX = x + 1 > width -1 ? 1 : 0;

                //There are 4 possible edges that we can find, 
                //top (y + 1), 
                //bottom (y - 1), 
                //left (x - 1), 
                //right (x + 1)

                //Check bounds.
                if (isBottomY == 0) {
                    if (map[x][y - 1] == 0) {
                        Vertex* centerVertex = createVertex(x, y);
                        Vertex* topVertex = createVertex(x, y - 1);
                        vArr[x][y] = centerVertex;

                        addDirectedEdge(centerVertex, topVertex, 1);
                        printf("Adding edge between: (%d, %d) -> (%d, %d)\n" , centerVertex->x, centerVertex->y, topVertex->x, topVertex->y);
                    }
                }

                //Check bounds.
                if (isTopY == 0) {
                    if (map[x][y + 1] == 0) {
                        Vertex* centerVertex = createVertex(x, y);
                        Vertex* bottomVertex = createVertex(x, y + 1);
                        vArr[x][y] = centerVertex;


                        addDirectedEdge(centerVertex, bottomVertex, 1);
                        printf("Adding edge between: (%d, %d) -> (%d, %d)\n", centerVertex->x, centerVertex->y, bottomVertex->x, bottomVertex->y);
                    }
                }

                //Check bounds.
                if (isLeftMinX == 0) {
                    if(map[x - 1][y] == 0){
                        Vertex* centerVertex = createVertex(x, y);
                        Vertex* leftVertex = createVertex(x - 1, y);
                        vArr[x][y] = centerVertex;

                        addDirectedEdge(centerVertex, leftVertex, 1);
                        printf("Adding edge between: (%d, %d) -> (%d, %d) \n", centerVertex->x, centerVertex->y, leftVertex->x, leftVertex->y);
                    }
                }

                //Check bounds.
                if (isRightMaxX == 0) {
                    if (map[x + 1][y] == 0) {
                        Vertex* centerVertex = createVertex(x, y);
                        Vertex* rightVertex = createVertex(x + 1, y);
                        vArr[x][y] = centerVertex;

                        addDirectedEdge(centerVertex, rightVertex, 1);
                        printf("Adding edge between: (%d, %d) -> (%d, %d) \n", centerVertex->x, centerVertex->y, rightVertex->x, rightVertex->y);
                    }
                }
            }
        }
        printf("\n");
    }

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (vArr[x][y] != NULL) {
                Vertex* vertex = vArr[x][y];
                if (vertex->x != -1 && vertex->y != -1) {
                    printf("( %d , %d )", vertex->x, vertex->y);
                    //printf("( O )");
                }
                else {
                    printf("(   X   )");

                }
            }
        }
        printf("\n");
    }

    printGraph(graph);
}


