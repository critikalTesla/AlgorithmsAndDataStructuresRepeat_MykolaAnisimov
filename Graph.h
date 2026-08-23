#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Graph
{
private:
    // Store each location and its neighbours here.
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

public:
    void AddLocation(const std::string& location);

    void AddConnection(
        const std::string& from,
        const std::string& to
    );

    void RemoveConnection(
        const std::string& from,
        const std::string& to
    );

    bool Search(const std::string& location) const;

    void DisplayGraph() const;
};