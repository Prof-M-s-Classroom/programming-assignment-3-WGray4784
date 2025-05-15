#ifndef HEAP_H
#define HEAP_H
using namespace std;

class MinHeap {
public:
    MinHeap(int capacity) { //Constructor
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        for (int i = 0; i < capacity; i++) {
            keyArray[i] = INF;
            position[i] = -1;
        }
    }
    ~MinHeap() {    //Destructor
        delete[] heapArray;
        delete[] keyArray;
        delete[] position;
    }
    void insert(int vertex, int key) {
        if (size == capacity) {
            return;
        }
        heapArray[size] = vertex;   //Inserting new vertex at end of heap
        keyArray[vertex] = key;
        position[vertex] = size;
        size++;

        int current = size-1;
        int parent = (current-1)/2;
        while (current != 0 && keyArray[heapArray[current]] < keyArray[heapArray[parent]]) {    //Fixing min heap
            swap(heapArray[current], heapArray[parent]);
            position[heapArray[current]] = current;
            position[heapArray[parent]] = parent;
            current = parent;
            parent = (current-1)/2;
        }
    }
    int extractMin() {
        if (size == 0) {
            return -1;
        }
        int min = heapArray[0];
        int lastVertex = heapArray[size-1];
        heapArray[0] = lastVertex;   //Removing min
        position[lastVertex] = 0;    //Update position
        position[min] = -1;
        size--;
        minHeapify(0);  //Fix entire heap after min is removed
        return min;
    }
    void decreaseKey(int vertex, int newKey) {
        int current = position[vertex];
        int parent = (current-1)/2;
        keyArray[vertex] = newKey;  //Update key
        while (current != 0 && keyArray[heapArray[current]] < keyArray[heapArray[parent]]) {    //Fixing min heap
            swap(heapArray[current], heapArray[parent]);
            position[heapArray[current]] = current;
            position[heapArray[parent]] = parent;
            current = parent;
            parent = (current-1)/2;
        }
    }
    bool isInMinHeap(int vertex) {  //Checks if heapArray contains vertex
        if (position[vertex] != -1) {
            return true;
        }
        return false;
    }
    bool isEmpty() {    //Checks if the heap is empty
        if (size == 0) {
            return true;
        }
        return false;
    }

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;
    const int INF = 1000000000;

    void minHeapify(int idx) {
        int min = idx;  //Will find minimum vertex
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[min]]) {  //Check if left child is smaller than min
            min = left;
        }
        if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[min]]) {    //Check if right child is smaller than min
            min = right;
        }
        if (min != idx) {   //Swaps min and idx if necessary
            swap(heapArray[idx], heapArray[min]);
            position[heapArray[idx]] = idx;
            position[heapArray[min]] = min;
            minHeapify(min);
        }
    }
};

#endif