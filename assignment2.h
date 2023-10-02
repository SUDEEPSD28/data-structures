/*Write program to store student details in a data structure.
Carry out transactions like insert, delete and search an employee.
For every transaction conducted, store the log details like type_of_operation, transaction_time and transactions_date in a separate data structure.
Count the number of insert and delete transactions took place.
Deallocate all the memory allocated dynamically. (Preferably solve the above problem using linked list*/


#include<stdlib.h>
#define INSERT 1
#define FAIL 0
#define SUCCESS 1
#define DELETE 0
#define SIZE 30


struct _student_
{
    int sid;
    char sname[SIZE];
    int marks;
    struct _student_ *ptr;
};typedef struct _student_ Student;


struct _operation_
{
    char operation_name[SIZE];
    char date[SIZE];
    float time;
    struct _operation_ *ptr;
}; typedef struct _operation_ Operation;

struct _list_
{
    Student *head,*tail;
    int count;
    Operation *head1,*tail1;
    int insert_count,delete_count;
};typedef struct _list_ List;


List* initialize();
int insert(List*,char*,int,int,char*,float);
int delete(List*,char*,float);
void search(List*,int);




