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

    Node(int x, int w) {
        val = x;
        weight = w;
        next = NULL;
    }
};

// List class for adjacency list representation
class List {
public:
    Node* head;

    List() {
        head = NULL;
    }
};

// Graph class
class Graph {
public:
    int vt;         // Number of vertices
    List* array;    // Array of adjacency lists

    Graph(int vertices) {
        vt = vertices;
        array = new List[vertices];
    }

    // Adds an edge from source to dest with weight x
    void addEdge(int source, int dest, int x) {
        Node* temp = new Node(dest, x);
        temp->next = array[source].head;
        array[source].head = temp;
    }

    // Counts the total number of edges
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

// Main function
int main() {
    int vertices = 1000;
    Graph gr(vertices);

    srand(time(0));

    // Add 10,000 random edges (sparse graph)
    for (int i = 0; i < (100 * 100); i++) {
        int src = rand() % vertices;
        int dst = rand() % vertices;
        int weight = rand() % 100 + 1; // Optional: random weight from 1 to 100
        gr.addEdge(src, dst, weight);
    }

    // Output total number of edges
    int edges = gr.numEdge();
    cout << "The total number of edges for Case A is " << edges << endl;

    return 0;
}
