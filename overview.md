# Project Overview

[Return to README](README.md)

## Table of Contents

- [Introduction](#introduction)
- [Project Topic](#project-topic)
- [Project Aim](#project-aim)
- [Game World Structure](#game-world-structure)
- [How the Graph Works](#how-the-graph-works)
- [Main Features](#main-features)
- [Why Graphs Are Useful in Games](#why-graphs-are-useful-in-games)
- [Technologies Used](#technologies-used)
- [Conclusion](#conclusion)

## Introduction

This project is a small C++ console application created to demonstrate how a graph data structure can be used in game development. I decided to represent a simple game world containing five rooms.

Each room is represented as a vertex in the graph, while the connection between two rooms is represented as an edge. This creates a basic game map where the player could move between connected locations.

The project was created as part of my study of algorithms and data structures.

## Project Topic

The topic of this project is **Graphs in Game Development**.

Graphs are useful in games because they can represent relationships between different locations or objects. For example, a graph can be used to represent:

- Rooms in a building.
- Locations on a game map.
- Roads connecting cities.
- Levels in a game.
- Dialogue options.
- Quest dependencies.
- Enemy navigation points.

In this project, the graph represents a small game world made from five connected rooms.

## Project Aim

The main aim of this project is to understand how a graph works and how it can be implemented using C++.

The project demonstrates how to:

- Create a graph.
- Add locations to the graph.
- Connect locations together.
- Search for a location.
- Remove a connection.
- Display the complete graph.
- Use a graph to represent a game environment.

## Game World Structure

The game world contains five rooms:

1. Middle Room
2. Top Room
3. Bottom Room
4. Left Room
5. Right Room

The Middle Room is located in the centre. Every outside room is connected directly to the Middle Room.

```text
                    Top Room
                        |
                        |
Left Room ------- Middle Room ------- Right Room
                        |
                        |
                   Bottom Room
```

The outside rooms are not connected directly to each other. This means that the Middle Room works like the main hub of the game world.

For example, travelling from the Left Room to the Right Room would require the player to move through the Middle Room.

More information about the room structure is available in the [Design document](design.md).

## How the Graph Works

The project uses an **undirected graph**. In an undirected graph, a connection works in both directions.

For example, if the Middle Room is connected to the Top Room, it is possible to move:

```text
Middle Room → Top Room
```

It is also possible to move back:

```text
Top Room → Middle Room
```

The graph is stored as an adjacency list using:

```cpp
std::unordered_map<std::string, std::vector<std::string>>
```

The `unordered_map` stores the name of each room. The `vector` connected to each room stores the names of its neighbouring rooms.

A more detailed explanation of the implementation is available in the [Code Explanation](code.md).

## Main Features

The program includes the following methods:

### `AddLocation()`

Adds a new room to the graph. The method checks whether the room already exists before adding it.

### `AddConnection()`

Creates a two-way connection between two rooms. The method also prevents duplicate connections and stops a room from connecting to itself.

### `RemoveConnection()`

Removes the connection between two rooms in both directions.

### `Search()`

Checks whether a room exists in the graph and returns either `true` or `false`.

### `DisplayGraph()`

Displays every room and all rooms directly connected to it.

The program demonstrates these methods automatically when it is started.

## Why Graphs Are Useful in Games

Graphs can be useful for creating maps and navigation systems in games. A room or location can be represented as a vertex, while a path between two locations can be represented as an edge.

A larger version of this project could be used to:

- Check whether a player can travel to another room.
- Find the shortest route between two locations.
- Lock or unlock paths during gameplay.
- Create different level routes.
- Allow enemies to navigate around a map.
- Represent fast-travel locations.
- Generate game maps.

This project uses only five rooms, but the same graph structure could be expanded by adding more locations and connections.

## Technologies Used

The project was developed using:

- C++
- Microsoft Visual Studio 2022
- MSVC Platform Toolset v143
- C++ Standard Library
- `std::unordered_map`
- `std::vector`
- `std::find`
- `std::remove`
- Git and GitHub

Instructions for building and running the project are available in the [README](README.md#build-and-run-instructions).

## Conclusion

This project helped me understand how graphs can represent a simple game world. I learned how to store rooms as vertices and connections as edges.

I also learned how to add, search, remove, and display information stored inside an adjacency list. Although this is a console application, the same ideas could later be used in a larger game with player movement, pathfinding, locked rooms, or level navigation.

## Related Documents

- [README](README.md)
- [Design](design.md)
- [Code Explanation](code.md)
- [Analysis](analysis.md)
- [References](references.md)
