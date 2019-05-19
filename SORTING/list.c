#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

void print(node *head) {
    if(head == NULL) return;
    node *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
}


int list_add(int newdata, node ** head)
{
    
    // let's create a new node
    node * newNode = (node*)malloc(sizeof(node));

    //let's update the newNode info with the data we want to add 
    newNode -> data = newdata;
    newNode -> next = NULL;
    
    //and now we have to check where to insert it
   if(*head == NULL){
       
       *head = newNode;
  
   } else if((*head) -> next == NULL){
        
        (*head) -> next = newNode;
    
    } else {
      
      node * current  = *head;
      
      while(current -> next != NULL){
          current = current -> next;
      }
      
      current -> next = newNode;
        
    } 
    
    return 0;
}    

void radix_sort(node** head){
    
    int count, k, digit, least_significant, most_significant;
    struct node *rear[10], *front[10], *current;
    
    least_significant = 1;
    most_significant = larger_digit( (*head) );
    
    for(k = least_significant; k <= most_significant; k++){
        
        for(count = 0; count <= 9; count++){
            rear[count] = NULL;
            front[count] = NULL;
        }
        
        for(current = (*head); current != NULL; current = current -> next){
            
            digit = digit_finder((current)->data, k);
            
            if(front[digit] == NULL){
                front[digit] = current;
            } else {
                rear[digit] -> next = current;
            }
            rear[digit] = current;
        }
        
        count = 0;
        while(front[count] == NULL){
            count++;
        }
        
        (*head) = front[count];
        
        while(count < 9){
            if(rear[count + 1] != NULL){
                rear[count] -> next = front[count + 1];
            } else {
                rear[count + 1] = rear[count];
            }
            count++;
        }
        rear[9] -> next = NULL;
    }
}


int larger_digit(node * head){
    if(head == NULL) return 0;
    struct node * current  = (head);
    int tmp = 0;
    int digit = 0;
    
    while(current != NULL){
        if(current -> data > tmp)
        {
            tmp = current -> data;
        }
        current = current -> next;
    }
    
    while(tmp != 0){
        digit++;
        tmp = tmp / 10;
    }
    return(digit);
}

int digit_finder(int number, int k){
    int term, count;
    for(count = 1; count <= k; count++){
        term = number % 10;
        number = number / 10;
    }
    
    return(term);
}


void bucketsort(int * array, int size, int bucket_size){
    // we have to compute the max/min value in the array and we can do it in linear time 
    // by looking through all the element of the array.
    int i;
    int max = array[0];
    int min = array[0];
    for(i = 1; i < size; i++){
        if(array[i] > max ){
            max = array[i];
        } else if (array[i] < min){
            min = array[i];
        }
    }
    
    

    
    int b_count = ((max - min) / bucket_size) + 1;
    
    // let's create an array of buckets 
    node ** buckets = (node**)malloc(b_count * sizeof(node*));
    
    

    for(i = 0; i < b_count; i++){
        buckets[i] = NULL;
    }
    //let's compute the interval (the range of value for each bucket)
    
    
    for(i = 0; i < size; i++){
        int b_index = floor((array[i] - min) / bucket_size);
        list_add(array[i], &(buckets[b_index]));
    }
    
    
    
    for(i = 0; i < b_count; i++){
        
        radix_sort( &buckets[i] );
        
    }
    
    int i_array = 0;
    
    for(i = 0; i < b_count; i++){
        
        if(buckets[i] == NULL){
            continue;
        } else {
            node * current  = buckets[i];
            while(current -> next != NULL){
                array[i_array] = current -> data;
                i_array++;
                current = current -> next;
            }
            
            array[i_array] = current -> data;
            i_array++;
        }
        
        
    }
    
    for(i = 0; i < b_count; i++){
        free(buckets[i]);
    }
}






