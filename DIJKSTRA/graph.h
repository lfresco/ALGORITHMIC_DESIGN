#ifndef GRAPH_H__
#define GRAPH_H__



typedef struct
{
  int node;			// the arriving node
  int weight;			// the weight of the edge
} edge;

typedef struct
{
  edge **edges;			// an array storing all the edges to a particular node
  int edges_len;		// number of actual edges "occupied"
  int edges_size;		// allocated memory for the edges vector (used in the adding method)
  int dist;			// used to store the actual distance from the source
  int prev;			// the node we go through to get the minimum distance from the source
  int visited;			// used to keep track of visited nodes
  int id;
} node;


typedef struct
{
  node **nodes;			// nodes of our graphs
  int nodes_len;		// actual nodes
  int nodes_size;		// size of the array of nodes, used in the add method to avoid useless allocations of memory
} graph;
/**
 * 
 * GRAPH FUNCTIONS 
 * 
 * 
 *
 */


/**
 * @brief creates an empty graph 
 */
graph * build_graph();

/**
 * @brief auxiliary function called inside the add-edge function. 
 * 
 * @param g, the graph to which we want to add the node to
 * @param i, the index that will identify the newly added node inside the graph 
 */
void add_node (graph * g, int i);	// called inside the add_edge procedure

/**
 * @brief main function used to add an edge inside our graph. The edge will directed
 * 
 * @param g, the graph
 * @param a, the origin node of the edge
 * @param b, the arriving node
 * @param w, the weigth of the edge
 * 
 */
void add_edge (graph * g, char a, char b, int w);

/**
 * @brief deconstructor for the graph struct
 */
void freeGraph(graph * g);

/**
 * @brief deconstructor for the node struct
 */
void freeNode(node * n);

#endif //GRAPH_H__

