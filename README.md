# BST and MaxHeap Data Structures

This project implements two fundamental data structures: Binary Search Tree (BST) and MaxHeap. Each structure is designed to handle specific operations efficiently.

## Classes

### 1. node_BST
This class represents a node in the Binary Search Tree. It contains attributes for the node's value and pointers to its left and right children.

### 2. node_Maxheap
This class represents a node in the MaxHeap. It includes attributes for the node's value and its index within the heap.

### 3. BST
This class implements various operations associated with a Binary Search Tree, including:

- insert(nodeBST* TC, nodeBST new_node): Finds the location for a new node and inserts it into the tree.
- Tnsert_BST(string name, int id): Accepts information for a new node and adds it to the BST.
- search_Request_BST(int id): Searches for a node by its ID and displays its information.
- search(int id): Searches for a node by its ID and returns a boolean indicating its existence, used to prevent duplicate IDs during insertion.
- size_BST(): Returns the size of the BST.
- isEmpty_BST(): Checks if the BST is empty.
- print_BST(node_BST TC): Prints the contents of the BST using pre-order traversal.
- deleterequestBST(int id): Deletes a node from the BST based on its ID.

### 4. Maxheap
This class implements various operations associated with a MaxHeap, including:

- isEmptyMaxheap()**: Checks if the MaxHeap is empty.
- **sizeMaxheap(): Returns the size of the MaxHeap.
- Increasepriority(int id, int newpriority): Increases the priority of a node in the MaxHeap.
- InsertHeap(int id, int priority)**: Adds a new node to the MaxHeap.
- **PrintMaxheap(int index): Prints the contents of the MaxHeap using level-order traversal.
- Maxheapify(int index)**: Corrects the position of a node if it violates the MaxHeap property.
- **DeleteMaxheap(): Deletes the node with the highest priority from the MaxHeap.
- Deletenode(int id)**: Deletes a node from the MaxHeap based on its ID.

## Usage
This repository provides a clear structure for implementing and using BST and MaxHeap data structures in C++. The implementation includes functions for inserting, deleting, searching, and printing nodes in each structure, ensuring efficient data handling.

## Installation
Clone the repository and compile the C++ files to test the functionality of both data structures.
