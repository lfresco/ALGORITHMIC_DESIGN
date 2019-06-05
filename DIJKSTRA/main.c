#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "dijkstra.h"
#include "heap.h"


int main () {
   
    
    printf("------ TEST FOR GRAPH 1 -------------\n");
    graph *g = build_graph();
    add_edge(g, 0, 1, 7);
    add_edge(g, 0, 2, 9);
    add_edge(g, 0, 4, 14);
    add_edge(g, 1, 2, 10);
    add_edge(g, 1, 3, 15);
    add_edge(g, 2, 3, 11);
    add_edge(g, 2, 5, 2);
    add_edge(g, 3, 4, 6);
    add_edge(g, 4, 5, 9);
    printf(" Expected 11 acf\n");
    printf(" Dijkstra Heap : ");
    dijkstra_heap(g, 0, 5);
    printf("Dijkstra Array : ");
    dijkstra(g, 0, 5);
    printf("----------- END TEST FOR GRAPH 1 ----------\n");   
    free(g);
    
    graph * huge = BuildRandomGraph(100, 10, 20);
    
    dijkstra_heap(huge, 0, 3);
    dijkstra(huge, 0,3);
    
    huge = BuildRandomGraph(150, 30, 40);
    dijkstra_heap(huge, 0, 3);
    dijkstra(huge, 0,3);
    
    huge = BuildRandomGraph(300, 50, 10);
    dijkstra_heap(huge, 0, 3);
    dijkstra(huge, 0,3);
    
    
    huge = BuildRandomGraph(1000, 90, 20);
    dijkstra_heap(huge, 0, 3);
    dijkstra(huge, 0,3);
    

    freeGraph(huge);
    
    
    return 0;
}