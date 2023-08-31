#include <stdio.h>
#include <stdlib.h>

//structure defnition

struct node{
int data;
struct node * next;}*first = NULL;



//creating a linked list
void create (int a[],int n){
int i;
struct node *t,*last;
first = (struct node*)malloc (sizeof(struct node));
first->data=a[0];
first->next=NULL;
last=first;
for(i=1;i<n;i++){
    t=(struct node*)malloc(sizeof(struct node));
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
}
}
//displaying linked list using loop
/*void display(struct node *p)
{
    while(p!=0){
        printf("%d",p->data);
        p=p->next;
    }
} */

//displaying using condition statement
/*
void display(struct node *p){
if(p!=0)
    {
        printf("%d",p->data);
        display(p->next);
    }
} */

//displaying using recursion function
void rdisplay(struct node *p){
if(p!=0)
{
   printf("%d",p->data);
        rdisplay(p->next);
}
}

//counting nodes in linked list
/*
int count(struct node *p){
int count=0;
while(p!=0){
    count++;
    p=p->next;
}
return count;
}
*/

//counting using recursion
int count (struct node *p){
if(p==0){
    return 0;}
    else{
        return count(p->next)+1;
}
}

//sum of all elements in linked list

int add(struct node *p){
int sum=0;
while(p){
    sum=sum+p->data;
    p=p->next;
}return sum;
}



int main()
{
    int a[]={3,7,5,6,8};
    create(a,5);
    // display(first);
    rdisplay(first);
    count (first);
    printf("%d", count);
    add(first);
    return 0;
}

