#include <iostream>
#include "Node.h" 


int main(){

    Node node_a(1, true),
         node_b(2, false),
         node_c(3, true),
         clust_a(4, true),
         clust_b(5, true);

    // Connect some nodes
    std::cout << "node_a degree = " << node_a.degree << "\n";
    Node::connect_nodes(&node_a, &node_b);
    Node::connect_nodes(&node_a, &node_c);
    std::cout << "node_a degree = " << node_a.degree << "\n";
    std::cout << "node_b degree = " << node_b.degree << "\n";
    
    std::cout << "clust_a num members = " << clust_a.members.size() << "\n";
    clust_a.add_member(&node_a);
    clust_a.add_member(&node_b);
    std::cout << "clust_a num members = " << clust_a.members.size() << "\n";

    return 0;
}