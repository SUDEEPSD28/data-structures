#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include"assignment2.h"



int main()
{
List *test;
test=initialize();
assert(test->head = test->tail == 0);
assert (test->count == 0);

assert(insert(test,"abc",1,30,"03/08/2023",9.5));
assert(insert(test,"def",2,20,"04/08/2023",10));
assert(insert(test,"ghi",3,33,"05/08/2023",10.30));
assert(insert(test,"jkl",4,28,"06/08/2023",11));
assert(insert(test,"mno",5,34,"07/08/2023",11.30));
assert(insert(test,"pqr",6,30,"08/08/2023",9.5));

assert(test->count==6);
assert(test->insert_count==6);
assert(test->delete_count==NULL);

assert(delete(test,"03/08/2023",10.5));
assert(delete(test,"04/08/2023",12));

assert(test->count==4);
assert(test->insert_count==6);
assert(test->delete_count==2);

search(test,1);
search(test,7);
}
