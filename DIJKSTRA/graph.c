#include "graph.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

#define MIN_WEIGHT 5

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
        (g -> nodes[i]) -> dist = 0;
        (g -> nodes[i]) -> edges = NULL;
    }
}
/**
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
*/

void add_edge(graph*g, int a, int b, int w){

    // a is the starting node 
    // b is the arrival node
    // as the nodes will be indicated by means of chars we have to "normalize them"
    int a_i = a;
    int b_i = b;
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


void freeEdge(edge* e)
{
    free( e );
}



void freeNode(node * n)
{
    for(int i = 0; i < n -> edges_len; i++){
       freeEdge( (n -> edges[i]));
       
    }
    free( n -> edges );
    free(n);
}


void freeGraph(graph * g)
{
    for(int i = 0; i < g -> nodes_len; i++)
       freeNode(g -> nodes[i]);
    
    free( g -> nodes );
    free( g );
}


graph * BuildRandomGraph(const int HUGE_N, const int MAX_EDGES, const int MAX_WEIGHT)
{
    graph * g  = build_graph();

    for(int i = 0; i < HUGE_N; i++)
    {
        int n_random_edges = abs((int)((rand()%(2*(MAX_EDGES)) - (MAX_EDGES))));
        
        if(n_random_edges == 0) add_edge(g, i, i, 0);

        for(int j = 0; j < n_random_edges; j++)
        {
            // now for each of the edges we have to create a random destination. 
            // this can be choosen from any node on the graph, even the graph itself. 
            int random_destination = abs((int)((rand()%(2 * (HUGE_N - 1))) - (HUGE_N - 1)));
            int random_weight = abs((int)((rand()%(2*(MAX_WEIGHT)) - (MAX_WEIGHT)))) + MIN_WEIGHT;

            add_edge(g, i, random_destination, random_weight);
        }

    }

    return g;
}

void printHuge(graph * g, const int HUGE_N)
{
    for(int i = 0; i < HUGE_N ; i++)
    {
        node * current = g -> nodes[i];
        if(current == NULL) continue;
        printf ( "%d -> ", current -> id);
        for(int j = 0; j < current -> edges_len; j++)
        {
            printf(" %d -> ", current -> edges[j] -> node);
        }
        
        printf("\n");
    }
}

