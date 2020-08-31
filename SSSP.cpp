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

// vertex type assumed to be pair<string, int edge_weight>
//typedef  std::pair<std::string,int> stringintpair;
//using neighbor_vector = std::vector<stringintpair>;

// overloading of the less than operator for comparison in priority queue.. 
/* Not working
bool operator<(const stringintpair& lhs,  const stringintpair& rhs){
    return lhs.second > rhs.second;
}
*/

// A better way is using a function object compare (as below)
class mycomparison
{
public:
  //mycomparison();
  bool operator() (const stringintpair& lhs,  const stringintpair& rhs) const
  {
    return (lhs.second >rhs.second);
  }
};


std::unordered_map<std::string, int> SSSP(adj_list_map &adj_list, std::string source){
    std::priority_queue<stringintpair, std::vector<stringintpair>, mycomparison> heap;

    // keep track of visited nodes.. detect when all nodes are visited to quit loop
    // + fast check if a node given by extract_min is duplicate in lazy deletion
    std::unordered_set<std::string> visited; 

    // distance map of node and shortest path
    std::unordered_map<std::string, int> d;
    
    // initialize 
    d[source]= 0;
    heap.push({source, d[source]});


    while(visited.size()< adj_list.size()){  // O(N) iteration
        
        // get the minimum and remove it

        // Since using Lazy deletion, the minimum can be duplicate node
        // so we add a check if this node is already done first
        // the only way a visited node is still in heap is due to previous edge 
        //that never made it to the top of the heap so in total - outer while loop included-  this is O(m)
        // since the heap can grow to m size, all heap operation are O(logM)

        std::string curNode = heap.top().first;  // O(1)
        while(visited.count(curNode)){ 
            std::cout << "Duplicate detected" << std::endl;
            heap.pop(); // O(logM) = O(logN)
            curNode = heap.top().first;
        }

        // Once a new node is found, removeMin from heap
        heap.pop(); // O(logN)
        // label node as visited
        visited.insert(curNode);
        
        std::cout<<  visited.size() << curNode << "\t shortest path " << d[curNode]<< std::endl;

        for (auto adjNode: adj_list.at(curNode)){ // Totality for double loops O(m)
          // calculate the shortest path to each adjacent node
          // min(SP of curNode + edge weight, SP of adjNode)  
          // SP discovered for a node, if any, stored in d.

          // Basic Idea: update the SP key in heap
          // remove the key with value = adjNode and insert the new key, value pair.
          // don"t know the index of the key,value pair to be removed. 

          // soln 1: Use Lazy deletion
          // just insert the new <key, value> pair into the heap


          std::string u = adjNode.first;
          int weight = adjNode.second;

          if (!d.count(u)){
              d[u] = d[curNode]+ weight;
              heap.push({u, d[u]}); // O(logM) = O(logN)
          } else if (d[u]> d[curNode]+ weight)
          {
            d[u] = d[curNode]+ weight;
              heap.push({u, d[u]}); // O(logM) = O(logN)
          }

        }
        
    }
    return d;
}
