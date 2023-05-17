#include <stdlib.h>
#include <stdio.h>

typedef struct Con{
    double weight;
    struct Node *node;
} Con;


typedef struct Node {
    int data;
    int num_cons;
    struct Con **connections;
    double dist_from_start;

} Node;



void create_node(int data, Node **p_node) {
    *p_node = malloc(sizeof(Node));
    (*p_node)->data = data;
    (*p_node)->connections = (void *)0;
    (*p_node)->num_cons = 0;
    (*p_node)->dist_from_start = 10000000.0;
}

void add_neighbour(Node *node, Node *neighbour, double weight) {
    node->num_cons++;
    node->connections = realloc(node->connections, node->num_cons * sizeof(Con *));
    node->connections[node->num_cons - 1] = malloc(sizeof(Con));
    node->connections[node->num_cons - 1]->weight = weight;
    node->connections[node->num_cons - 1]->node = neighbour;
}


void add_to_visited(Node ***p_visited, int *p_n_visited, Node *node) { // CHANGED
    Node **visited = *p_visited; // ADDED

    for(int i = 0; i < *p_n_visited; i++) {
        if (visited[i] == node) {
            return;
        }
    }
    (*p_n_visited)++; // CHECK THIS
    visited = realloc(visited, *p_n_visited * sizeof(Node *));
    visited[*p_n_visited - 1] = node;

    *p_visited = visited; // ADDED
}

int was_visited(Node **visited, int n_visited, Node *node) {
    for (int i = 0; i < n_visited; i++){
        if (visited[i] == node){
            return 1;
        }
    }
    return 0;
}


void dijkstra(Node *start, Node *end) {
    Node **visited = (void *)0;
    int num_visited = 0;
    Node *current = start;
    current->dist_from_start = 0;
    add_to_visited(&visited, &num_visited, current); // CHANGED

    

    while (current != end) {
        double min_dist = 1000000000.0;
        Node *min_node = (void *)0;
        for(int i = 0; i < num_visited; i++){
            Node *s = visited[i];
            for(int j = 0; j < s->num_cons; j++) {

                /////////
                Node *n = ((s->connections)[j])->node;
                if (was_visited(visited, num_visited, n)){
                    continue;
                }

                if (min_dist> (s->dist_from_start + ((s->connections)[j])->weight)){
                    min_dist = s->dist_from_start + ((s->connections)[j])->weight;
                    min_node = ((s->connections)[j])->node;
                }  
            }
        }
        current = min_node;
        current->dist_from_start = min_dist;
        add_to_visited(&visited, &num_visited, current); // CHANGED
        printf("%f\n", min_dist);  
    }
    

}

int main(){
    Node* NodeA;
    Node* NodeB;
    Node *NodeC;
    Node *NodeD;
    Node *NodeE;
    create_node(1, &NodeA);
    create_node(2, &NodeB);
    create_node(3, &NodeC);
    create_node(4, &NodeD);
    create_node(5, &NodeE);
    add_neighbour(NodeA, NodeB,8);
    add_neighbour(NodeA,NodeC,2);
    add_neighbour(NodeB, NodeA, 8);
    add_neighbour(NodeB,NodeD,9);
    add_neighbour(NodeB,NodeE,4);
    add_neighbour(NodeC,NodeA,2);
    add_neighbour(NodeC,NodeD,5);
    add_neighbour(NodeD,NodeC,5);
    add_neighbour(NodeD,NodeB,9);
    add_neighbour(NodeD,NodeE,5);
    add_neighbour(NodeE,NodeD,5);
    add_neighbour(NodeE,NodeB,4);
    dijkstra(NodeA,NodeE);
    return 0;
}
