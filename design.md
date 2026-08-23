# Project Design

[Return to README](README.md)

## Table of Contents

- [Introduction](#introduction)
- [Design Goal](#design-goal)
- [Game World Layout](#game-world-layout)
- [Graph Type](#graph-type)
- [Vertices and Edges](#vertices-and-edges)
- [Adjacency List Design](#adjacency-list-design)
- [Class Design](#class-design)
- [Method Design](#method-design)
- [Program Flow](#program-flow)
- [Design Decisions](#design-decisions)
- [Possible Improvements](#possible-improvements)
- [Conclusion](#conclusion)

## Introduction

This document describes the design of my Game World Graph project. The project is a C++ console application that uses a graph data structure to represent five connected rooms.

I designed the project as a simple example of how graphs can be used in game development. Each room is represented as a graph vertex, and each connection between two rooms is represented as an edge.

More general information about the project is available in the [Project Overview](overview.md).

## Design Goal

The main goal was to create a graph that is simple to understand but still demonstrates the important operations of a graph data structure.

The design needed to support the following operations:

- Adding new rooms.
- Connecting two rooms.
- Searching for a room.
- Removing a connection.
- Displaying all rooms and their connections.
- Preventing invalid or duplicate connections.

I selected a five-room layout because it clearly demonstrates how one vertex can connect to several other vertices.

## Game World Layout

The game world contains one room in the middle and four rooms around it.

```text
                    Top Room
                        |
                        |
Left Room ------- Middle Room ------- Right Room
                        |
                        |
                   Bottom Room
```

The Middle Room is the central point of the graph. The Top, Bottom, Left, and Right rooms are all connected to the Middle Room.

The four outside rooms are not directly connected to each other.

To travel between two outside rooms, the player would need to travel through the Middle Room. For example:

```text
Left Room → Middle Room → Right Room
```

This creates a hub-style level layout, where the Middle Room works as the central hub.

## Graph Type

The project uses an **undirected and unweighted graph**.

### Undirected

The graph is undirected because every connection works in both directions.

If the following connection exists:

```text
Middle Room — Top Room
```

The player could move from the Middle Room to the Top Room and from the Top Room back to the Middle Room.

Because of this, every connection is stored in both rooms’ neighbour lists.

### Unweighted

The graph is unweighted because the connections do not contain distance, time, or movement cost values.

Every connection is treated equally. For example, travelling from the Middle Room to the Top Room has the same value as travelling from the Middle Room to the Left Room.

Weights could be added in a future version if different paths needed different travel costs.

## Vertices and Edges

A graph consists of vertices and edges.

### Vertices

The vertices represent the five rooms:

| Vertex | Purpose |
|---|---|
| Middle Room | Central room and main hub |
| Top Room | Room above the Middle Room |
| Bottom Room | Room below the Middle Room |
| Left Room | Room to the left of the Middle Room |
| Right Room | Room to the right of the Middle Room |

### Edges

The edges represent the connections between rooms:

| First room | Second room |
|---|---|
| Middle Room | Top Room |
| Middle Room | Bottom Room |
| Middle Room | Left Room |
| Middle Room | Right Room |

The graph contains:

- Five vertices.
- Four edges.
- One connected component before an edge is removed.

## Adjacency List Design

The graph is stored as an adjacency list.

The data structure is declared in [`Graph.h`](Graph.h):

```cpp
std::unordered_map<std::string, std::vector<std::string>> adjacencyList;
```

The `unordered_map` stores every room using its name as a key. The `vector` stores all rooms directly connected to that room.

The initial adjacency list can be represented like this:

```text
Middle Room -> Top Room, Bottom Room, Left Room, Right Room
Top Room    -> Middle Room
Bottom Room -> Middle Room
Left Room   -> Middle Room
Right Room  -> Middle Room
```

When the connection between the Middle Room and Right Room is removed, the adjacency list becomes:

```text
Middle Room -> Top Room, Bottom Room, Left Room
Top Room    -> Middle Room
Bottom Room -> Middle Room
Left Room   -> Middle Room
Right Room  -> No connections
```

The order of rooms displayed by the application may be different because an `unordered_map` does not store its keys in a fixed order.

## Class Design

The project uses a class called `Graph`.

The class declaration is located in [`Graph.h`](Graph.h), and the method definitions are located in [`Graph.cpp`](Graph.cpp).

The basic class structure is:

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

The adjacency list is private because it should only be changed through the public methods of the `Graph` class.

This protects the graph data and allows the methods to check whether an operation is valid before changing anything.

## Method Design

### `AddLocation()`

The purpose of `AddLocation()` is to add a new room to the graph.

The method:

1. Receives the room name.
2. Uses `find()` to check whether it already exists.
3. Displays a message if the room already exists.
4. Otherwise, adds the room with an empty neighbour list.

Example:

```cpp
gameWorld.AddLocation("Middle Room");
```

### `AddConnection()`

The purpose of `AddConnection()` is to connect two rooms.

The method:

1. Checks whether both rooms exist.
2. Prevents a room from connecting to itself.
3. Checks whether the connection already exists.
4. Adds the second room to the first room’s neighbour list.
5. Adds the first room to the second room’s neighbour list.

Example:

```cpp
gameWorld.AddConnection("Middle Room", "Top Room");
```

Adding the connection in both directions is required because this is an undirected graph.

### `RemoveConnection()`

The purpose of `RemoveConnection()` is to remove an existing connection.

The method:

1. Checks whether both rooms exist.
2. Checks whether the connection exists.
3. Removes the second room from the first room’s neighbour list.
4. Removes the first room from the second room’s neighbour list.

Example:

```cpp
gameWorld.RemoveConnection(
    "Middle Room",
    "Right Room"
);
```

Both entries must be removed to keep the undirected graph correct.

### `Search()`

The purpose of `Search()` is to check whether a room exists.

The method uses `unordered_map::find()` and returns:

- `true` when the room exists.
- `false` when the room does not exist.

Example:

```cpp
bool found = gameWorld.Search("Top Room");
```

### `DisplayGraph()`

The purpose of `DisplayGraph()` is to print the complete adjacency list.

The method:

1. Checks whether the graph is empty.
2. Loops through every room.
3. Prints the room name.
4. Prints every neighbouring room.
5. Displays `No connections` when a room has no neighbours.

Example output:

```text
Middle Room -> Top Room, Bottom Room, Left Room, Right Room
Top Room -> Middle Room
Bottom Room -> Middle Room
Left Room -> Middle Room
Right Room -> Middle Room
```

## Program Flow

The main program is located in [`main.cpp`](main.cpp).

The program follows these steps:

1. Create a `Graph` object called `gameWorld`.
2. Add the five rooms.
3. Add four connections to the Middle Room.
4. Display the original graph.
5. Search for `Top Room`.
6. Search for `Secret Room`.
7. Remove the connection between the Middle Room and Right Room.
8. Display the updated graph.
9. Wait for the user to press Enter.

This flow demonstrates all the main graph methods in one execution.

## Design Decisions

### Using room names as strings

I used strings because names such as `Middle Room` and `Top Room` make the output easy to understand.

Another design could use integer identification numbers, but these would not be as clear when the graph is displayed.

### Using an `unordered_map`

I selected an `unordered_map` because it allows rooms to be found using their names. It is also suitable for storing a key together with an associated value.

The key is the room name, and the value is the room’s neighbour list.

### Using a `vector` for neighbours

I used a `vector` to store the neighbours because it is simple to loop through and display.

The program uses `std::find()` to check whether a connection already exists and `std::remove()` with `erase()` to remove a connection.

### Keeping graph data private

The adjacency list is private, so `main.cpp` cannot modify it directly.

Instead, the program must use methods such as `AddLocation()` and `AddConnection()`. This makes the graph easier to control and prevents some invalid changes.

### Separating the project into files

The project is separated into three main code files:

- [`Graph.h`](Graph.h) contains the class declaration.
- [`Graph.cpp`](Graph.cpp) contains the method implementations.
- [`main.cpp`](main.cpp) demonstrates and tests the graph.

This makes the project more organised and easier to understand.

## Possible Improvements

The current project is a basic graph demonstration. It could be improved by adding:

- A console menu for user interaction.
- A method for removing a room.
- A method for checking whether two rooms are connected.
- Breadth-first search.
- Depth-first search.
- Shortest-path calculation.
- Weighted connections.
- Locked and unlocked doors.
- Different room descriptions.
- Player movement between connected rooms.
- Saving and loading the graph from a file.
- A graphical display of the room layout.

These additions could make the graph work more like a real game navigation system.

## Conclusion

The design uses an undirected adjacency-list graph to represent a simple five-room game world. The Middle Room acts as the central hub, while the other four rooms connect to it.

The `Graph` class keeps the graph data private and provides separate methods for adding, searching, removing, and displaying graph information.

This design is small enough to understand clearly, but it could also be expanded into a larger game map or navigation system.

## Related Documents

- [README](README.md)
- [Project Overview](overview.md)
- [Code Explanation](code.md)
- [Analysis](analysis.md)
- [References](references.md)
