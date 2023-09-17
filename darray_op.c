#include<stdlib.h>
#include<assert.h>
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
Array_dyn * deallocate(Array_dyn *dynarr)
{
    free(dynarr->arr);
    free(dynarr);

    return NULL;

}
Array_dyn * intersection(Array_dyn *arr_a, Array_dyn *arr_b)
{
    Array_dyn *arr_c;
    int i;

    if(arr_a->csize == 0 || arr_b->csize == 0) return NULL;

    arr_c = initialize_array(arr_a->csize);

    for(i=0; i<arr_a->csize; i++)
    {
        if(search_data(arr_b, arr_a->arr[i]) && !search_data(arr_c, arr_a->arr[i] ))
                assert(insert_data(arr_c, arr_a->arr[i]));
    }
    return arr_c;
}
int is_palindrome(Array_dyn *dynarr)
{
    int i=0,j=dynarr->csize-1;
    while(i<j)
        if(dynarr->arr[i++]!=dynarr->arr[j--])
        return 0;
    return 1;
}
int bubble_sort(Array_dyn *dynarr)
{
    int i,j,temp,flag;
    if(dynarr->csize<=1)
        return 0;
    for(i=0;i<dynarr->csize;i++)
    {
        flag =0;
        for(j=0;j<dynarr->csize-i-1;j++)
        {
            temp=dynarr->arr[j];
            dynarr->arr[j]=dynarr->arr[j+1];
            dynarr->arr[j+1]=temp;
            flag=1;
        }
        if(flag==0)
            return 1;
    }
    return 1;
}




