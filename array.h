#define ARRAY_STATIC
#define FOUND 1
#define NOT_FOUND 0
#define MAX_SIZE 20


//define a structure
struct _array_
{
    int array[MAX_SIZE];
    int csize,tsize;
};
typedef struct _array_ Array;

//call the functions
Array initialize_array (int);
Array insert_data(Array,int);
int search_data(Array,int);


