#include "graph.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

graph *build_graph()
{
    graph *g=(graph *)malloc(sizeof(graph));
    
    g->nodes_size=0;
    g->nodes_len=0;
    g->nodes=NULL;
    
    return g;
}


void add_node(graph * g, int i){
    //we have to check if we have enough space to store it 
    if((g) -> nodes_size < i +1){
        // the memory allocated is not enough, similar to what happens in push_back of c++ std::vector
        // we need to allocate new memory. 
        int size = g ->nodes_size * 2 > i ? g -> nodes_size * 2 : i + 4;
        // now that we have the dimension we reallocate the memory
        g -> nodes = realloc(g->nodes, size * sizeof(node*));
        // finally we have to put equal to null all the newly allocated nodes
        for(int j = g->nodes_size; j < size; j++){
            g -> nodes[j] = NULL;
        }

        // we can finally update the nodes element of g
        g->nodes_size = size;
    }
    //we can now add the new node 
    if(!(g->nodes[i])){
        g->nodes[i] = calloc(1, sizeof(node));  //allocate memory for a new node
        g-> nodes_len++; //we can update the variable storing the actual number of nodes in our graph
        (g -> nodes[i]) -> id = i;
    }
}

void add_edge(graph*g, char a, char b, int w){

    // a is the starting node 
    // b is the arrival node
    // as the nodes will be indicated by means of chars we have to "normalize them"
    int a_i = a - 'a';
    int b_i = b - 'a';
    // we begin by adding them to our graph, or checking their presence inside the graph;
    add_node(g, a_i);
    add_node(g, b_i);
    // now we start by considering the node a, as in our graph, we only have to set the arriving node

    node* n = g->nodes[a_i];

    // as we did in the add_node procedure we have to check if the reserved memory is enough to store a new node
    if(n ->edges_len >= n->edges_size){
        int size = n->edges_size ? 2 * n->edges_size : 4; // check if it is different from zero as we can add edges to
                                                          // a newly inserted node
        n->edges = realloc(n->edges, size *sizeof(edge*) );
        n -> edges_size = size;

    }
    // we have space, we can now add the new edge to the graph
    edge * e = calloc(1, sizeof(edge));
    e -> node = b_i;
    e -> weight = w;

    n -> edges[n->edges_len++] = e;
    
    
}

void freeNode(node * n)
{
    for(int i = 0; i < n -> edges_len; i++)
       free( n -> edges[i]);
       
    free( n );
}


void freeGraph(graph * g)
{
    for(int i = 0; i < g -> nodes_len; i++)
       freeNode(g -> nodes[i]);
       
    free( g );
}



