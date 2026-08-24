# Project Analysis

[Return to README](README.md)

## Table of Contents

- [Introduction](#introduction)
- [Project Result](#project-result)
- [Analysis of the Graph Structure](#analysis-of-the-graph-structure)
- [Analysis of the Main Operations](#analysis-of-the-main-operations)
- [Time Complexity](#time-complexity)
- [Space Complexity](#space-complexity)
- [Testing](#testing)
- [Advantages](#advantages)
- [Limitations](#limitations)
- [Possible Improvements](#possible-improvements)
- [What I Learned](#what-i-learned)
- [Conclusion](#conclusion)

## Introduction

This document analyses the result of my Game World Graph project. The project uses a graph data structure to represent five rooms in a simple game world.

The program was created in C++ using an adjacency list. It can add rooms, connect rooms, search for a room, remove a connection and display the complete graph.

The main goal was to create a simple example that shows how graphs can be used in game development.

More information about the project can be found in the [Project Overview](overview.md).

## Project Result

The final program succesfully creates the following five rooms:

- Middle Room
- Top Room
- Bottom Room
- Left Room
- Right Room

The Middle Room is connected to all four outside rooms:

```text
                    Top Room
                        |
                        |
Left Room ------- Middle Room ------- Right Room
                        |
                        |
                   Bottom Room
```

The program demonstrates all of the planned graph operations.

It first displays the complete graph, searches for two rooms, removes one connection, and then displays the updated graph.

The result shows that the graph data structure is working correctly for this small example.

## Analysis of the Graph Structure

The project uses an undirected and unweighted graph.

The graph contains:

- Five vertices.
- Four edges.
- One central vertex.
- Four outside vertices.

The Middle Room has a degree of four because it connects to four other rooms.

Before removing a connection, each outside room has a degree of one because it only connects to the Middle Room.

| Room | Degree before removal |
|---|---:|
| Middle Room | 4 |
| Top Room | 1 |
| Bottom Room | 1 |
| Left Room | 1 |
| Right Room | 1 |

The sum of all vertex degrees is:

```text
4 + 1 + 1 + 1 + 1 = 8
```

In an undirected graph, the sum of all degrees should be two times the number of edges:

```text
2 × 4 edges = 8
```

This confirms that the original graph structure is correct.

After removing the connection between the Middle Room and Right Room, the degrees become:

| Room | Degree after removal |
|---|---:|
| Middle Room | 3 |
| Top Room | 1 |
| Bottom Room | 1 |
| Left Room | 1 |
| Right Room | 0 |

The graph then contains three edges, and the total degree is:

```text
3 + 1 + 1 + 1 + 0 = 6
```

This is equal to:

```text
2 × 3 edges = 6
```

The Right Room still exists as a vertex, but it becomes disconnected from the rest of the graph.

## Analysis of the Main Operations

### Adding a room

The `AddLocation()` method checks whether the room already exists before adding it.

This is useful because duplicate rooms could create problems in the game world. For example, two vertices with the same name would make it difficult to know which room should be used.

The method gives a clear console message when a duplicate is detected.

### Adding a connection

The `AddConnection()` method completes several checks before changing the graph.

It checks that:

- The first room exists.
- The second room exists.
- The rooms are not the same.
- The connection does not already exist.

These checks make the program more reliable and prevent invalid graph data.

The connection is added in both directions becouse the graph is undirected.

### Searching for a room

The `Search()` method checks whether a room name exists as a key in the `unordered_map`.

The program demonstrates two possible results:

```text
Top Room was found in the graph.
Secret Room was not found in the graph.
```

This proves that the method can recognise an existing room and correctly reject a room that was not added.

However, this method only searches for a room by name. It does not search for a route between two different rooms.

### Removing a connection

The `RemoveConnection()` method removes a connection from both neighbour lists.

When the connection between the Middle Room and Right Room is removed:

- Right Room is removed from the Middle Room’s list.
- Middle Room is removed from the Right Room’s list.

This is important because removing only one direction would make the graph inconsistant.

The method does not delete the Right Room. It only removes the edge, so the room remains in the adjacency list with no connections.

### Displaying the graph

The `DisplayGraph()` method loops through every vertex and prints its neighbour list.

This makes it possible to compare the graph before and after removing an edge.

One limitation is that the display order is not fixed. This happens because the graph uses an `unordered_map`.

The connections are still correct even if the rooms appear in a different order.

## Time Complexity

The performance of the main operations depends on the containers and algorithms used.

In the following table:

- `V` means the number of vertices.
- `E` means the number of edges.
- `d` means the number of neighbours connected to a particular vertex.

| Operation | Average time complexity | Explanation |
|---|---:|---|
| Add a room | `O(1)` | `unordered_map` usually inserts and searches in constant time |
| Search for a room | `O(1)` | The room is searched as an `unordered_map` key |
| Add a connection | `O(d)` | The vector is searched to prevent a duplicate connection |
| Remove a connection | `O(d)` | The method searches and removes values from neighbour vectors |
| Display the graph | `O(V + E)` | Every vertex and connection is visited |

The average performance of `unordered_map` is `O(1)`, but the worst case can be `O(V)` if many keys are placed into the same hash bucket.

For this project, the graph only has five rooms, so the performance difference is not noticable. However, complexity would become more important in a much larger game world.

## Space Complexity

The adjacency list requires approximately:

```text
O(V + E)
```

space.

Each room is stored once as a key. Every undirected edge is stored twice:

```text
Middle Room -> Top Room
Top Room -> Middle Room
```

This means that four undirected edges produce eight neighbour entries.

An adjacency list is suitable for this project because the graph is sparse. The five rooms contain only four of the many connections that could possibly exist.

An adjacency matrix would store every possible connection, including connections that do not exist. This could use more memory for a larger sparse game world.

## Testing

I tested the project by running different valid and invalid operations.

### Test 1: Adding the five rooms

**Action:**

```cpp
gameWorld.AddLocation("Middle Room");
gameWorld.AddLocation("Top Room");
gameWorld.AddLocation("Bottom Room");
gameWorld.AddLocation("Left Room");
gameWorld.AddLocation("Right Room");
```

**Expected result:** All five rooms are added.

**Actual result:** The program displays a message confirming that each room was added.

**Result:** Passed.

### Test 2: Adding a duplicate room

**Action:**

```cpp
gameWorld.AddLocation("Middle Room");
```

**Expected result:** The second Middle Room should not be added.

**Actual result:**

```text
Middle Room already exists.
```

**Result:** Passed.

### Test 3: Adding valid connections

**Action:**

```cpp
gameWorld.AddConnection("Middle Room", "Top Room");
gameWorld.AddConnection("Middle Room", "Bottom Room");
gameWorld.AddConnection("Middle Room", "Left Room");
gameWorld.AddConnection("Middle Room", "Right Room");
```

**Expected result:** Four two-way connections are created.

**Actual result:** The graph shows every outside room connected to the Middle Room.

**Result:** Passed.

### Test 4: Adding a duplicate connection

**Action:**

```cpp
gameWorld.AddConnection("Middle Room", "Top Room");
```

**Expected result:** The connection should not be added twice.

**Actual result:**

```text
Connection between Middle Room and Top Room already exists.
```

**Result:** Passed.

### Test 5: Creating a self-connection

**Action:**

```cpp
gameWorld.AddConnection("Top Room", "Top Room");
```

**Expected result:** The connection should be rejected.

**Actual result:**

```text
A room cannot connect to itself.
```

**Result:** Passed.

### Test 6: Searching for an existing room

**Action:**

```cpp
gameWorld.Search("Top Room");
```

**Expected result:** The method returns `true`.

**Actual result:** The program reports that Top Room was found.

**Result:** Passed.

### Test 7: Searching for a missing room

**Action:**

```cpp
gameWorld.Search("Secret Room");
```

**Expected result:** The method returns `false`.

**Actual result:** The program reports that Secret Room was not found.

**Result:** Passed.

### Test 8: Removing a connection

**Action:**

```cpp
gameWorld.RemoveConnection(
    "Middle Room",
    "Right Room"
);
```

**Expected result:** The connection is removed in both directions.

**Actual result:** Right Room displays no connections, and Right Room is removed from the Middle Room’s neighbour list.

**Result:** Passed.

## Advantages

The main advantages of the project are:

- The graph is simple and easy to understand.
- Room names make the output clear.
- The graph can be expanded with more rooms.
- Duplicate rooms are prevented.
- Duplicate connections are prevented.
- Self-connections are prevented.
- Invalid room names are detected.
- Connections work in both directions.
- The code is seperated into header, implementation and main files.
- The adjacency list is suitable for a sparse game map.

The project also demonstrates several parts of the C++ Standard Library, including `unordered_map`, `vector`, `find`, `remove` and range-based loops.

## Limitations

The current project also has several limitations:

- The program only contains five rooms.
- The user cannot choose operations from a menu.
- Room names are written directly in `main.cpp`.
- The graph is not loaded from a file.
- The graph cannot remove a complete room.
- There is no visual game environment.
- There is no player object.
- There is no pathfinding.
- Connections do not contain weights or distances.
- The program does not check if a path exists between two rooms.
- The output order is not fixed.
- Room names are case-sensitive.

For example, the program would treat these as different names:

```text
Top Room
top room
TOP ROOM
```

## Possible Improvements

A future version could include a console menu such as:

```text
1. Add a room
2. Add a connection
3. Remove a connection
4. Search for a room
5. Display the graph
6. Move the player
7. Exit
```

The project could also add breadth-first search to find the shortest route between rooms.

For example:

```text
Left Room → Middle Room → Top Room
```

Other possible improvements include:

- Depth-first search.
- Weighted edges.
- Locked doors.
- Room descriptions.
- Player movement.
- Enemy navigation.
- Saving and loading.
- Random map generation.
- A graphical user interface.
- Integration with a game engine.

Using an `unordered_set` instead of a `vector` for neighbour lists could also make connection searches faster. However, a vector is easier to understand for this small student project.

## What I Learned

By completing this project, I learned how graphs can be applied to game development.

Before this project, I understood that graphs contained vertices and edges, but this example helped me connect the theory to a game map.

I also learned:

- How to create an adjacency list.
- How `unordered_map` stores keys and values.
- How vectors can store connected vertices.
- How to prevent duplicate data.
- How to use `std::find()`.
- How the erase-remove method works.
- How to use constant references.
- How to seperate a class into `.h` and `.cpp` files.
- Why an undirected edge must be stored in both directions.
- How to analyse time and space complexity.

The most important part was understanding that a room does not need to contain the complete room object. The graph can store the room name and its relationship with other rooms.

## Conclusion

The project achieved its main goal of demonstrating a graph data structure in a game development example.

The application succesfully creates five rooms, creates undirected connections, searches for locations, removes an edge and displays the graph before and after the change.

The adjacency-list design is suitable for this project because it is simple, expandable and memory efficient for a sparse graph.

The current application is basic, but the structure could be developed further into a larger room-navigation or pathfinding system.

## Related Documents

- [README](README.md)
- [Project Overview](overview.md)
- [Design](design.md)
- [Code Explanation](code.md)
- [References](references.md)
