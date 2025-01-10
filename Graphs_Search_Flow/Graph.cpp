#include <iostream>
#include <fstream>
#include "Graph.h"

//////////////////////////////////////////////////////////////////////////////////
/// Implements Node and Edge Structs
//////////////////////////////////////////////////////////////////////////////////

template<typename NData, typename EData>
std::ostream& Node<NData,EData>::operator<< (std::ostream& os, const Node<NData,EData>& node) {
    os << data;

    return os;
}

template<typename NData, typename EData> 
std::ostream& Edge<NData,EData>::operator<< (std::ostream& os, const Edge<NData,EData>& edge) {
    os << data;

    return os;
}

//////////////////////////////////////////////////////////////////////////////////
/// Implements Graph Class
//////////////////////////////////////////////////////////////////////////////////

template<typename NData, typename EData>
Graph<NData,EData>::Graph(const bool& directed, const std::string& name) {
    _name = name;
    _directed = std::move(directed); 

    //declare fstream
    _fout.open("graph_" + _name + ".txt", std::ios::out | std::ios::trunc); //opens for writing and overwrites
}

template<typename NData, typename EData>
Graph<NData,EData>::Graph(const Graph<NData,EData>& graph, const std::string& name) {
    _name = graph._name;
    _fout = graph._fout;
    _directed = graph._directed;
    _nodes = graph._nodes;
    _edges = graph._edges;
    _nodeSize = graph._nodeSize;
}

template<typename NData, typename EData>
Graph<NData,EData>& Graph<NData,EData>::operator= (const Graph<NData,EData>& graph) const {
    _name = graph._name;
    _fout = graph._fout;
    _directed = graph._directed;
    _nodes = graph._nodes;
    _edges = graph._edges;
    _nodeSize = graph._nodeSize;
}

template<typename NData, typename EData>
Graph<NData,EData>::~Graph() {
    _fout.close();
}

template<typename NData, typename EData>
std::ostream& Graph<NData,EData>::operator<< (std::ostream& os, const Graph<NData,EData>& graph) const {
    //Print directed/undirected
    os << "Printing " << _directed ? "directed" : "undirected" << "graph: " << _name << "\n";
    _fout << "Printing " << _directed ? "directed" : "undirected" << "graph: " << _name << "\n";
    
    //print node list in 3 cols
    os << "Nodes: ";
    _fout << "Nodes: ";
    std::size_t i = 0;
    for(auto& node : _nodes) {
        os << node << ": ";
        _fout << node;

        bool i = false;
        for(auto& edge : node.edges) {
            os << edge << " ";
            _fout << edge << " ";
        }

        os << "\n";
        _fout << "\n";
    }

    os << "\n";
    _fout << "\n";
    
    return os;
}

template<typename NData, typename EData>
inline std::ofstream& Graph<NData,EData>::getFile() const {
    return _fout;
}

template<typename NData, typename EData>
inline std::size_t Graph<NData,EData>::getNumNodes() const {
    return _numNodes;
}

template<typename NData, typename EData>
inline std::size_t Graph<NData,EData>::getNumEdges() const {
    return _numEdges;
}

template<typename NData, typename EData>
inline bool Graph<NData,EData>::nodeExists(const NodeConstPtr<NData,EData>& node) const {

}

template<typename NData, typename EData>
inline bool Graph<NData,EData>::edgeExists(const NodeConstPtr<NData,EData>& src, const NodeConstPtr<NData,EData>& dest) const {

}

template<typename NData, typename EData>
bool Graph<NData,EData>::addNode(const NodeConstPtr<NData,EData>& node) {

}

template<typename NData, typename EData>
bool Graph<NData,EData>::addEdge(const NodeConstPtr<NData,EData>& src, const NodeConstPtr<NData,EData>& dest) {

}

template<typename NData, typename EData>
bool Graph<NData,EData>::removeNode(const NodeConstPtr<NData,EData>& node) {

}

template<typename NData, typename EData>
bool Graph<NData,EData>::removeEdge(const NodeConstPtr<NData,EData>& src, const NodeConstPtr<NData,EData>& dest) {

}

template<typename NData, typename EData>
template<typename Callback>
bool Graph<NData,EData>::sortNodes(Callback& func) {

}

template<typename NData, typename EData>
template<typename Callback>
bool Graph<NData,EData>::sortEdges(Callback& func) {

}

template<typename NData, typename EData>
template<typename Callback>
bool Graph<NData,EData>::forEachNode(Callback& func) {

}

template<typename NData, typename EData>
template<typename Callback>
bool Graph<NData,EData>::forEachEdge(Callback& func) {

}