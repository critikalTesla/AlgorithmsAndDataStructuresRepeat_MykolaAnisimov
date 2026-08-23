#include <iostream>
#include <string>

#include "Graph.h"

int main()
{
    Graph gameWorld;

    std::cout << "Creating the five-room game world...\n\n";

    // TODO 1 completed:
    // Add the five rooms to the graph.
    gameWorld.AddLocation("Middle Room");
    gameWorld.AddLocation("Top Room");
    gameWorld.AddLocation("Bottom Room");
    gameWorld.AddLocation("Left Room");
    gameWorld.AddLocation("Right Room");

    // TODO 2 completed:
    // Connect every outside room to the middle room.
    gameWorld.AddConnection("Middle Room", "Top Room");
    gameWorld.AddConnection("Middle Room", "Bottom Room");
    gameWorld.AddConnection("Middle Room", "Left Room");
    gameWorld.AddConnection("Middle Room", "Right Room");

    // TODO 3 completed:
    // Display the original graph.
    gameWorld.DisplayGraph();

    // TODO 4 completed:
    // Search for an existing room.
    std::string roomToFind = "Top Room";

    std::cout << "\nSearching for: "
        << roomToFind << "\n";

    if (gameWorld.Search(roomToFind))
    {
        std::cout << roomToFind
            << " was found in the graph.\n";
    }
    else
    {
        std::cout << roomToFind
            << " was not found in the graph.\n";
    }

    // Search for a room.
    roomToFind = "Secret Room";

    std::cout << "\nSearching for: "
        << roomToFind << "\n";

    if (gameWorld.Search(roomToFind))
    {
        std::cout << roomToFind
            << " was found in the graph.\n";
    }
    else
    {
        std::cout << roomToFind
            << " was not found in the graph.\n";
    }

    // TODO 5 completed:
    // Remove the connection to the right room.
    std::cout << "\nRemoving the connection between "
        << "Middle Room and Right Room...\n";

    gameWorld.RemoveConnection(
        "Middle Room",
        "Right Room"
    );

    // TODO 6 completed:
    // Display the graph after removing the connection.
    gameWorld.DisplayGraph();

    std::cout << "\nPress Enter to close the program...";
    std::cin.get();

    return 0;
}