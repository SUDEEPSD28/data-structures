#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>


typedef struct stack
{
    int *data;
    int top;
    int capacity;
}Stack;

/* Create a stack*/

Stack* createstack(int capacity)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->capacity=capacity;
    s->top = -1;
    s->data = (int *)malloc(capacity*sizeof(int));
    return s;
}

//Check if the stack is empty
 bool isempty(Stack *s)
 {
     return s->top == -1;

 }

//Check if the stack is full

 bool isfull(Stack *s)
 {
     return s->top == s->capacity -1;

 }

 //Push data into stack
 void push(Stack *s, int value)
 {
     if(isfull(s))
     {
         printf("Stack is full cannot push data\n");

     }

         s->data[++s->top] = value;
         printf("pushed data is %d",value);
 }

 //pop data from stack
 int pop(Stack *s)
 {
     if(isempty(s))
        printf("Stack is empty cannot pop data");
     int x = s->data[s->top ++];
     return x;
 }

 //Peek of stack
 int peek(Stack *s)
 {
     return s->data[s->top];
 }

// Print the current elements in the stack
void printStack(Stack *s) {
    if (isempty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Free the dynamically allocated memory
void freeStack(Stack *s) {
    if (s) {
        free(s->data);
        free(s);
    }
}

int main()
{
    Stack *mystack = createstack(5);
    push(mystack,2);

    push(mystack,1);
    push(mystack,3);
    push(mystack,5);
    push(mystack,7);



    pop(mystack);
    printStack(mystack);



    return 0;
}

