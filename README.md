# Game World Graph

Game World Graph is a C++ console application that demonstrates how a graph data structure can represent connections between rooms in a game world. The program creates five rooms, connects the four outside rooms to a central room, displays the graph, searches for rooms, removes a connection, and displays the updated result.

**Project topic:** Graphs in Game Development

## Table of Contents

- [Project Overview](overview.md)
- [Design](design.md)
- [Code Explanation](code.md)
- [Analysis](analysis.md)
- [References](references.md)
- [Room Layout](#room-layout)
- [Features](#features)
- [Program Behaviour](#program-behaviour)
- [Project Files](#project-files)
- [Build and Run Instructions](#build-and-run-instructions)
- [Development Environment](#development-environment)
- [Repository](#repository)

## Room Layout

The game world contains five rooms. The Middle Room is the central vertex, and the other four rooms are connected to it.

```text
                    Top Room
                        |
                        |
Left Room ------- Middle Room ------- Right Room
                        |
                        |
                   Bottom Room
```

The graph is undirected, meaning each connection can be followed in both directions. For example, the player could travel from the Middle Room to the Top Room or from the Top Room back to the Middle Room.

For more information about the project structure, see the [Design document](design.md).

## Features

The application demonstrates the following graph operations:

- Adding locations as graph vertices.
- Creating undirected connections between rooms.
- Preventing duplicate rooms and connections.
- Preventing a room from connecting to itself.
- Searching for an existing or missing room.
- Removing a connection between two rooms.
- Displaying every room and its neighbours as an adjacency list.

The graph is stored using:

```cpp
std::unordered_map<std::string, std::vector<std::string>>
```

Each key in the `unordered_map` represents a room, while its associated `vector` contains the names of all directly connected rooms.

A detailed explanation of the implementation is available in the [Code Explanation](code.md).

## Program Behaviour

When the application starts, it automatically:

1. Creates the five rooms.
2. Connects the Top, Bottom, Left, and Right rooms to the Middle Room.
3. Displays the original graph.
4. Searches for `Top Room`.
5. Searches for `Secret Room` to demonstrate an unsuccessful search.
6. Removes the connection between `Middle Room` and `Right Room`.
7. Displays the updated graph.
8. Waits for the user to press Enter before closing.

Because the program uses `std::unordered_map`, the order in which rooms are displayed may vary. This does not affect the graph or its connections.

See the [Analysis document](analysis.md) for an evaluation of the program and its graph operations.

## Project Files

- [`Graph.h`](Graph.h) declares the `Graph` class and its public operations.
- [`Graph.cpp`](Graph.cpp) contains the implementation of the graph methods.
- [`main.cpp`](main.cpp) creates and demonstrates the five-room graph.
- [`GameWorldGraph.sln`](GameWorldGraph.sln) is the Visual Studio solution.
- [`GameWorldGraph.vcxproj`](GameWorldGraph.vcxproj) contains the Visual Studio C++ project configuration.
- [`overview.md`](overview.md) explains the project topic and its connection to game development.
- [`design.md`](design.md) describes the graph structure and room layout.
- [`code.md`](code.md) explains the implementation.
- [`analysis.md`](analysis.md) analyses the program and its graph operations.
- [`references.md`](references.md) lists the sources used during research and development.

## Build and Run Instructions

### Requirements

- Windows 10 or Windows 11.
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/).
- Desktop development with C++ workload.
- MSVC v143 platform toolset.
- Windows 10 SDK or a compatible newer Windows SDK.

### Running with Visual Studio

1. Download or clone the [GitHub repository](https://github.com/critikalTesla/AlgorithmsAndDataStructuresRepeat_MykolaAnisimov).
2. Open [`GameWorldGraph.sln`](GameWorldGraph.sln) in Visual Studio 2022.
3. Select either `Debug` or `Release`.
4. Select either the `x64` or `Win32` platform.
5. Select **Build > Build Solution**, or press `Ctrl + Shift + B`.
6. Confirm that the build completes successfully.
7. Select **Debug > Start Without Debugging**, or press `Ctrl + F5`.
8. Review the graph operations displayed in the console.
9. Press Enter when prompted to close the application.

For information about creating and compiling C++ projects, see the [Microsoft Visual Studio C++ project guide](https://learn.microsoft.com/en-us/cpp/build/creating-and-managing-visual-cpp-projects?view=msvc-170).

## Development Environment

The project was created using:

- Microsoft Visual Studio 2022.
- MSVC Platform Toolset v143.
- C++ Standard Library.
- Windows SDK 10.0.
- Visual Studio C++ Console Application project.

Additional technical sources are listed in [`references.md`](references.md).

## Repository

The complete source code is available in the [AlgorithmsAndDataStructuresRepeat_MykolaAnisimov GitHub repository](https://github.com/critikalTesla/AlgorithmsAndDataStructuresRepeat_MykolaAnisimov).
