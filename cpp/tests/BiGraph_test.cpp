#include <iostream>
#include "../src/BiGraph.h" 

using namespace std;

int main(){
    BiGraph my_bigraph;
    my_bigraph.add_edge("a1", "b1");
    my_bigraph.add_edge("a1", "b2");
    my_bigraph.add_edge("a1", "b3");
    my_bigraph.add_edge("a2", "b1");
    my_bigraph.add_edge("a2", "b3");
    my_bigraph.add_edge("a3", "b2");

    cout << "======================================" << endl;
    cout << "my_bigraph.a_nodes.size() = " <<  my_bigraph.a_nodes.size() <<endl;
    cout << "my_bigraph.b_nodes.size() = " <<  my_bigraph.b_nodes.size() <<endl;
    my_bigraph.remove_node("a2", true);
    cout << "my_bigraph.remove_node('a2', true)" <<  my_bigraph.b_nodes.size() <<endl;
    cout << "my_bigraph.a_nodes.size() = " <<  my_bigraph.a_nodes.size() <<endl;

   
    return 0;
}
