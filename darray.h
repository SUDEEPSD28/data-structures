#define DYNAMIC_ARRAY
#define ARRAY_FULL 0
#define SUCCESS 1
#define NOT_FOUND 0
#define FOUND 1

struct _dynamic_array_
{
    int *arr;
    int csize,tsize;
};
typedef struct _dynamic_array_ Array_dyn;

struct _maxmin_
{
    int max,min;
};typedef struct _maxmin_ Maxmin;

Array_dyn* initialize_array(int size);
int insert_data(Array_dyn*,int data);
int search_data(Array_dyn*,int element);
Array_dyn * intersection(Array_dyn *arr_a, Array_dyn *arr_b);
Array_dyn * deallocate(Array_dyn *dynarr);
int is_palindrome(Array_dyn *dynarr);
int bubble_sort(Array_dyn *dynarr);
