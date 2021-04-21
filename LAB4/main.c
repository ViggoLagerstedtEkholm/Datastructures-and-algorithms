#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"


int main(int argc, char* argv[]) {	

	//TEST FOR SHOWCASING THE LAB.
	/*
	Graph* graph = createGraph(3);

	addDirectedEdge(graph->Adj_List[1].head, graph->Adj_List[0].head, -3.0);
	addDirectedEdge(graph->Adj_List[0].head, graph->Adj_List[1].head, 2.0);
	addDirectedEdge(graph->Adj_List[1].head, graph->Adj_List[2].head, 1.0);
	addDirectedEdge(graph->Adj_List[2].head, graph->Adj_List[0].head, 1.0);*/
	
	//TEST DATA 1

	
	Graph* graph = createGraph(5);
	
	addDirectedEdge(graph->Adj_List[0].head, graph->Adj_List[3].head, 4.0);
	addDirectedEdge(graph->Adj_List[0].head, graph->Adj_List[2].head, 3.0);
	addDirectedEdge(graph->Adj_List[0].head, graph->Adj_List[1].head, 5.0);

	addDirectedEdge(graph->Adj_List[1].head, graph->Adj_List[4].head, -2.0);

	addDirectedEdge(graph->Adj_List[2].head, graph->Adj_List[1].head, -1.0);
	addDirectedEdge(graph->Adj_List[2].head, graph->Adj_List[4].head, 4.0);

	addDirectedEdge(graph->Adj_List[3].head, graph->Adj_List[2].head, -2.0);
	addDirectedEdge(graph->Adj_List[3].head, graph->Adj_List[4].head, 2.0);
	

	//TEST DATA 2

	/* Here we have a negative weight cycle in the graph, we will return false from the bellman ford algorithm.
	
	addDirectedEdge(graph->Adj_List[0].head, graph->Adj_List[1].head, 3.0);
	addDirectedEdge(graph->Adj_List[1].head, graph->Adj_List[2].head, -9.0);
	addDirectedEdge(graph->Adj_List[2].head, graph->Adj_List[3].head, 2.0);

	addDirectedEdge(graph->Adj_List[3].head, graph->Adj_List[1].head, 4.0);
	addDirectedEdge(graph->Adj_List[3].head, graph->Adj_List[4].head, 1.0);
	*/

	//These are some test for showing the methods in exercise 1.
		
	List* listAllNeigbors = getNeighbors(graph, graph->Adj_List[1].head); //Get all neighbors.
	List* inNeigbors = getInNeighbors(graph, graph->Adj_List[2].head); //Get all the incoming edges.
	List* listOut = getOutNeighbors(graph, graph->Adj_List[0].head); //Get all the outgoing edges.

	printf("ALL \n");
	display(listAllNeigbors);
	printf("\n");

	printf("IN \n");
	display(inNeigbors);
	printf("\n");
	
	printf("OUT \n");
	display(listOut);
	printf("\n");

	printGraph(graph);

	int numEdges = getNumEdges(graph); //Returns number of edges in our graph.
	int numVertices = getNumVertices(graph); //Return number of vertices in our graph.
	int hasEdgeBetweenV1andV2 = hasEdge(graph->Adj_List[1].head, graph->Adj_List[0].head); //Returns 1 if there is a edge between v1->v2 or v2->v1

	printf("NUM OF VERTICES: %d \n", numVertices);
	printf("NUM OF EDGES: %d \n", numEdges);
	printf("HAS EDGE BETWEEN V1 AND V2: %d \n", hasEdgeBetweenV1andV2);

	
	int hasCycle = bellmanford(graph, graph->Adj_List[0].head); //Put the vertex you want as source.
	if (hasCycle == 1) {
		printf("Negative cycle detected! \n");
	}

	printBellmanFord(graph);
	
	return 0;
}