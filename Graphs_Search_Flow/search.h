#ifndef SEARCH_CPP
#define SEARCH_CPP

#include <iostream>
#include "Graph.h"

//////////////////////////////////////////////////////////////////////////////////
/// Implements Graph Search routines in modern C++11
//////////////////////////////////////////////////////////////////////////////////

template<typename NData, typename EData>
std::tuple<bool, PathPtr<NData,EData>> dijkstra(
    const GraphPtr<NData,EData>& graph, 
    const NodePtr<NData,EData>& src, 
    const NodePtr<NData,EData>& dest
) {

}

template<typename NData, typename EData>
std::tuple<bool, PathPtr<NData,EData>> bellmanFord(
    const GraphPtr<NData,EData>& graph, 
    const NodePtr<NData,EData>& src, 
    const NodePtr<NData,EData>& dest
) {

}

template<typename NData, typename EData>
std::tuple<bool, Matrix<EData>> floydWarshall(
    const GraphPtr<NData,EData>& graph, 
    const NodePtr<NData,EData>& src, 
    const NodePtr<NData,EData>& dest
) {

}

#endif