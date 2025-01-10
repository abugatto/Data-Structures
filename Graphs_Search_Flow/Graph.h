#ifndef GRAPH_H
#define GRAPH_H

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/// Implements Adjacency List class in modern C++11
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <queue>
#include <map>

//////////////////////////////////////////////////////////////////////////////////
/// Defines new types for use in the Graph Class
//////////////////////////////////////////////////////////////////////////////////

//Define graph and tree
template<typename NData, typename EData> class Graph;
template<typename NData, typename EData> using GraphPtr = std::shared_ptr<Graph<NData,EData>>;
template<typename NData, typename EData> using GraphConstPtr = std::shared_ptr<Graph<NData,EData> const>;
template<typename NData, typename EData> using Tree = Graph<NData,EData>;
template<typename NData, typename EData> using TreePtr = std::shared_ptr<Tree<NData,EData>>;

//Pointer to nodes and edges so that the data doesn't need to be copied or moved 
template<typename NData, typename EData> struct Node;
template<typename NData, typename EData> struct Edge;
template<typename NData, typename EData> using NodePtr = std::shared_ptr<Node<NData,EData>>;
template<typename NData, typename EData> using EdgePtr = std::shared_ptr<Edge<NData,EData>>;
template<typename NData, typename EData> using NodeConstPtr = std::shared_ptr<Node<NData,EData> const>;
template<typename NData, typename EData> using EdgeConstPtr = std::shared_ptr<Edge<NData,EData> const>;

//Node list and edge lists so that the data doesn't need to be copied or moved when used in other functions
//Nodes should be contiguous in memory for efficiency (object instead of pointer)
//For priority queue without insertion we can use std::sort with lambda compare
template<typename NData, typename EData> using NodeList = std::vector<Node<NData,EData>>;
template<typename NData, typename EData> using EdgeList = std::vector<Edge<NData,EData>>;
template<typename NData, typename EData> using EdgePtrList = std::vector<EdgePtr<NData,EData>>;

//For use in search
template<typename NData, typename EData> using Path = NodeList<NData,EData>;
template<typename NData, typename EData> using PathPtr = std::shared_ptr<Path<NData,EData>>;

//Create iterable priority queues (uses vector w/ lack of allocation overhead vs map)
//Use when insertion is needed during usage
//Objects and data can be captured in lambdas
template<typename Data, typename NData, typename EData> 
struct SortedNodeList : std::priority_queue<Data, NodeConstPtr<NData,EData>> {
    decltype(c.begin()) begin() const { return c.begin(); } //pointer to first object in queue
    decltype(c.end()) end() const { return c.end(); }
};

template<typename Data, typename NData, typename EData> 
struct SortedEdgeList : std::priority_queue<Data, EdgeConstPtr<NData,EData>> {
    decltype(c.begin()) begin() const { return c.begin(); }
    decltype(c.end()) end() const { return c.end(); }
};

//For adjacency matrix or searching algorithms
template<typename T> using Vector = std::vector<T>;
template<typename T> using Matrix = std::vector<Vector<T>>;

//ADD SET TYPES

//////////////////////////////////////////////////////////////////////////////////
/// Implements Node and Edge Structs
//////////////////////////////////////////////////////////////////////////////////

template<typename NData, typename EData>
struct Node {
    NData data;
    EdgePtrList<NData,EData> edges;

    std::ostream& operator<< (std::ostream&, const Node<NData,EData>&);
};

template<typename NData, typename EData>
struct Edge {
    EData weight;
    NodePtr<NData,EData> src;
    NodePtr<NData,EData> dest;
    EdgePtr<NData,EData> twin; //cross link

    std::ostream& operator<< (std::ostream&, const Edge<NData,EData>&);
};

//////////////////////////////////////////////////////////////////////////////////
/// Implements Graph Class
//////////////////////////////////////////////////////////////////////////////////

//Trees and priority queues should be created outside and captured in lambdas
//Functionalities: add, remove, sort, foreach

template<typename NData, typename EData>
class Graph {
    private:
        std::string name;
        bool _directed;
        std::size_t _numNodes, _numEdges;
        NodeList<NData,EData> _nodes; //List of node pointers to iterate through
        EdgeList<NData,EData> _edges; //List of edge pointers to iterate through

    public:


        Graph() = delete;
    

        Graph(const bool&, const std::string&);


        Graph(const GraphConstPtr<NData,EData>&, const std::string&) const;

        Graph& operator= (const Graph<NData,EData>&) const;


        std::ostream& operator<< (std::ostream&, const Graph<NData,EData>&) const;


        inline std::ofstream& getFile() const;


        inline std::size_t getNumNodes() const;


        inline std::size_t getNumEdges() const;


        inline bool nodeExists(const NodeConstPtr<NData,EData>&) const;


        inline bool edgeExists(const NodeConstPtr<NData,EData>&, const NodeConstPtr<NData,EData>&) const;


        bool addNode(const NodeConstPtr<NData,EData>&);         //Use std::move


        bool addEdge(const NodeConstPtr<NData,EData>&, const NodeConstPtr<NData,EData>&);


        bool removeNode(const NodeConstPtr<NData,EData>&);


        bool removeEdge(const NodeConstPtr<NData,EData>&, const NodeConstPtr<NData,EData>&);


        template<typename Callback>
        bool sortNodes(Callback&);


        template<typename Callback>
        bool sortEdges(Callback&);


        template<typename Callback>
        bool forEachNode(Callback&);


        template<typename Callback>
        bool forEachEdge(Callback&);
};

#endif