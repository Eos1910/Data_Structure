#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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

class List {
public:
    Node* head;

    List() {
        head = NULL;
    }
};

class Graph {
public:
    int vt;
    List* array;

    Graph(int vertices) {
        vt = vertices;
        array = new List[vertices];
    }

    // Add an edge between two vertices
    void addEdge(int source, int dest, int x) {
        Node* temp = new Node(dest, x);
        temp->next = array[source].head;
        array[source].head = temp;
    }

    // Count the total number of edges in the graph
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

// Case A: Sparse Graph - 100x100
int main() {
    int vertices = 1000;
    int edges;

    Graph gr(vertices);
    srand(time(0));

    // Add 10,000 edges with random source, destination, and weight
    for (int i = 0; i < (100 * 100); i++) {
        gr.addEdge(rand() % 1000, rand() % 1000, rand());
    }

    // Count and print total number of edges
    edges = gr.numEdge();
    cout << "The total number of edges for Case A is " << edges << endl;

    return 0;
}
