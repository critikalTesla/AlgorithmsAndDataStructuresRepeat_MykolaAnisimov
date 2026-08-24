# References

[Return to README](README.md)

## Table of Contents

- [Introduction](#introduction)
- [Graph Theory Sources](#graph-theory-sources)
- [C++ Code References](#c-code-references)
- [Visual Studio References](#visual-studio-references)
- [GitHub and README References](#github-and-readme-references)
- [Project Repository](#project-repository)
- [How the Sources Were Used](#how-the-sources-were-used)
- [Reference List](#reference-list)

## Introduction

This document contains the internet sources used to research graphs, C++ containers, algorithms, Visual Studio and GitHub Markdown formatting.

The sources helped me understand how to design and explain the project. The final code was adapted for my own five-room game world example and was not copied as one complete program from a single website.

All links were last checked on **24 August 2026**.

## Graph Theory Sources

### Boost Graph Theory Review

**Source:** Boost C++ Libraries  
**Page:** Review of Elementary Graph Theory  
**Link:** [https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/about/graph_theory_review.html](https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/about/graph_theory_review.html)

This source explains the main graph theory terms, including:

- Vertices.
- Edges.
- Directed graphs.
- Undirected graphs.
- Vertex degree.
- Paths.
- Adjacency lists.
- Adjacency matrices.
- Breadth-first search.
- Depth-first search.

I used this source to understand the difference between directed and undirected graphs. It also helped me understand why an adjacency list is suitable for a small and sparse graph.

### Boost Graph Interface Primitives

**Source:** Boost C++ Libraries  
**Page:** Graph Interface Primitives  
**Link:** [https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/primitives.html](https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/primitives.html)

This source explains that a graph contains a set of vertices and a set of edges. It also explains how edges work in directed and undirected graphs.

I used this source when designing the connections between the rooms. My project uses an undirected graph, so every room connection works in both directions.

### Boost Adjacency List Documentation

**Source:** Boost C++ Libraries  
**Page:** Adjacency List  
**Link:** [https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/graph_classes/adjacency_list.html](https://www.boost.org/doc/libs/latest/libs/graph/doc/html/graph/graph_classes/adjacency_list.html)

This page contains information about using an adjacency list to store vertices and edges.

My project does not use the Boost Graph Library directly. However, this documentation was useful for understanding the general structure of an adjacency-list graph.

## C++ Code References

### Microsoft `unordered_map` Documentation

**Source:** Microsoft Learn  
**Page:** `unordered_map` Class  
**Link:** [https://learn.microsoft.com/en-us/cpp/standard-library/unordered-map-class?view=msvc-170](https://learn.microsoft.com/en-us/cpp/standard-library/unordered-map-class?view=msvc-170)

This source explains the C++ `unordered_map` container and its main operations.

The project uses an `unordered_map` to store room names and their connected rooms:

```cpp
std::unordered_map<std::string,
    std::vector<std::string>> adjacencyList;
```

I used this documentation to understand:

- How keys and values are stored.
- How `find()` searches for a key.
- How `end()` can be used to check if a key was found.
- How `operator[]` accesses or inserts an element.
- Why the display order is not fixed.

### Microsoft `vector` Documentation

**Source:** Microsoft Learn  
**Page:** `vector` Class  
**Link:** [https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170](https://learn.microsoft.com/en-us/cpp/standard-library/vector-class?view=msvc-170)

This source explains how the C++ `vector` container works.

A vector is used to store each room’s list of neigbours:

```cpp
std::vector<std::string>
```

I used this source to understand:

- How to create a vector.
- How `push_back()` adds an element.
- How `begin()` and `end()` work.
- How `erase()` removes an element.
- How `size()` returns the number of elements.

### Microsoft Algorithm Documentation

**Source:** Microsoft Learn  
**Page:** `<algorithm>` Functions  
**Link:** [https://learn.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=msvc-170](https://learn.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=msvc-170)

This source explains the algorithms available in the C++ Standard Library.

The project uses `std::find()` to search for an existing connection:

```cpp
std::find(
    fromNeighbours.begin(),
    fromNeighbours.end(),
    to
);
```

It also uses `std::remove()` together with `vector::erase()` to remove a connection:

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

This documentation helped me understand how these algorithms work with vectors.

### Microsoft Member Functions Documentation

**Source:** Microsoft Learn  
**Page:** Overview of Member Functions  
**Link:** [https://learn.microsoft.com/en-us/cpp/cpp/overview-of-member-functions?view=msvc-170](https://learn.microsoft.com/en-us/cpp/cpp/overview-of-member-functions?view=msvc-170)

This source explains how functions can be declared as members of a C++ class.

I used this information when seperating the `Graph` class declaration into [`Graph.h`](Graph.h) and the method implementations into [`Graph.cpp`](Graph.cpp).

### Microsoft Class Member Documentation

**Source:** Microsoft Learn  
**Page:** Class Member Overview  
**Link:** [https://learn.microsoft.com/en-us/cpp/cpp/class-member-overview?view=msvc-170](https://learn.microsoft.com/en-us/cpp/cpp/class-member-overview?view=msvc-170)

This source explains the purpose of class data members and member functions.

It helped me understand why the adjacency list should be private while the graph methods should be public.

### Microsoft Input and Output Documentation

**Source:** Microsoft Learn  
**Page:** `iostream`  
**Link:** [https://learn.microsoft.com/en-us/cpp/standard-library/iostream?view=msvc-170](https://learn.microsoft.com/en-us/cpp/standard-library/iostream?view=msvc-170)

This source explains standard console input and output.

The project uses:

```cpp
std::cout
```

to display graph information and:

```cpp
std::cin.get();
```

to wait for the user to press Enter before the program closes.

## Visual Studio References

### Creating Visual Studio C++ Projects

**Source:** Microsoft Learn  
**Page:** Create and Configure Visual Studio C++ Projects  
**Link:** [https://learn.microsoft.com/en-us/cpp/build/creating-and-managing-visual-cpp-projects?view=msvc-170](https://learn.microsoft.com/en-us/cpp/build/creating-and-managing-visual-cpp-projects?view=msvc-170)

This source explains how to create, configure and build a C++ project using Visual Studio.

It was used as a reference for the build and run instructions in the [README](README.md#build-and-run-instructions).

### Installing C++ Support in Visual Studio

**Source:** Microsoft Learn  
**Page:** Install C and C++ Support in Visual Studio  
**Link:** [https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170)

This guide explains how to install the Desktop development with C++ workload in Visual Studio.

This workload is required to build the project using Visual Studio 2022 and the MSVC v143 platform toolset.

## GitHub and README References

### GitHub Basic Writing and Formatting Syntax

**Source:** GitHub Docs  
**Page:** Basic Writing and Formatting Syntax  
**Link:** [https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

This source explains how to format Markdown files on GitHub.

It was used for:

- Headings.
- Paragraphs.
- Bold text.
- Lists.
- Tables.
- Links.
- File links.
- Section links.

For example, a link to another project document is written as:

```markdown
[Project Overview](overview.md)
```

A link to a section in the same file is written as:

```markdown
[Table of Contents](#table-of-contents)
```

### GitHub Code Block Guide

**Source:** GitHub Docs  
**Page:** Creating and Highlighting Code Blocks  
**Link:** [https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/creating-and-highlighting-code-blocks](https://docs.github.com/en/get-started/writing-on-github/working-with-advanced-formatting/creating-and-highlighting-code-blocks)

This source explains how to display code inside GitHub Markdown files.

It was used to show C++ examples with syntax highlighting:

````text
```cpp
gameWorld.AddLocation("Middle Room");
```
