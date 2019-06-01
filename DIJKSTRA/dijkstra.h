

#ifndef DIJKSTRA_H__
#define DIJKSTRA_H__

#include "heap.h"

typedef struct
{
  node **nodes;
  int size;
} array;




/**
 * @breif Given a graph and a source the algorithm will find the shortest path between 
 *        the two nodes used as parameters. Uses an array based queue
 *        
 * @param graph g , is the graph we are wo
 * rking with
 * @param char a, the source 
 * @param char b, the destination node
 * 
 */
void dijkstra (graph * g, char a, char b);

/**
 * @breif Given a graph and a source the algorithm will find the shortest path between 
 *        the two nodes used as parameters. Uses an min-heap based queue
 *
 * @param graph g , is the graph we are working with
 * @param char a, the source 
 * @param char b, the destination node
 * 
 */

void dijkstra_heap(graph * g, char a, char b);

/**
 * @brief the initialitation of the graph useful for the solution of the dijkstra
 *        algorithm
 * 
 * @param graph g, the graph we want to initialize 
 */
void init_ssp (graph * g);

/**
 * @brief used inside the dijkstra algorithm to continue the search.
 * 
 * @param array * Queue, the queue. Contains all the nodes and it
 * 
 */
node *extract_minimum (array * Queue);

/**
 * @brief used inside the extract_minimum routine to perform a node removal
 * 
 * @param array * Queue, the queue containing the nodes
 * @param int min_index, the index relative to the node we want to remove
 * 
 */
void remove_node (array * Queue, int min_index);

/**
 * @brief from a given graph it builds a array based queue
 * 
 * @param graph * g, the graph we want to buil the queue from
 * 
 */
array* build_array (graph * g);

/**
 * @ breif used to update distance inside the dijkstra routine
 * 
 * @ param node * v, the node whose distance we want to update
 * @ int new_dist, the updated distance from the source
 */
 void update_distance (node * v, int new_dist);
 
 
 /**
  * @breif  used to update distance from the source, if a shortest path 
  *         has been found
  * 
  * @param u, the current node
  * @param v, all the possible neighbours
  * @param e, the edge that connects them
  */
void relax_array (node * u, node * v, edge * e);
 
/**
 * @brief used at the end of the execution of the dijkstra algorithm
 * 
 * @ param g, the graph with the updated distances
 * @ param i, the destination node
 * 
 */
void print_path (graph *g, int i);

 
/**
 * @brief check if there are still nodes inside the queue
 * 
 * @param Queue, the Queue, whose size we want to check
 * 
 */
int is_empty_array(const array* Queue);
 
#endif //DIJKSTRA_H__