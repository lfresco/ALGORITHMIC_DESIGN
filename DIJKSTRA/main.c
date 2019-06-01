#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "dijkstra.h"


int main () {
    graph *g = build_graph();
    add_edge(g, 'a', 'b', 7);
    add_edge(g, 'a', 'c', 9);
    add_edge(g, 'a', 'e', 14);
    add_edge(g, 'b', 'c', 10);
    add_edge(g, 'b', 'd', 15);
    add_edge(g, 'c', 'd', 11);
    add_edge(g, 'c', 'f', 2);
    add_edge(g, 'd', 'e', 6);
    add_edge(g, 'e', 'f', 9);
   
    dijkstra_heap(g, 'a', 'f');
    dijkstra(g, 'a', 'f');
    freeGraph( g );
   
    
    
    return 0;
}