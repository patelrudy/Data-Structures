#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
}

struct node *newListNode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

struct node *addFront(struct node *head, int data) {
    struct node *p = newListNode(data);
    if (p == NULL) {
        printf("error adding node in the front of the linked list\n");
        return head;
    }
    p->next = head;
    return p;
}

struct node *addBack(struct node *head, int data) {
    if (head == NULL) {
        head = newListNode(data);
        return head;
    }
    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newListNode(data);
    return head;
}

struct node *find(struct node *head, int data) {
    for (struct node *p = head; p != NULL; p = p->next){
        if (p->data == data) {
            return p;
        }
    }
    return NULL;
}