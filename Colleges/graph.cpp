#include "graph.h"

WeightedGraph::WeightedGraph() : numVertices(0) {}
WeightedGraph::~WeightedGraph() {}

void WeightedGraph::addColleges(const CollegeHashMap &collegeMap,
                                const std::vector<int>& ids) {
    College curr;
    std::unordered_map<int, float> distances;

    // loop through the colleges in the map using the ids to index
    for (int id : ids) {
        // get the current college
        curr = collegeMap.find(id);

        // add the current college as a vertex in the graph
        addVertex(curr.getID());

        // get the current college's distances to other colleges
        distances = curr.getDistances();

        // loop through the id, distance pairs of the distances
        for (const std::pair<int, float>& edge : distances) {
            // check that the pair isn't for the college itself (i.e. {1, 0}) as
            // it is irrelevant information and would add avoidable bloated
            // error checking to the graph code
            if (edge.first != curr.getID()) {
                // add the edge to the graph (this college's id with the other
                // college's id and the distance between them)
                addEdge(curr.getID(), edge.first, edge.second);
            }
        }
    }
}

void WeightedGraph::addVertex(int v) {
    // open a spot for v in the map
    adjList[v];
    // increment the number of vertices in the graph
    ++numVertices;
}

void WeightedGraph::addEdge(int v, int w, float weight) {
    // if there already exists an edge between v and w, simply update its weight
    bool found = false;
    for (auto& edge : adjList[v]) {
        if (edge.first == w) {
            found = true;
            edge.second = weight;
            break;
        }
    }
    for (auto& edge : adjList[w]) {
        if (edge.first == v) {
            edge.second = weight;
            break;
        }
    }

    // otherwise, add w and its distance from v to v's neighbors and add v and
    // its distance from w to w's neighbors
    if (!found) {
        adjList[v].push_back(std::make_pair(w, weight));
        adjList[w].push_back(std::make_pair(v, weight));
    }
}

void WeightedGraph::removeEdge(int v, int w) {
    // loop through the neighbors of v and if w is found, erase it from v's
    // neighbors
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        if (it->first == w) {
        adjList[v].erase(it);
        break;
        }
    }

    // loop through the neighbors of w and if v is found, erase it from w's
    // neighbors
    // note: if w was found in v's neighbors, then v will certainly be found
    //       in w's neighbors and be erased as well due to the way edges are
    //       added
    for (auto it = adjList[w].begin(); it != adjList[w].end(); ++it) {
        if (it->first == v) {
        adjList[w].erase(it);
        break;
        }
    }
}

void WeightedGraph::removeVertex(int v) {
    // loop through the v's neighbors and remove each edge
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        removeEdge(v, it->first);
    }
    // remove the vertex from the map
    adjList.erase(v);
    // decrement the number of vertices in the graph
    --numVertices;
}

void WeightedGraph::printGraph() const {
    // loop through all vertices
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        // output the vertex
        std::cout << "id: " << it->first << ": ";
        // loop through the vertex's neighbors
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            // output each neighbor and its distance from the current vertex
            std::cout << "{ id: " << it2->first << ", " << it2->second << " } ";
            if ((it2 + 1) != it->second.end()) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}

std::vector<int> WeightedGraph::getNeighbors(int v) {
    std::vector<int> neighbors;
    // add the neighbors of v to the neighbors vector
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        neighbors.push_back(it->first);
    }

    // return the neighbors of v
    return neighbors;
}

float WeightedGraph::getWeight(int v, int w) {
    // loop through the neighbors of v
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        // check if w has been found in the neighbors of v
        if (it->first == w) {
            // return the distance to w from v
            return it->second;
        }
    }
    // return -1 if w was not an adjacent vertex of v
    return -1;
}

int WeightedGraph::getNumVertices() const { return numVertices; }

void WeightedGraph::dfs(int v,
                                    std::vector<int> &path,
                                    std::vector<float> &distances) {
    // clear the path and distances vectors of any previous values
    path.clear();
    distances.clear();
    // create a map to detect which ids have been visited
    std::unordered_map<int, bool> visited;
    // call the private dfs method
    dfsUtil(v, visited, path, distances);
}

void WeightedGraph::dfsUtil(int v,
                            std::unordered_map<int, bool> &visited,
                            std::vector<int> &path,
                            std::vector<float> &distances) {
    // mark the current node as visited
    visited[v] = true;

    // add the current node to the path
    path.push_back(v);
    float minWeight = std::numeric_limits<float>::max();
    int minWeightId = -1;

    // loop through the current node's adjacent nodes and find the closest one
    for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) {
        if (!visited[it->first] && it->second < minWeight) {
            minWeight = it->second;
            minWeightId = it->first;
        }
    }

    // make sure a closest adjacent node was found (will be false if all nodes
    // adjacent to the current one have already been visited or there are no
    // adjancies)
    if (minWeightId != -1) {
        // add distance to chosen next node to the distances
        distances.push_back(minWeight);

        // do a dfs starting from that next node
        dfsUtil(minWeightId, visited, path, distances);
    }
}

void WeightedGraph::bfs(int v,
                        std::vector<int> &path,
                        std::vector<float> &distances) {
    // clear the path and distances vectors of any previous values
    path.clear();
    distances.clear();
    std::unordered_map<int, bool> visited;

    // create a queue for the vertices to visit
    std::queue<int> q;

    // add the starting vertex to the queue
    q.push(v);

    // add the starting vertex to the path
    path.push_back(v);

    // mark the current vertex as visited
    visited[v] = true;

    // continue traversal as long as the queue is not empty
    while (!q.empty()) {
        // get current vertex from front of queue and remove it
        int curr = q.front();
        q.pop();

        // get the neighbors of the current vertex
        std::vector<std::pair<int, float>> neighbors = adjList[curr];

        // sort neighbors by weight
        std::sort(neighbors.begin(), neighbors.end(),
                  [](const std::pair<int, float> &a,
                     const std::pair<int, float> &b) {
                    return a.second < b.second;
                  });

        // add the neighbors to the queue and path and add their respective
        // distances to distances
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
            // check that the neighbor has not yet been visited
            if (!visited[it->first]) {
                // mark the neighbor as visited
                visited[it->first] = true;

                // add the neighbor to the path
                path.push_back(it->first);

                // add the distance to the neighbor to distances
                distances.push_back(it->second);

                // add the neighbor to the queue
                q.push(it->first);
            }
        }
    }
}
