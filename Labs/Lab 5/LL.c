#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct LL{
    node *head;
    int size;
} LL;

void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;
    for (int i = 0; i < size; i++){
        node *n;
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        if(cur == NULL){
            (*p_LL)->head = n;
        }
        else{
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}

void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

void LL_insert(LL *my_list, int new_elem, int index)
{
    // created new node with pointer to what was originally in its place
    node *new_node;
    create_node(&new_node, new_elem);
    int i = 0;

    node *prev_node = my_list->head;
    while(i < index-1){
        prev_node = prev_node->next;
        i++;
    }   

    node *next_node;
    next_node = prev_node->next;

    prev_node->next = new_node;
    new_node->next = next_node;

    my_list->size++;
    // // Insert new_elem at index index in linked list my_list
}

void LL_delete(LL *my_list, int index)
{
    // TODO
    int i = 0;

    node *prev_node = my_list->head;
    while(i < index-1){
        prev_node = prev_node->next;
        i++;
    } 

    node *del_node = prev_node->next;
    prev_node ->next = del_node ->next;
    // Delete element at index index in linked list my_list
    my_list->size --;
}

void LL_free_all(LL *my_list)
{
    // TODO
    node *current_node = my_list->head;
    while(current_node->next != NULL){
        node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    my_list->head = NULL;
    my_list->size = 0;
    // Free all memory allocated for linked list my_list,
    // including all the nodes
}


int LL_get_rec_helper(node *current_node, int index, int correct_index) {
    if (current_node == NULL) {
        printf("Error");
    }
    if (index == correct_index){
        return current_node->data;
    }
    index++;
    return LL_get_rec_helper(current_node->next, index, correct_index);

}

int LL_get_rec(LL *my_list, int correct_index) {
    int index = 0;
    return LL_get_rec_helper(my_list->head, index, correct_index);
}



// int main()
// {
//     int data_arr[] = {1, 2, 3, 4, 5};
//     LL *my_list;
//     create_LL_from_data(&my_list, data_arr, 5);
//     LL_append(my_list, 6);
//     LL_insert(my_list, 243, 3);

//     printf("\nrecursive:%d\n", LL_get_rec(my_list, 3));
//     node *cur = my_list->head;
//     while(cur != NULL){
//         printf("%d\n", cur->data);
//         cur = cur->next;
//     }
//     return 0;
// }


typedef struct ArrayList{
    int *data;
    int size;
    int capacity;
} ArrayList;

void create_AL_from_data(ArrayList **p_AL, int *data_arr, int size)
{
    //initializing arraylist
    (*p_AL)= (ArrayList*)malloc(sizeof(ArrayList)); //created an ArrayList object
    (*p_AL)->data = (int*)malloc(size * sizeof(int)); //created space for the data characteristic
    (*p_AL)->size = size;
    (*p_AL)->capacity = size;

    memmove((*p_AL)->data, data_arr, size*sizeof(int)); //mulitplied by 4 bcz each int requires 4 bytes
}

void AL_resize(ArrayList *my_list){
    (my_list)->data = realloc((my_list->data), ((my_list)->capacity)*2*sizeof(int)); //passes in pointer to data array and doubles original capacity
    (my_list)->capacity = ((my_list)->capacity)*2; //updates capacity
}

void AL_append(ArrayList *my_list, int new_elem)
{
    if (my_list->capacity == my_list->size){
        AL_resize(my_list);
    ((my_list)->data)[(my_list->size)] = new_elem;
    (my_list->size) ++;
    }
}

void print_contents(ArrayList *my_list){
    for (int i = 0; i < my_list->capacity+1; i++){
        printf("\n: [%d], %d, capacity:%d", i, ((my_list)->data)[i], my_list->capacity);
    }
}

void AL_insert(ArrayList *my_list, int new_elem, int index)
{
    //check whether there is sufficient space (resize if necessary)
    if (my_list->capacity <= (my_list->size)+1){
        AL_resize(my_list);
    }
    //check whether index can fit in capacity
    while ((my_list->capacity)-1 <= index){
        AL_resize(my_list);
    }

    memmove(&(my_list->data)[index + 1], &(my_list->data)[index], (my_list->size - index) * sizeof(int));
    ((my_list)->data)[index] = new_elem;
    // print_contents(my_list);

    (my_list)->size ++;

}

void AL_delete(ArrayList *my_list, int index)
{

    memmove(&(my_list->data)[index -1], &(my_list->data)[index], (my_list->size - index) * sizeof(int));
    ((my_list)->data)[my_list->size-1] = NULL;
    // ((my_list)->data)[index] = new_elem;

    (my_list)->size--;
    // //then, move all the elements one up
    // for (int i = index; i< ((my_list)->size); i++){
    //     ((my_list)->data)[i] = ((my_list)->data)[i+1];
    // }

    // print_contents(my_list);
}

void AL_free(ArrayList *my_list)
{
    free(my_list->data);
    free(my_list);
}

int main()
{
    int data_arr[] = {1, 2, 3, 4, 5, 6};
    ArrayList *my_list;
    create_AL_from_data(&my_list, data_arr, 6);
    // AL_append(my_list, 243);
    AL_insert(my_list, 243, 1);
    // AL_delete(my_list, 3);

    print_contents(my_list);

    //Q2)b) difference between memcpy and memmove.
    //memcpy cannot move things with overlap in memory, whereas memmove can.
    //this is why you can use memmove for the same pointer.
    return 0;
}


