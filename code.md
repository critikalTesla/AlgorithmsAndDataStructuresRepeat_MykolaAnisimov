# Code Explanation

[Return to README](README.md)

## Table of Contents

- [Introduction](#introduction)
- [Project Files](#project-files)
- [Graph Header File](#graph-header-file)
- [Graph Data Structure](#graph-data-structure)
- [AddLocation Method](#addlocation-method)
- [AddConnection Method](#addconnection-method)
- [RemoveConnection Method](#removeconnection-method)
- [Search Method](#search-method)
- [DisplayGraph Method](#displaygraph-method)
- [Main Program](#main-program)
- [Program Output](#program-output)
- [Conclusion](#conclusion)

## Introduction

This document explains the main code used in my Game World Graph project. The application was created in C++ and demonstrates how a graph can represent connected rooms in a game.

The code is seperated into three main files:

- [`Graph.h`](Graph.h)
- [`Graph.cpp`](Graph.cpp)
- [`main.cpp`](main.cpp)

The header file declares the `Graph` class, the source file contains the method implementations, and the main file creates and tests the game world.

More information about the structure of the project is available in the [Design document](design.md).

## Project Files

### `Graph.h`

The [`Graph.h`](Graph.h) file contains the declaration of the `Graph` class. It shows what information the class stores and what public methods can be called.

### `Graph.cpp`

The [`Graph.cpp`](Graph.cpp) file contains the implementation of every method declared in `Graph.h`.

### `main.cpp`

The [`main.cpp`](main.cpp) file creates a `Graph` object, adds five rooms, connects them, searches for rooms and removes one connection.

## Graph Header File

The `Graph` class is declared in [`Graph.h`](Graph.h):

```cpp
class Graph
{
private:
    std::unordered_map<std::string,
        std::vector<std::string>> adjacencyList;

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
```

The class has one private variable called `adjacencyList`. It also has five public methods that are used to control the graph.

The adjacency list is private, which means it cannot be directly changed from `main.cpp`. This helps protect the data from incorrect changes.

The public methods allow the program to interact with the graph in a controlled way.

## Graph Data Structure

The graph is stored using an `unordered_map` and a `vector`:

```cpp
std::unordered_map<std::string,
    std::vector<std::string>> adjacencyList;
```

The `unordered_map` uses the room name as its key. The `vector` stores the names of all rooms connected to that room.

For example, the Middle Room can contain the following neigbours:

```text
Top Room
Bottom Room
Left Room
Right Room
```

This can be represented like this:

```text
Middle Room -> Top Room, Bottom Room, Left Room, Right Room
```

The required libraries are included at the beginning of `Graph.h`:

```cpp
#include <string>
#include <unordered_map>
#include <vector>
```

The `<string>` library is needed for the room names. The `<unordered_map>` library is needed for the adjacency list, and `<vector>` is needed for each room’s list of connections.

## AddLocation Method

The `AddLocation()` method adds a new room to the graph:

```cpp
void Graph::AddLocation(const std::string& location)
{
    if (adjacencyList.find(location) != adjacencyList.end())
    {
        std::cout << location << " already exists.\n";
        return;
    }

    adjacencyList[location] = {};

    std::cout << location << " added.\n";
}
```

The method receives the room name as a constant reference:

```cpp
const std::string& location
```

Using a reference means the complete string does not need to be copied when the method is called. The `const` keyword means the method cannot change the string that it receives.

The method uses `find()` to check if the location already exists:

```cpp
adjacencyList.find(location)
```

If `find()` does not locate the room, it returns:

```cpp
adjacencyList.end()
```

The following condition checks if the location was found:

```cpp
if (adjacencyList.find(location) != adjacencyList.end())
```

If it was found, the program displays a message and uses `return` to stop the method. This prevents duplicate rooms.

If the room does not exist, it is added with an empty connection list:

```cpp
adjacencyList[location] = {};
```

The method is called in `main.cpp` like this:

```cpp
gameWorld.AddLocation("Middle Room");
```

## AddConnection Method

The `AddConnection()` method creates a connection between two rooms:

```cpp
void Graph::AddConnection(
    const std::string& from,
    const std::string& to)
```

The method receives the names of the two rooms. Before creating the connection, it completes several checks.

### Checking the first room

```cpp
if (!Search(from))
{
    std::cout << "Cannot create connection. "
        << from << " does not exist.\n";
    return;
}
```

The method uses `Search()` to check the existance of the first room. The `!` operator means “not”.

If `Search(from)` returns `false`, the room does not exist and the connection cannot be created.

### Checking the second room

```cpp
if (!Search(to))
{
    std::cout << "Cannot create connection. "
        << to << " does not exist.\n";
    return;
}
```

The same check is completed for the second room.

### Preventing self-connections

```cpp
if (from == to)
{
    std::cout << "A room cannot connect to itself.\n";
    return;
}
```

This prevents a room from creating a connection with itself.

For example, this connection would not be allowed:

```cpp
gameWorld.AddConnection("Top Room", "Top Room");
```

### Accessing the neighbour lists

```cpp
std::vector<std::string>& fromNeighbours =
    adjacencyList[from];

std::vector<std::string>& toNeighbours =
    adjacencyList[to];
```

These references make the code easier to read. They also allow the method to modify the original vectors stored inside the adjacency list.

### Checking for a duplicate connection

```cpp
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
```

The `std::find()` algorithm searches the first room’s neighbour list for the second room.

The search starts at:

```cpp
fromNeighbours.begin()
```

It finishes at:

```cpp
fromNeighbours.end()
```

If the connection is found, the program displays a message and does not add it again.

### Adding the connection

```cpp
fromNeighbours.push_back(to);
toNeighbours.push_back(from);
```

The second room is added to the first room’s list. The first room is also added to the second room’s list.

Both lines are needed becouse the project uses an undirected graph.

For example:

```cpp
gameWorld.AddConnection("Middle Room", "Top Room");
```

Creates both of these connections:

```text
Middle Room -> Top Room
Top Room -> Middle Room
```

## RemoveConnection Method

The `RemoveConnection()` method removes an edge between two rooms:

```cpp
void Graph::RemoveConnection(
    const std::string& from,
    const std::string& to)
```

First, the method checks whether both rooms exist:

```cpp
if (!Search(from) || !Search(to))
{
    std::cout << "Cannot remove connection. "
        << "One or both rooms do not exist.\n";
    return;
}
```

The `||` operator means “or”. The method stops if either room does not exist.

The neighbour lists are then accessed:

```cpp
std::vector<std::string>& fromNeighbours =
    adjacencyList[from];

std::vector<std::string>& toNeighbours =
    adjacencyList[to];
```

The program searches for the connection:

```cpp
auto connection = std::find(
    fromNeighbours.begin(),
    fromNeighbours.end(),
    to
);
```

The `auto` keyword allows the compiler to select the correct iterator type.

If the connection is not found, the method displays a message:

```cpp
if (connection == fromNeighbours.end())
{
    std::cout << "No connection exists between "
        << from << " and " << to << ".\n";
    return;
}
```

The connection is removed from the first neighbour list using:

```cpp
fromNeighbours.erase(
    std::remove(
        fromNeighbours.begin(),
        fromNeighbours.end(),
        to
    ),
    fromNeighbours.end()
);
```

`std::remove()` moves the unwanted value to the end of the vector. The `erase()` method then removes it from the vector.

The opposite connection is removed in the same way:

```cpp
toNeighbours.erase(
    std::remove(
        toNeighbours.begin(),
        toNeighbours.end(),
        from
    ),
    toNeighbours.end()
);
```

Both directions must be removed. If only one direction was removed, the graph would contain inconsistant connection information.

The method is used in `main.cpp` like this:

```cpp
gameWorld.RemoveConnection(
    "Middle Room",
    "Right Room"
);
```

After this operation, the Right Room still exists, but it has no connection to the Middle Room.

## Search Method

The `Search()` method checks whether a room exists:

```cpp
bool Graph::Search(const std::string& location) const
{
    return adjacencyList.find(location) != adjacencyList.end();
}
```

The return type is `bool`, so the method returns either `true` or `false`.

It returns `true` if `find()` locates the room before reaching the end of the `unordered_map`. Otherwise, it returns `false`.

The final `const` means the method does not change the `Graph` object:

```cpp
bool Search(const std::string& location) const;
```

The method can be used inside an `if` statement:

```cpp
if (gameWorld.Search("Top Room"))
{
    std::cout << "Top Room was found.\n";
}
else
{
    std::cout << "Top Room was not found.\n";
}
```

## DisplayGraph Method

The `DisplayGraph()` method prints all rooms and connections:

```cpp
void Graph::DisplayGraph() const
```

The method first prints a heading:

```cpp
std::cout << "\n---------- GAME_WORLD_GRAPH ----------\n";
```

It checks whether the adjacency list is empty:

```cpp
if (adjacencyList.empty())
{
    std::cout << "The graph is empty.\n";
    return;
}
```

The method uses a range-based `for` loop to visit every location:

```cpp
for (const auto& location : adjacencyList)
```

Inside the loop:

- `location.first` is the room name.
- `location.second` is the vector of connected rooms.

The room name is displayed using:

```cpp
std::cout << location.first << " -> ";
```

If the room has no connections, the program displays:

```cpp
std::cout << "No connections";
```

If it has connections, a second loop displays every neighbour:

```cpp
for (std::size_t i = 0;
    i < location.second.size();
    ++i)
{
    std::cout << location.second[i];

    if (i < location.second.size() - 1)
    {
        std::cout << ", ";
    }
}
```

The `if` statement adds a comma after every room except the last one. This makes the output easier to read.

The display order may be different each time becouse `unordered_map` does not keep its keys in a fixed order.

## Main Program

The main program starts by creating a `Graph` object:

```cpp
Graph gameWorld;
```

The five locations are then added:

```cpp
gameWorld.AddLocation("Middle Room");
gameWorld.AddLocation("Top Room");
gameWorld.AddLocation("Bottom Room");
gameWorld.AddLocation("Left Room");
gameWorld.AddLocation("Right Room");
```

The four outside rooms are connected to the Middle Room:

```cpp
gameWorld.AddConnection("Middle Room", "Top Room");
gameWorld.AddConnection("Middle Room", "Bottom Room");
gameWorld.AddConnection("Middle Room", "Left Room");
gameWorld.AddConnection("Middle Room", "Right Room");
```

The graph is displayed using:

```cpp
gameWorld.DisplayGraph();
```

The program searches for an existing room:

```cpp
std::string roomToFind = "Top Room";
```

It also searches for a room that does not exist:

```cpp
roomToFind = "Secret Room";
```

This demonstrates both a succesful and unsuccessful search.

The program then removes one connection:

```cpp
gameWorld.RemoveConnection(
    "Middle Room",
    "Right Room"
);
```

Finally, it displays the graph again:

```cpp
gameWorld.DisplayGraph();
```

The program waits for Enter before it closes:

```cpp
std::cin.get();
```

## Program Output

The exact order of rooms may change, but the first graph should contain these connections:

```text
Middle Room -> Top Room, Bottom Room, Left Room, Right Room
Top Room -> Middle Room
Bottom Room -> Middle Room
Left Room -> Middle Room
Right Room -> Middle Room
```

The program should also display the search results:

```text
Top Room was found in the graph.
Secret Room was not found in the graph.
```

After removing the right connection, the updated graph should contain:

```text
Middle Room -> Top Room, Bottom Room, Left Room
Right Room -> No connections
```

This proves that the connection was removed from both rooms, while the Right Room was not deleted.

## Conclusion

The code demonstrates how an adjacency list can be used to represent a small game world. Every room is stored as a vertex, and each connection is stored as an undirected edge.

The `Graph` class contains seperate methods for adding rooms, creating connections, removing connections, searching, and displaying the graph.

Completing this project helped me understand how C++ containers and algorithms can work together. It also showed me how the same graph structure could later be expanded for player navigation or game level design.

## Related Documents

- [README](README.md)
- [Project Overview](overview.md)
- [Design](design.md)
- [Analysis](analysis.md)
- [References](references.md)
