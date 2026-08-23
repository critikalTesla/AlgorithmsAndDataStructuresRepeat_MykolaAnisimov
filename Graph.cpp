#include "Graph.h"

#include <algorithm>
#include <iostream>

void Graph::AddLocation(const std::string& location)
{
    // Check if the location already exists.
    if (adjacencyList.find(location) != adjacencyList.end())
    {
        std::cout << location << " already exists.\n";
        return;
    }

    // Add the location with an empty neighbour list.
    adjacencyList[location] = {};

    std::cout << location << " added.\n";
}

void Graph::AddConnection(
    const std::string& from,
    const std::string& to)
{
    // Check whether the first location exists.
    if (!Search(from))
    {
        std::cout << "Cannot create connection. "
            << from << " does not exist.\n";
        return;
    }

    // Check whether the second location exists.
    if (!Search(to))
    {
        std::cout << "Cannot create connection. "
            << to << " does not exist.\n";
        return;
    }

    // Prevent a room from connecting to itself.
    if (from == to)
    {
        std::cout << "A room cannot connect to itself.\n";
        return;
    }

    // Get the neighbour lists of both rooms.
    std::vector<std::string>& fromNeighbours = adjacencyList[from];
    std::vector<std::string>& toNeighbours = adjacencyList[to];

    // Check whether the connection already exists.
    if (std::find(
        fromNeighbours.begin(),
        fromNeighbours.end(),
        to) != fromNeighbours.end())
    {
        std::cout << "Connection between "
            << from << " and " << to
            << " already exists.\n";

        return;
    }

    // Add the connection in both directions.
    fromNeighbours.push_back(to);
    toNeighbours.push_back(from);

    std::cout << "Connection added: "
        << from << " <-> " << to << "\n";
}

void Graph::RemoveConnection(
    const std::string& from,
    const std::string& to)
{
    // Check whether both rooms exist.
    if (!Search(from) || !Search(to))
    {
        std::cout << "Cannot remove connection. "
            << "One or both rooms do not exist.\n";
        return;
    }

    std::vector<std::string>& fromNeighbours = adjacencyList[from];
    std::vector<std::string>& toNeighbours = adjacencyList[to];

    // Check whether the connection exists.
    auto connection = std::find(
        fromNeighbours.begin(),
        fromNeighbours.end(),
        to
    );

    if (connection == fromNeighbours.end())
    {
        std::cout << "No connection exists between "
            << from << " and " << to << ".\n";
        return;
    }

    // Remove "to" from the neighbour list of "from".
    fromNeighbours.erase(
        std::remove(
            fromNeighbours.begin(),
            fromNeighbours.end(),
            to
        ),
        fromNeighbours.end()
    );

    // Remove "from" from the neighbour list of "to".
    toNeighbours.erase(
        std::remove(
            toNeighbours.begin(),
            toNeighbours.end(),
            from
        ),
        toNeighbours.end()
    );

    std::cout << "Connection removed: "
        << from << " <-> " << to << "\n";
}

bool Graph::Search(const std::string& location) const
{
    // find() returns end() if the location does not exist.
    return adjacencyList.find(location) != adjacencyList.end();
}

void Graph::DisplayGraph() const
{
    std::cout << "\n---------- GAME_WORLD_GRAPH ----------\n";

    // Check whether the graph is empty.
    if (adjacencyList.empty())
    {
        std::cout << "The graph is empty.\n";
        std::cout << "---------------------------------------\n";
        return;
    }

    // Loop through every room in the graph.
    for (const auto& location : adjacencyList)
    {
        std::cout << location.first << " -> ";

        // Check whether the room has any connections.
        if (location.second.empty())
        {
            std::cout << "No connections";
        }
        else
        {
            // Print all neighbours of the room.
            for (std::size_t i = 0;
                i < location.second.size();
                ++i)
            {
                std::cout << location.second[i];

                // Print a comma except after the final neighbour.
                if (i < location.second.size() - 1)
                {
                    std::cout << ", ";
                }
            }
        }

        std::cout << "\n";
    }

    std::cout << "------------------------------------\n";
}