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
    int i = 0;
    while (table[index] != 0) // this while loop work when data is already there
    {
        index = (index + (i * i)) % size;
        i++;
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
    insert(11);
    insert(12);
    insert(14);
    insert(24);
    insert(111);

    display();
}