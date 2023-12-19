#include <list> // Using a List for our adjacency list.
#include <cstdio>   // Using console printing.
#include <iostream>
#include <limits>   // Using maximum int.
// Bidirectional Weighted Acyclic Graph using an adjacency list.

// Defines and implements an edge with its destination and weight.
class AdjacencyListNode {
  private:
    int _end_node;  // I use "node(s)", "start", and "end" throughout for simplicity.
    int _weight;
  public:
    AdjacencyListNode(int end_node, int weight) {
        _end_node = end_node;
        _weight = weight;
    }
    inline int getVertex() {
        return _end_node;
    }
    inline int GetWeight() {
        return _weight;
    }
    inline std::string toString() {
        return ("end_node: " + std::to_string(_end_node) 
                + " weight: " + std::to_string(_weight));
    }
};
// Defines a graph as a list of verticies with edges who lead to them.
class Graph {
  private:
    // Number of verticies currently stored in the graph.
    size_t _number_of_nodes;
    // For a graph made with adjacency, you use a (linked) list of 
    // pointers so you can add and remove nodes and all their 
    // connections easily.
    std::list<AdjacencyListNode> *_adjacency_list_ptr;
  public:
    Graph(size_t nodes);
    void addEdge(int start_vertex, int end_node, int weight);
    void shortestPath(int start_node);
    std::list<AdjacencyListNode>& getListPtr();
    int getNodes();
};
// Implementation of graph.
Graph::Graph(size_t nodes) {
    _number_of_nodes = nodes;
    _adjacency_list_ptr = new std::list<AdjacencyListNode>[nodes];
}
void Graph::addEdge(int start_node, int end_node, int weight) {
    AdjacencyListNode node(end_node, weight);
    //std::cout << "start_node: " << start_node << " " << node.toString() << std::endl;
    _adjacency_list_ptr[start_node].push_back(node);

    //std::cout << ( _adjacency_list_ptr[start_node].back().toString() ) << std::endl;
    //std::cout << ( _adjacency_list_ptr[start_node].size() ) << std::endl;
}
inline std::list<AdjacencyListNode>& Graph::getListPtr() {
    return *_adjacency_list_ptr;
}
inline int Graph::getNodes() {
    return this->_number_of_nodes;
}
void Graph::shortestPath(int start_node) {
    if (start_node) {}
    // Create an array to store the distance from root to that vertex.
    size_t* path_distance = new size_t[this->_number_of_nodes];
    // Create an array to store the list of verticies for each shortest path.
    // Create a queue of nodes to run through.
    std::list<AdjacencyListNode>*node_queue(this->_adjacency_list_ptr);
    int* previous_hop_nodes = new int[this->_number_of_nodes];
    for (size_t i = 0; i < this->_number_of_nodes; i++) {
        path_distance[i] = std::numeric_limits<int>::max(); // Init to INF
        previous_hop_nodes[i] = 0;
    }
    path_distance[start_node] = 0;
    // Loop through each vertex in the queue.
    while (!node_queue->empty()) {
        // Loop through TODO
    }
}
// Driver
int main() {
    // Create graph given by wikipedia's first example.
    Graph mr_graph(7);  // Which contains six nodes, excluding zero😑.
    mr_graph.addEdge(1, 2, 7);/*
    mr_graph.addEdge(1, 3, 9);
    mr_graph.addEdge(1, 6, 14);
    mr_graph.addEdge(2, 3, 10);
    mr_graph.addEdge(2, 4, 15);
    mr_graph.addEdge(3, 6, 2);
    mr_graph.addEdge(3, 4, 11);
    mr_graph.addEdge(4, 5, 6);
    mr_graph.addEdge(5, 6, 9);*/

    int root = 1;
    std::cout << "Shortest path order from node " << root << " to:" << std::endl;
    // Dijkstra's Algorithm finds the shortest path between a starting node and
    // and all other nodes in a any variation of an acyclic graph.
    mr_graph.shortestPath(root);
    //std::cout << (mr_graph.getListPtr().size() + 1) << std::endl;
    //std::cout << mr_graph.getNodes() << std::endl;
    return 0;
}