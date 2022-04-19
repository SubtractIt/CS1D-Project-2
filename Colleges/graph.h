#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include "collegehashmap.h"

#define INF std::numeric_limits<float>::max()

///
/// @brief   Represents a weighted graph using adjacency list representation
/// @details vertices are college ids, and edges are disances in miles
///
class WeightedGraph {
private:
    std::unordered_map<int, std::vector<std::pair<int, float>>> adjList;
    int numVertices;

    ///
    /// @brief   Helper function for DFS (dfs needs map of visited vertices)
    /// @param   v         vertex to start DFS from
    /// @param   visited   map of visited vertices
    /// @param   path      vector of vertices in order of traversal
    /// @param   distances vector of distances from start vertex
    ///
    void dfsUtil(int v,
                 std::unordered_map<int, bool> &visited,
                 std::vector<int> &path,
                 std::vector<float> &distances);

public:
    ///
    /// @brief Initializes the number of vertices to 0
    ///
    WeightedGraph();
    ///
    /// @brief Empty
    ///
    ~WeightedGraph();

    ///
    /// @brief Adds the colleges of a CollegeHashMap to the graph using their
    ///        ids as vertices and distances to other colleges as edge weights
    /// @param collegeMap Map of colleges to add
    /// @param ids        Ids of the colleges for indexing into the map
    ///
    void addColleges(const CollegeHashMap& collegeMap,
                     const std::vector<int>& ids);

    ///
    /// @brief Adds a vertex to the graph
    /// @param v The vertex to add
    ///
    void addVertex(int v);

    ///
    /// @brief Adds an edge to the graph or updates its weight if already exists
    /// @param v      The vertex to add the edge to
    /// @param w      The vertex to add the edge from
    /// @param weight The weight of the edge
    ///
    void addEdge(int v, int w, float weight);

    ///
    /// @brief Removes an edge from the graph
    /// @param v The vertex to remove the edge from
    /// @param w The vertex to remove the edge to
    ///
    void removeEdge(int v, int w);

    ///
    /// @brief Removes a vertex from the graph (and all edges connected to it)
    /// @param v The vertex to remove
    ///
    void removeVertex(int v);

    ///
    /// @brief Prints the graph
    ///
    void printGraph() const;

    ///
    /// @brief  Gets the neighbors of a vertex
    /// @param  v The vertex to get the neighbors of
    /// @return A vector of the neighbors of the vertex
    ///
    std::vector<int> getNeighbors(int v);

    ///
    /// @brief  Gets the weight of an edge
    /// @param  v The vertex to get the weight of the edge from
    /// @param  w The vertex to get the weight of the edge to
    /// @return The weight of the edge or -1 if no such edge exists
    ///
    float getWeight(int v, int w);

    ///
    /// @brief  Gets the number of vertices in the graph
    /// @return The number of vertices in the graph
    ///
    int getNumVertices() const;

    ///
    /// @brief  Performs a depth first search on the graph, choosing the next
    ///         adjacent vertex to visit based on the distance from the source
    /// @param  source    The vertex to start the search from
    /// @param  path      vector of the vertices in the order they were visited
    /// @param  distances vector of the distances from the source to each vertex
    ///
    void dfs(int v,
             std::vector<int> &path,
             std::vector<float> &distances);

    ///
    /// @brief  Performs a breadth first search on the graph, sorting the
    ///         neighbors by distance from the source and then visiting them
    /// @param  source    The vertex to start the search from
    /// @param  path      vector of the vertices in the order they were visited
    /// @param  distances vector of the distances from the source to each vertex
    ///
    void bfs(int v,
             std::vector<int> &path,
             std::vector<float> &distances);

    ///
    /// @brief Calclates the shortest paths from a vertex to all other vertices
    /// @param v     the vertex to calculate the shortest paths from
    /// @param paths the shortest paths from v to all other vertices
    /// @param costs the costs of the shortest paths starting from v
    ///
    void dijkstra(int v,
                  std::unordered_map<int, std::vector<int>>& shortestPaths,
                  std::unordered_map<int, float>& costs);
};

#endif // GRAPH_H_
