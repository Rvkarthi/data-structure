#include<string.h>
#include<ctype.h>
#include <stdio.h>
#define capacity 5
int arr[capacity];
int top=-1;

int isfull(){
    if(top==capacity-1)
        return 1;
    return 0;
}

int isempty()
{
    if(top==-1)
        return 1;
    return 0;
}

void push(int element)
{
    if(isfull())
        printf("\nstack is overflow\n");
    else
    {
        top++;
        arr[top] = element;
    }
}

int pop()
{
    if(isempty())
        printf("\nstack is underflow\n");
    else
    {
        top--;
        return arr[top+1];
    }
}

void display()
{
    for(int i=0;i<top+1;i++)
    {
        printf(" %d ", arr[i]);
    }
}



int main() {
    
    char str[] = "231*+9-"; //here write ur expression
    
    for(int i = 0;i<strlen(str);i++)
    {
        if(isdigit(str[i]))
        {
            push(str[i]-'0');
        }
        else
        {
            switch(str[i])
            {
                case '+':
                push(pop()+pop());
                break;
                
                case '-':
                push(pop()-pop());
                break;
                
                case '*':
                push(pop()*pop());
                break;
                
                case '/':
                push(pop()/pop());
                break;
            }
            
        }
    }
    
    printf("\nevaluated value is %d ", pop());
    
    
}