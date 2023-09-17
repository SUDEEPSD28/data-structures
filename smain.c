#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include"array.h"


int main()
{
   Array testarr;
   testarr= initialize_array(10);
   assert(testarr.csize==0 && testarr.tsize== 10);

   //insert data in array
   testarr=insert_data(testarr,10);
   testarr=insert_data(testarr,20);
   testarr=insert_data(testarr,30);
   testarr=insert_data(testarr,40);
   testarr=insert_data(testarr,50);
   testarr=insert_data(testarr,60);
   testarr=insert_data(testarr,70);
   testarr=insert_data(testarr,80);
   testarr=insert_data(testarr,90);
   testarr=insert_data(testarr,100);
   assert(testarr.csize==10);
   assert(testarr.array[3]==40);

  //search array
    assert(search_data(testarr,20));
    assert(search_data(testarr,70));
    assert(search_data(testarr,80));
    return 0;
}
