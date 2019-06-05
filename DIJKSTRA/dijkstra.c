#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "graph.h"
#include "dijkstra.h"
#include "heap.h"

void print_array_nodes(const array* Queue)
{
    for(int i = 0; i < Queue -> size; i++)
    {
        node * current = Queue -> nodes[i];
        
        printf(" %d ", current -> id);
    }
}



void init_ssp(graph * g){

    for(int i = 0; i < (g->nodes_len); i++){
        
        node * current = (g -> nodes[i]);
        if(current != NULL){
          current->dist = 1000;
          current->prev = 0;
        }
    }
}

void relax_array(node* u, node* v, edge * e){
    int new_dist = u ->dist + e -> weight;
    int old_dist = v -> dist;

    if(new_dist < old_dist){
        v -> dist = new_dist;
        v -> prev = u -> id;
    }
}


array*  build_array(graph * g){
    int size = g->nodes_len;
    node ** nodes_array = (node**)malloc(size * sizeof(node*)); // allocate memory to store the values
    for(int i = 0; i < size; i++){
        nodes_array[i] = g->nodes[i];
    }

    array *Q=(array *)malloc(sizeof(array));
    Q -> nodes = nodes_array;
    Q -> size = size;
    Q -> original_size = size;

    return Q;
}

void remove_node_array(array* Queue, int min_index){
    
    int size = (Queue) ->size;
    node * tmp = (Queue) -> nodes[min_index];
    (Queue)->nodes[min_index] = (Queue)->nodes[size - 1];
    (Queue)->nodes[size - 1] = tmp;

    (Queue)->size --; 
}


int is_empty_array(const array* Queue){
    if(Queue -> size > 0){
        return 0;
    } else {
        return 1;
    }
}


node * extract_minimum_array(array * Queue){
    // I must find the minimum and then remove it
    //print_array_nodes(*Queue);
    //print_array_nodes(Queue);
    
    long int min = (Queue -> nodes[0])->dist;
    int min_index = 0;

    for(int i = 1; i < Queue->size; i++){
        node * tmp = Queue -> nodes[i];
        if(tmp ->dist < min){
            min_index = i;
            min = tmp ->dist;
        }
    }

    node * return_node = Queue->nodes[min_index];
    remove_node_array(Queue, min_index);

    return return_node;
}



void dijkstra(graph *g, int a, int b){

    init_ssp(g); // WE initialize all the needed values
    int a_i = a ;
    int b_i = b ;
    node * source = g -> nodes[a_i]; // we get the source 

    source -> dist = 0; // and set its distance to zero

    array * Q = build_array(g);
    
    
  
    
    while(!is_empty_array(Q)){
        
        node * u = extract_minimum_array(Q);
         
        if(u -> id == b_i) break;
        
        int n = u -> edges_len;
        for(int j = 0; j < n; j++){
            
            edge * e = u -> edges[j];
            
            int node_id = e -> node;
            node * v = g->nodes[node_id];

            relax_array(u, v, e);
            

        }
        
        

     
    }  
    
     
    print_path(g, b);

}


void dijkstra_heap(graph * g, int a, int b)
{
    init_ssp(g); // WE initialize all the needed values
    int a_i = a;
    int b_i = b;
    node * source = g -> nodes[a_i]; // we get the source 

    source -> dist = 0; // and set its distance to zero
    
    heap * Queue = BuildHeap(g);
    
    
    
    
    while(Queue -> size > 0)
    {
        node * u = extract_minimum_heap(Queue);
        
        if(u -> id == b_i) break;
  
        int n = u -> edges_len;
        
        for(int j = 0; j < n; j++)
        {
            
            
            edge * e = u -> edges[j];
            
            
            int node_id = e -> node;
            node * v = g -> nodes[node_id];
            
            int new_dist = u ->dist + e -> weight;
            int old_dist = v -> dist;

            if(new_dist < old_dist){
                
                
                v -> dist = new_dist;
                v -> prev = u -> id;
                
                //hswap(Queue, 0, node_id);
                
                Heapify(Queue, 0);
               /**
               printf("-------------\n");
               for(int i = 0; i < Queue -> size; i++)
               printf("%d has dist %d\n", i, Queue -> nodes[i]->dist);
               */
            }
        }
        
       
       
    }
    
    
    //freeHeap(Queue);
    //freeArray(Queue);
    
    print_path(g, b);
    
    

}


/**
void dijkstra_heap(graph * g, int a, int b)
{
    init_ssp(g); // WE initialize all the needed values
    int a_i = a;
    int b_i = b;
    node * source = g -> nodes[a_i]; // we get the source 

    source -> dist = 0; // and set its distance to zero
    
    heap * Queue = BuildHeap(g);
    
    printf("Expected 0 got %d\n ", Queue -> nodes[0] -> dist);
    
    
    while(Queue -> size > 0)
    {
        
        node * u = Queue -> nodes[0];
        
        hswap(Queue, 0, Queue -> size - 1);
        Queue -> size --;
        
        
        
        //node * u = extract_minimum_heap(Queue);
        
        if(u -> id == b_i) break;
  
        int n = u -> edges_len;
        
        for(int j = 0; j < n; j++)
        {
            
            
            edge * e = u -> edges[j];
            
            
            int node_id = e -> node;
            node * v = g -> nodes[node_id];
            
            int new_dist = u ->dist + e -> weight;
            int old_dist = v -> dist;

            if(new_dist < old_dist){
                
                
                v -> dist = new_dist;
                v -> prev = u -> id;
                
                
                
                Heapify(Queue, 0);
               /**
               printf("-------------\n");
               for(int i = 0; i < Queue -> size; i++)
               printf("%d has dist %d\n", i, Queue -> nodes[i]->dist);
               
            }
        }
        
       
       
    }
    
    
    //freeHeap(Queue);
    //freeArray(Queue);
    
    print_path(g, b);
    
    

}
*/


void print_path (graph *g, int i) {
    int n, j;
    node *v, *u;
    i = i ;
    v = g->nodes[i];
    if (v->dist == 1000) {
        printf("no path\n");
        return;
    }
    n = 1;
    u = v;
    while(u -> dist > 0)
    {
        n++;
        u = g -> nodes[u -> prev];
    }
    
    int *path = malloc(n * sizeof(int));
    path[n - 1] =  i;
    j = 0;
    
    u = v;
    while(u -> dist > 0)
    {
        path[n - j - 2] =  u -> prev;
        j++;
        u = g -> nodes[u -> prev];
    }

      
    printf("%d ", v->dist);
    printf(" %d ", path[0]);
    for( int i = 1; i < n; i++)
      printf("  -> %d ", path[i]);
    
    printf("\n");
}



void freeArray(array* Queue)
{
    for(int i = 0; i < Queue -> original_size; i++)
        freeNode(Queue -> nodes[i]);
        
    free(Queue);
}



