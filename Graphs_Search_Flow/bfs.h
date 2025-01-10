#ifndef BFS_CPP
#define BFS_CPP

//////////////////////////////////////////////////////////////////////////////////
/// Implements Breadth First Search routines in modern C++11
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Graph.h"

template<typename NData, typename EData>
TreePtr<NData,EData> breadthFirstSearch(const GraphPtr<NData,EData>& graph, const NodePtr<NData,EData>& src) {

}

template<typename NData, typename EData>
std::tuple<TreePtr<NData,EData>, bool> isBipartite(const GraphPtr<NData,EData>& graph) {

}

#endif