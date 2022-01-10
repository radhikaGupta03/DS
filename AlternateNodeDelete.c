#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head;
int flag = 0;
void push(int item) {
    struct node *ptr,*temp;  
    ptr = (struct node*)malloc(sizeof(struct node));      
    if (ptr == NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        ptr -> data = item;  
        if (head == NULL) {  
            ptr -> next = NULL;  
            head = ptr;  
        }  
        else {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;  
            ptr -> next = NULL;
        }  
    } 
    flag++;
}
void print() {
    struct node * start;
    start = head;
    while (start != NULL) {
        printf("%d ", start -> data);
        start = start -> next;
    }
}
void delete(int loc) {
    struct node *ptr,*ptr1;  
    int i;
    ptr = head;  
    for(i = 0; i < loc; i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if (ptr == NULL)  
        {  
            return;  
        }  
    }  
    ptr1 -> next = ptr -> next;  
    free(ptr);    
}
void deleteAlternate() {
    int i = 0;
    int j = 0;
    while (i < flag) {
        if ((i - j) & 1) {
            delete(i);
            j++;
        }
        i++;
    }
}
int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    printf("Linked list before deletion of alternate nodes:\n");
    print();
    printf("\n");
    deleteAlternate();
    printf("Linked list after deletion of alternate nodes:\n");
    print();
    printf("\n");
    return 0;
}