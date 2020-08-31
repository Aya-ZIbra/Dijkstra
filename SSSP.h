/** Simple implementation of Dijkstra's algorithm
 * Usage: Single source shortest path (SSSP)
 */

/* Preprocessor directive
"include guard":  prevents the same file from being pasted multiple times into another file
*/
#ifndef SSSP_H
#define SSSP_H
// vertex type assumed to be pair<string, int edge_weight>
typedef  std::pair<std::string,int> stringintpair;
using neighbor_vector = std::vector<stringintpair>;
using adj_list_map = std::unordered_map<std::string, neighbor_vector>;

std::unordered_map<std::string, int> SSSP(adj_list_map &, std::string);

#endif