#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <limits>

std::vector<int> djikstra(const std::vector<std::vector<int>> &graph, int start) // returns a co-ordinate and passes a starting point
{
    int n = graph.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max()); // a vector of n elements, all set to max initially
    std::vector<bool> visited(n, false);                       // a vector of n elements, all set to false initially then set to true when visited
    dist[start] = 0;                                           // distance from start to start is 0

    for (int i = 0; i < n; i++)
    {
        int min_dist = std::numeric_limits<int>::max();
        int min_index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_index = j;
            }
        }
        if (min_index == -1)
        {
            break;
        }
        visited[min_index] = true;
        for (int j = 0; j < n; j++)
        {
            if (graph[min_index][j] != 0 && dist[j] > dist[min_index] + graph[min_index][j])
            {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }
    return dist;
}

void visualizeGraph(const std::vector<std::vector<int>> &graph, const std::vector<int> &dist)
{
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {0, 1, 4, 0, 0},
        {1, 0, 4, 2, 7},
        {4, 4, 0, 3, 5},
        {0, 2, 3, 0, 4},
        {0, 7, 5, 4, 0}};
    int start_node = 0;
    std::vector<int> dist = djikstra(graph, start_node);
    std::cout << "Shortest distances from node " << start_node << ":\n";
    for (int i = 0; i < dist.size(); i++)
    {
        std::cout << "Node " << i << ": " << dist[i] << std::endl;
    }
    return 0;
}