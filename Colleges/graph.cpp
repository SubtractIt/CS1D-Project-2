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

void WeightedGraph::dijkstra(int v,
                     std::unordered_map<int, std::vector<int>>& shortestPaths,
                     std::unordered_map<int, float>& costs) {
    // priority queue to keep track of vertices
    std::priority_queue<std::pair<float, int>,
                        std::vector<std::pair<float, int>>,
                        std::greater<std::pair<float, int>>> pq;
    // distance from the source vertex to a vertex using shortest path
    std::unordered_map<int, float> distances;
    // a vertex's previous vertex in the shortest path
    std::unordered_map<int, int> previous;
    std::unordered_map<int, bool> visited;


    // clear costs and shortest paths
    costs.clear();
    shortestPaths.clear();

    // initialize distances
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        distances[it->first] = INF;
    }
    distances[v] = 0;

    // initialize pq
    pq.push(std::make_pair(0, v));


    // initialize shortest_paths
    shortestPaths.clear();
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        shortestPaths[it->first] = std::vector<int>();
    }
    shortestPaths[v].push_back(v);

    // loop through vertices

    while (!pq.empty()) {
        std::pair<float, int> curr = pq.top();
        pq.pop();

        // if the vertex has been visited, skip it
        if (visited[curr.second]) {
            continue;
        }
        // mark the vertex as visited
        visited[curr.second] = true;

        // loop through neighbors
        for (auto it = adjList[curr.second].begin();
             it != adjList[curr.second].end();
             ++it) {
            // if the distance is less than the current distance, update the
            // distance
            if (distances[it->first] > distances[curr.second] + it->second) {
                // update the distance
                distances[it->first] = distances[curr.second] + it->second;
                // update the previous
                previous[it->first] = curr.second;
                // add the vertex to the priority queue
                pq.push(std::make_pair(distances[it->first], it->first));
            }
        }
    }


    // loop through vertices and display their edges and those edges' weights
    for (auto it = adjList.begin(); it != adjList.end(); ++it) {
        if (it->first == v) {
            continue;
        }

        // loop through the shortest path by backtracking through ancestors
        shortestPaths[it->first].push_back(it->first);
        int curr = it->first;
        while (curr != v) {
            // add the previous vertex to the shortest path (adding to front
            // to preserve order)
            shortestPaths[it->first].insert(shortestPaths[it->first].begin(),
                                            previous[curr]);
            curr = previous[curr];
        }
        // add cost of path
        costs[it->first] = distances[it->first];
    }
}

// Create an MST for the graph, store in a map that holds
// the edges which is passed by reference
void WeightedGraph::mst(std::unordered_map<int, int>& mstVertices, float& totalDist) {

  // Create a priority queue to make sure that all nodes
  // are added to the MST in the proper order
    std::priority_queue<std::pair<float, int>,
                        std::vector<std::pair<float, int>>,
                        std::greater<std::pair<float, int>>> pq;

  // Clear the structure used to hold the MST and
  // clear it to make sure it's empty
  mstVertices.clear();

  // dist is a map modeling the weigts which in this case
  // is distances and used is a map determining
  // if a vertex has been used in the MST yet
  std::unordered_map<int, float> dist(numVertices);
  std::unordered_map<int, bool> used(numVertices);

  // Initialize the maps to unused and nonsense values
  for (auto it = adjList.begin(); it != adjList.end(); ++it) {
    used[it->first] = false;
    dist[it->first] = INF;
  }

  // Getting the id of the first college in map to add to MST
  int v = adjList.begin()->first;

  // Add that first city with a distance of 0 to
  // the priority queue facilitating MST additions
  pq.push(std::make_pair(0, v));
  dist[v] = 0;

  // Continue looping until the priority queue facilititaing addition
  // is empty meaning done
  while(!pq.empty()) {

    // Get the value of the first vertex to be added
    // which is the top of the pq. Now that it is being used
    // remove it and make sure it is unused, if it is used do
    // not want duplicates so move on and if unused then
    // set to used since it now will be and keep iterating
    int u = pq.top().second;
    pq.pop();

    // Do not work on a vertex if it is already used
    if(used[u] == true)
      continue;

    used[u] = true;

    // Looping through all of the neighbors to find which
    // neighbor is closest in which that edge should be added
    for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) {

      // Get the name and distance for the city
      int vert = it->first;
      float weight = it->second;

      // Make sure it is not used and that the distance of this
      // neighbor is the shortest, if so then update the distance
      // and the next vertex in the map and add this new vertex
      // to the pq to be processed
      if(!used[vert] && dist[vert] > weight) {
        dist[vert] = weight;
        mstVertices[vert] = u;
        pq.push(std::make_pair(dist[vert], vert));
      }
    }
  }

  // Get total distance by looping and saccumulating
  totalDist = 0;
  for (const auto& i : mstVertices)
    totalDist += dist[i.first];

  // Outputting the edges and weights
  // ****Comment or uncomment following if want to test output*****
  qInfo() << "\n\nMST\n";
  qInfo() << "Edge : Weight\n";
  qInfo() << "-----------------\n";
  qInfo() << "Total Dist: " << totalDist << "\n";
  for (const auto& i : mstVertices) {
     qInfo() << i.first << " - " << i.second << ": "
             << dist[i.first] << "\n";
  }

}

