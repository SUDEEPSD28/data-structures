#include "array.h"

Array initialize_array (int size)
{
    Array my_arr;
   my_arr.csize=0;
   my_arr.tsize=size>0&&size<=MAX_SIZE?size:MAX_SIZE;
   return my_arr;

}
Array insert_data(Array my_arr,int data)
{
    if(my_arr.csize==my_arr.tsize)
        return my_arr;
    my_arr.array[my_arr.csize ++]=data;
    return my_arr;
}
int search_data(Array my_arr,int data)
{
    int i;
    for(i=0;i<my_arr.csize;i++)
    {
        if(my_arr.array[i]==data)
            return FOUND;
    }
    return NOT_FOUND;
}


