#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

Student* getnode(char sname[],int sid, int marks)
{
    Student *newnode;
    newnode=(Student*)malloc(sizeof(Student));
    strcpy(newnode->sname,sname);
    newnode->sid=sid;
    newnode->marks=marks;
    newnode->ptr=NULL;
    return newnode;
}

List* initialize()
{
    List *mylist;
    mylist=(List*)malloc(sizeof(List));
    mylist->head=mylist
    ->tail=NULL;
    mylist->head1=mylist->tail1=NULL;
    mylist->count=0;
    mylist->insert_count=0;
    mylist->delete_count=0;
    return mylist;
}

int insert(List *mylist,char *sname,int sid,int marks,char *date,float time)
{
    Operation *newnode1;
    newnode1=(Operation*)malloc(sizeof(Operation));
    strcpy(newnode1->operation_name,"insert");
    strcpy(newnode1->date,date);
    newnode1->time=time;

    Student *newnode;
    newnode=getnode(sname,sid,marks);
    if(mylist->count==0)
    {
        mylist->head=mylist->tail=newnode;
        mylist->head1=newnode1;
        mylist->head1->ptr=NULL;
        mylist->count++;
        mylist->insert_count++;
        return INSERT;

    }else
    {
        newnode->ptr=mylist->head;
        mylist->head=newnode;

        newnode1->ptr=mylist->head1;
        mylist->head1=newnode1;
        mylist->count++;
        mylist->insert_count++;
        return INSERT;
    }
}


int delete(List *mylist,char *date,float time)
{
    Student *temp;

    Operation *newnode1;
    newnode1=(Operation*)malloc(sizeof(Operation));
    strcpy(newnode1->operation_name,"delete");
    strcpy(newnode1->date,date);
    newnode1->time=time;

    if(mylist->count==0)
        return FAIL;

    else
    {
        temp=mylist->head;
        mylist->head=mylist->head->ptr;
        mylist->count--;
        free(temp);

        newnode1->ptr=mylist->head1;
        mylist->head1=newnode1;
        mylist->delete_count++;
        return DELETE;
    }

}

void search(List *mylist,int sid)
{
    Student *temp;
    while(temp!=NULL && temp->sid!=sid)
    {
        temp=temp->ptr;
    }
    if(temp==NULL)
        printf("element searched\n");
    else
        printf("element not present\n");

}
