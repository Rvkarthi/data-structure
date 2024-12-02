#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head,*tail,*t,*th, *n;

void insert(int value)
{
    n = malloc(sizeof(struct node));
    n->data = value;
    n->next = NULL;
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else{
        tail->next = n;
        tail = n;
    }

}

void del()
{
    t=head;
    while(t->next!=tail)
    {
        t=t->next;
    }

    free(tail);
    t->next=NULL;
    tail = t;
}

void display()
{
    t = head;
    for(t; t != NULL; t = t->next)
    {
        printf("\n %d ", t->data);
    }
}

void main()
{
    insert(10);
    insert(20);
    insert(30);
    del();
    display();
}