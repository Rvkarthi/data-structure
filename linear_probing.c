#include <stdio.h>

#define size 10
int table[size];

int hashfunction(int key)
{
    return key % size;
}

void insert(int key)
{
    int index = hashfunction(key);
    while (table[index] != 0)
    {
        index = (index + 1) % size;
    }
    table[index] = key;
}

void display()
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d :", i);
        if (table[i] == 0)
        {
            printf(" NULL\n");
        }
        else
        {
            printf(" %d\n", table[i]);
        }
    }
}

void main()
{
    printf("this is linear probing");
    insert(11);
    insert(12);
    insert(14);
    insert(24);
    display();
}
