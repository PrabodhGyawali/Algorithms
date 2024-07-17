#include <iostream>
#include <climits>

using namespace std;

void swap(int* x, int* y);

class MinHeap {
    int* harr; 
    int capacity; 
    int heap_size; 
public:
    MinHeap(int capacity);
    // to heapify a subtree with the root at given index
    void MinHeapify(int);

    int parent(int i) { return (i - 1) / 2;}

    // to get index of left child of node at index i
    int left(int i) { return 2*i + 1; }
    // to get the index of the right child of node at index i
    int right(int i) { return 2*i + 2; }

    int extractMin(); // extracts the root which is the minimum element

    // decreases the key value of key at index i to new_val
    void decreaseKey(int i, int new_value);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0];}

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap) {
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];    // in C++ new is preferred over malloc()
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases key value of key at index i to new_val
// It is assumed that new_val is smaller than harr[i]
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin() {
    if (heap_size <= 0) 
        return INT_MAX;
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}