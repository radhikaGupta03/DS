#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head;

void insert(int value) {
    struct node * start;
    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL) {
        printf("\nOVERFLOW\n");
    }
    else {
        start -> data = value;
        if (head == NULL) {
            start -> next = NULL;
            head = start;
        }
        else {
            struct node * temp;
            temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = start;
            start -> next = NULL;
        }
    }
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
    struct node * start;
    start = head;
    if (start == NULL) {
            printf("check");
            return;
    }
    
    if (loc == 0) {
        head = start -> next;
        free(start);
    }
    else {
        //printf("yes");
        struct node * temp;
        for (int i = 0; i < loc; i++) {
            temp = start;
            start = start -> next;
        }
        temp -> next = start -> next;
        free(start);
    }
}

int main() {
    insert(10);
    insert(9);
    insert(1);
    insert(7);
    insert(6);
    int key, i = 0;
    printf("Linked List before:\n");
    print();
    printf("\n\nEnter the key value: ");
    scanf("%d", &key);
    struct node * start;
    start = head;
    int flag = 0;
    while (start != NULL) {
        //printf("%d ", start -> data);
        if (start -> data == key) {
            // printf("check");
            // printf("%d ", i);
            delete(i);
            printf("\nKey value found in linked list and deleted\n");
            flag = 1;
            break;
        }
        i++;
        start = start -> next;
    }
    if (flag == 0) {
        printf("\nKey value not found in linked list\n");
    }
    printf("\nLinked list after:\n");
    print();
    return 0;
}