# Algorithm for searching through a graph
- Data structures:
    - Array called `stack`
    - Array called `visitedNodes`
## Algorithm
### Start
- Pop adjacent nodes of the root node into the `stack`
- Add the root node to the `visitedNodes`
### Visiting a node
- Choose a node in the `stack` to visit
- append it to `visitedNodes`
- remove it from `stack`
- append its adjacent nodes to `stack`
### If no adjacent node
- move back a node and visit another unvisited adjacent node
- Repeat until `stack` is empty

## Representing a maze as a graph
- Create a maze struct based on a .txt file using the `create_maze(...)` function in `maze.c`
- Once created 

# Coding Aspects:
- adding a GUI -> GTK