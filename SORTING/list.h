#ifndef LIST_H__
#define LIST_H__

typedef struct node {
    int data;
    struct node* next;
} node ;

void print(node *head);
void radix_sort( node ** head);
int larger_digit(node * head);
int digit_finder(int number, int k);
void print_list();
int list_add(int newdata, node ** head);
void bucketsort(int * array, int size, int bucket_size);
#endif //LIST_H__