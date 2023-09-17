#include<stdlib.h>
#include"darray.h"

//initialize dynamic array
Array_dyn* initialize_array(int size)
{
    Array_dyn *dynarr;
    dynarr=(Array_dyn*)malloc(sizeof(Array_dyn));
    if(dynarr==NULL)
        return NULL;
    dynarr->csize=0;
    dynarr->tsize=size;
    dynarr->arr=(int *)malloc(sizeof(int)*size);
    return dynarr;
}

//insert data into array
int insert_data(Array_dyn *dynarr,int data)
{
    if(dynarr->csize==dynarr->tsize)
        return ARRAY_FULL;
    *(dynarr->arr + dynarr->csize)=data;
    dynarr->csize++;
    return SUCCESS;
}
//search array
int search_data(Array_dyn *dynarr,int element)
{
    int i;
    for(i=0;i<dynarr->csize;i++){
        if(*(dynarr->arr + i)=element)
            return FOUND;
    }
    return NOT_FOUND;
}


