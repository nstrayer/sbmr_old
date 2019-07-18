#include <random>
#include <map>
#include "Node.h" 

using std::string;
using std::vector;
using std::map;

// Setup random number generation
std::random_device rand_dev;
std::mt19937 generator(rand_dev());

// Define an edge map for ease of reading
typedef map<string, Edge> EdgeMap;


// =======================================================
// Constructor that takes the nodes unique id integer and type
// =======================================================
Node::Node(string node_id, bool type_a):
  id(node_id),
  is_type_a(type_a),
  degree(0){}


// =======================================================
// Add connection to edge map
// =======================================================
void Node::add_edge(Node* node_ptr) {
  EdgeMap::iterator edge_to_add;
  
  // Try and find the node in edges.
  edge_to_add = edges.find(node_ptr->id);
  
  // Is there already a connection to this node?
  bool already_connected = edge_to_add != edges.end();
  
  if(already_connected){
    // If there is already a connection just iterate the count up
    edge_to_add->second.count++;
  } else {
    // Otherwise add a whole new edge to edges map.
    Edge new_edge;
    new_edge.node = node_ptr;
    new_edge.count = 1;
    edges[node_ptr->id] = new_edge;
  }
  
  // Increment the degree of the node up
  degree++;
}          


// =======================================================
// Remove a connection from edge map
// =======================================================
void Node::remove_edge(Node* node_ptr, bool remove_all){
  int num_edges;
  bool single_edge;
  EdgeMap::iterator edge_to_delete;
  
  // Try and find the node in edges.
  edge_to_delete = edges.find(node_ptr->id);
  
  // Is there already a connection to this node?
  bool node_in_edges = edge_to_delete != edges.end();
  
  // If edge exists, remove it.
  if(node_in_edges){
    num_edges = edge_to_delete->second.count;
    single_edge = num_edges == 1;
    
    if(remove_all | single_edge){
      // If we're removing all the edges erase from map
      edges.erase(edge_to_delete);
      degree -= num_edges;
    } else {
      // Otherwise simple remove one edge but keep map entry
      edge_to_delete->second.count--;
      degree--;
    }
  }
}      


// =======================================================
// How many total edges to another node?
// =======================================================
int Node::num_edges_to_node(Node* node_ptr){
  EdgeMap::iterator edge_to_find;

  // Try and find the node in edges.
  edge_to_find = edges.find(node_ptr->id);
  
  bool edge_exists = edge_to_find != edges.end();
  
  if(edge_exists){
    // Edge exists
    return edge_to_find->second.count;
  } else {
    return 0;
  }
} 


// =======================================================
// Find a random neighbor node
// =======================================================
Node* Node::get_random_neighbor(){
  std::uniform_int_distribution<int> distr(0, edges.size()-1); 
  int random_map_index = distr(generator);
  
  EdgeMap::iterator edge_grabber = edges.begin();
  std::advance(edge_grabber, random_map_index);
  
  return edge_grabber->second.node;
}    


// =======================================================
// Add a node to the members map
// =======================================================
void Node::add_member(Node* node_ptr){
  // Add node to member map
  members[node_ptr->id] = node_ptr;
  
  // Set cluster membership for node 
  node_ptr->cluster = this;
} 


// =======================================================
// Swap current cluster with a new one
// =======================================================
void Node::swap_clusters(Node* new_cluster_ptr){
  // Remove self from old clusters members
  cluster->members.erase(id);
  
  // Add self to new cluster's members
  new_cluster_ptr->add_member(this);
}


// =======================================================
// Get how many edges to all represented neighbor clusters
// =======================================================
vector<string> Node::neighbor_clusters(){
  EdgeMap::iterator  edges_it;             // Iterator for going through all edges
  vector<string>               neighbor_clusters;    // Returned vector of neighbor cluster ids
  
  neighbor_clusters.reserve(edges.size());
  for(edges_it = edges.begin(); edges_it != edges.end(); edges_it++){
    neighbor_clusters.push_back(edges_it->second.node->cluster->id);
  }
 
  return neighbor_clusters;
}


// =======================================================
// Static method to connect two nodes to each other with edge
// =======================================================
void Node::connect_nodes(Node* node_a_ptr, Node* node_b_ptr){
  // Add edge to node a
  node_a_ptr->add_edge(node_b_ptr);
  node_b_ptr->add_edge(node_a_ptr);
}