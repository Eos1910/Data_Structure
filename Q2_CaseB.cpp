#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Node class for adjacency list
class Node {
public:
    int val;
    int weight;
    Node* next;

    // Constructor
    Node(int x, int w) {
        val = x;
        weight = w;
        next = NULL;
    }
};

// List class containing head pointer
class List {
public:
    Node* head;

    // Constructor
    List() {
        head = NULL;
    }
};

// Graph class using adjacency list representation
class Graph {
public:
    int vt;       // Number of vertices
    List* array;  // Array of adjacency lists

    // Constructor
    Graph(int vertices) {
        vt = vertices;
        array = new List[vertices];
    }

    // Function to add an edge to the graph
    void addEdge(int source, int dest, int x) {
        Node* temp = new Node(dest, x);
        temp->next = array[source].head;
        array[source].head = temp;
    }

    // Function to count total number of edges
    int numEdge() {
        int counter = 0;
        for (int i = 0; i < vt; i++) {
            Node* temp = array[i].head;
            while (temp != NULL) {
                counter++;
                temp = temp->next;
            }
        }
        return counter;
    }
};
