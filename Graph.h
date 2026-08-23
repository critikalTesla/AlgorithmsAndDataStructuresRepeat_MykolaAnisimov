#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Graph
{
private:
    // Stores each room and a list of rooms connected to it.
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

public:
    // Adds a new room to the graph.
    void AddLocation(const std::string& location);

    // Creates a two-way connection between two rooms.
    void AddConnection(
        const std::string& from,
        const std::string& to
    );

    // Removes a two-way connection between two rooms.
    void RemoveConnection(
        const std::string& from,
        const std::string& to
    );

    // Returns true if the room exists.
    bool Search(const std::string& location) const;

    // Displays every room and its connections.
    void DisplayGraph() const;
};