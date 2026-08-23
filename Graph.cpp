#include "Graph.h"
#include <iostream>

void Graph::AddLocation(const std::string& location)
{
    // TODO:
    // Check whether location exists.
    // If it doesn't, create an empty neighbour list.
}

void Graph::AddConnection(
    const std::string& from,
    const std::string& to)
{
    // TODO:
    // Because the graph is undirected:
    //
    // Add "to" to the neighbours of "from".
    // Add "from" to the neighbours of "to".
}

void Graph::RemoveConnection(
    const std::string& from,
    const std::string& to)
{
    // TODO:
    // Remove "to" from from's neighbour list.
    // Remove "from" from to's neighbour list.
}

bool Graph::Search(const std::string& location) const
{
    // TODO:
    // Check whether the key exists in adjacencyList.

    return false;
}

void Graph::DisplayGraph() const
{
    // TODO:
    // Loop through every location.
    // Print the location.
    // Then loop through its neighbours and print them.
}