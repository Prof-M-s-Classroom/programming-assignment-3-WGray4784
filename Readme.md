[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
William Gray

## Description
This program is an implementation of Prim's algorithm to find the minimum spanning tree (MST) of a given connected, undirected, and weighted graph. It uses an adjacency matrix to store the edge weights between vertices, and it uses a min heap to store the vertices and edge weights. The min heap is built from a priority queue, which makes sure that the next vertex requiring the lowest cost (edge weight) is next in line to be added to the MST. This ensures that the min heap will help get the correct vertex that can be added to the MST.

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log n)        |
| Extract Min          | O(log n)        |
| Decrease Key         | O(log n)        |
| Prim’s MST Overall   | O(n^2)          |

_Explain why your MST implementation has the above runtime._
* Insert in MinHeap - The time complexity for inserting into the min heap is O(log n), where n is the number of elements in the heap. After the new vertex is added, it must be properly placed into the min heap. Since the while loop splits the possible locations for the vertex to go in half each time through, it runs at O(log n) time.
* Extract Min - The time complexity for extracting the minimum element in the min heap is O(log n). After the minimum element is extracted, the min heap must be fixed to restore the min heap property (parent must be smaller than child). To do this, minHeapify(int idx) is called, which runs at O(log n) time because it recursively fixes the min heap, making the problem smaller and smaller each time through.
* Decrease Key - The time complexity for the function decreaseKey(int vertex, int newKey) is O(log n). This function is very similar to the function for inserting into the min heap since it contains the same while loop that is used to fix the min heap after updating the key of the vertex. This while loop splits the problem in half each time, resulting in O(log n) time.
* Prim's MST Overall - The time complexity for Prim's MST is O(n^2), where n is the number of vertices. Since the algorithm checks all other vertices to find the lowest edge weight for each vertex, it runs at O(n^2) time (n vertices * n checks per vertex = n^2). 

## Test Case Description

Input:  
Graph g(6);  
g.addEdge(0, 1, 4);  
g.addEdge(0, 2, 3);  
g.addEdge(0, 5, 2);  
g.addEdge(1, 2, 1);  
g.addEdge(1, 3, 2);  
g.addEdge(1, 4, 4);  
g.addEdge(2, 3, 4);  
g.addEdge(3, 4, 2);  
g.addEdge(4, 5, 5);  
g.primMST();  
  
Output:  
2--1 (1)  
0--2 (3)  
1--3 (2)  
3--4 (2)  
0--5 (2)  
Total cost: 10