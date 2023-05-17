#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Circular{
    int *data;
    int head, tail, size;
}Circular;

Circular* create_queue(int size){
    Circular* circ = (Circular*)malloc(sizeof(Circular));
    circ ->data = (int*)malloc(size * sizeof(int));
    circ->tail =-1;
    circ->head = -1;
    circ->size = size;
    return circ;
}

void enqueue(Circular* c, int item){
    if (c->head == -1){
        c->head = 0;
        c->tail = 0;
        (c->data)[c->tail] = item;
    }
    else{
        c->tail = ((c->tail)+1)%(c->size);
        (c->data)[c->tail] = item;
    }
}

int dequeue(Circular* c){
    int item = (c->data)[c->head];
    if (c->head == c->size -1){
        c->head = 0;
    }
    else{
        c->head++;
    }
    return item;
}

int circ_comp(Circular *c1, Circular *c2){
    int i = 0;
    int j = 0;
    for (int a = 0; max{c1 -> size, c2 ->size}; i++){
        if (c1->data[i % c1->size] < c2->data[j % c2->size]) {
            return 1;
        else if (c1->data[i % c1->size] > c2->data[j % c2->size]) {
            return -1;
        i++;
        j++;
    }}
    return -1;}
}



int main(){
    return 0;
    Circular *c1 = create_queue(5);
}

//Question 4 (insert this in enqueue function)
// if (self.tail == self.head && self.tail !=-1){
//     realloc(c->data, (c->size)*2);
// }