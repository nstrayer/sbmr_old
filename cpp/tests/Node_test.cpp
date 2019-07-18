#include <iostream>
#include "Node.h" 

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

    // Connect some nodes
    cout << "I'm running!" << endl;
    cout << "I am running new code, too!" << endl;
   
    return 0;
}
