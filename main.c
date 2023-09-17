#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "darray.h"

int main()
{
    Array_dyn *test;

    test = initialize_array(7);
    assert(test != NULL);
    assert(test->csize == 0 && test->tsize == 7);
    assert(test->arr != NULL);

    assert(insert_data(test, 10));
    assert(insert_data(test, 20));
    assert(insert_data(test, 30));
    assert(insert_data(test, 40));
    assert(insert_data(test, 50));
    assert(insert_data(test, 60));
    assert(insert_data(test, 70) == SUCCESS);

    assert(test->csize == test->tsize);

    assert(insert_data(test, 80) == ARRAY_FULL);

    assert(search_data(test, 50));
    assert(search_data(test, 70));
    assert(search_data(test, 10));
    //assert(search_data(test, 90) == NOT_FOUND);


    return 0;

}
