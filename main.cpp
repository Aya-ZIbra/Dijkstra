/** Simple implementation of Dijkstra"s algorithm
 * Usage: Single source shortest path (SSSP)
 */


#include <iostream>
#include <unordered_map>
#include <vector> 
#include <string>
#include <queue>
#include <unordered_set>


#include "SSSP.h"
#include "Heap.h"


/** graph represented as adjacency list, which can be implemented as unordered map of <vertices, neighbors>
 * neighbors can be linked list, vector, unordered set.
 * hash tables supports find, insert, delete  ?? O(1)
 * Since we are not editing the graph and we are not doing checks (Search) on neighbors,
 * a vector implemenation should suffice.
 * adjacency list (to be added to a graph class)
 * using adj_list_map = std::unordered_map<std::string, neighbor_vector>;
 * alternative type definition: typedef std::unordered_map<int, neigbbor_vector> adj_list_map;
*/
void test_Heap(){
    // Heap test 
    Heap<int> myHeap1;
    std::vector<int> vect(5,100);
    std::cout<< "address of vect = " << &vect << std::endl;
    Heap<int> myHeap2(vect);
    myHeap2.insert(15);
    myHeap2.print(std::cout);
    std::cout << std::endl;
    return;
}
int main(){
    test_Heap();
    // list initialization
    adj_list_map adj_list({
        {"s", neighbor_vector{{"v", 1}, {"w",5}}},
        {"v", neighbor_vector{{"s", 2}, {"w",3},{"u", 6}}},
        {"w", neighbor_vector{{"s", 5}, {"v",3}}},
        {"u", neighbor_vector{{"v", 6}}}
    });
    auto path = SSSP(adj_list, "s");
    std::cout<< "Shortest path of all nodes: " << std::endl;
    for (auto& x: path) std::cout << " " << x.first << ":" << x.second;
    std::cout << std::endl;
}