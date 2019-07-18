#include <iostream>
#include "../src/Node.h" 

using namespace std;

int main(){

    Node node_a("n1", true),
         node_b("n2", false),
         node_c("n3", true),
         node_d("n4", true),
         clust_a("c1", true),
         clust_b("c2", true); 

    Node::connect_nodes(&node_a, &node_b);
    Node::connect_nodes(&node_a, &node_c);
    Node::connect_nodes(&node_a, &node_d);
    Node::connect_nodes(&node_b, &node_c);

    // Add members to cluster node
    clust_a.add_member(&node_a);
    clust_a.add_member(&node_b);
    clust_b.add_member(&node_c);
    clust_b.add_member(&node_d);

    cout << "======================================" << endl;
    cout << "node_a.id" << " = " << node_a.id << endl;
    cout << "node_a.cluster->id" << " = " << node_a.cluster->id << endl;
    cout << "node_a.degree" << " = " << node_a.degree << endl;
    cout << "node_a.edges.size()" << " = " << node_a.edges.size() << endl;
    cout << "node_a.num_edges_to_node(&node_b)" << " = " << node_a.num_edges_to_node(&node_b) << endl;
    cout << "node_a.get_random_neighbor()->id" << " = " << node_a.get_random_neighbor()->id << endl;
    cout << "clust_a.members.size()" << " = " << clust_a.members.size() << endl;
    cout << "clust_b.members.size()" << " = " << clust_b.members.size() << endl;
    cout << "node_c.cluster->id" << " = " << node_c.cluster->id << endl;
    // cout << "node_a.neighbor_clusters()" << " = " << node_a.neighbor_clusters() << endl; // is a vector so it cant be printed easily.
   
    return 0;
}
