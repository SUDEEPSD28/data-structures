#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#define value 0xff00
#define BYTESWAP(value) (((value & 0x00ff)<<8) | ((value & 0xff00)>>8))


void getbit (uint64_t *num, int  position);
void setbit(uint64_t *num, int  position);
void clrbit(uint64_t *num, int  position);
void togglebit(uint64_t *num, int  position);
void getrangebit(uint64_t *num, int i, int j);
void setrangebit(uint64_t *num, int i, int j);
void clrrangebit(uint64_t *num, int i, int j);
void togglerangebit(uint64_t *num, int i, int j);
int countones(uint64_t *num);
void ispower(int number);
void reversebits(int number);
void swap(int *i, int *j);
void add(int i, int j);
void swapbits(int number);
void evenorodd(int number);



/*get a bit*/
void getbit (uint64_t *num, int  position)
{
    int bit;
    bit = (*num >> position)&1;
    //printf("\n%d",bit);

}

/*Set a bit*/
void setbit(uint64_t *num, int  position)
{
    *num = *num |(1ULL<< position);
   // printf("%llx",*num);
}

/*Clear a bit*/
void clrbit(uint64_t *num, int  position)
{
    *num = *num & (~(1ull << position));
     //printf("%llx",*num);

}

/*Toggle a bit*/
void togglebit(uint64_t *num, int  position)
{
    *num = *num ^ (1ull << position);
     //printf("%llx",*num);

}

/*get a bit from range i to j*/
void getrangebit(uint64_t *num, int i, int j)
{
    *num  = *num & (((1U << (j-i+1))-1)<<i);
    printf("%llx",*num);
}

/*set a bit from range i to j*/
void setrangebit(uint64_t *num, int i, int j)
{
    *num  = *num | (((1U << (j-i+1))-1)<<i);
    printf("%llx",*num);
}

/*set a bit from range i to j*/
void clrrangebit(uint64_t *num, int i, int j)
{
    *num  = *num & (~ (((1U << (j-i+1))-1)<<i));
    printf("%llx",*num);
}

/*set a bit from range i to j*/
void togglerangebit(uint64_t *num, int i, int j)
{
    *num  = *num ^ (((1U << (j-i+1))-1)<<i);
    //printf("%llx",*num);
}

/*Count number of 1's */

int countones(uint64_t *num)
{
    uint64_t temp = *num;
    int count = 0;
    while (temp)
    {
        count = count +  (temp &1);
        temp = temp >> 1;
    }
    //printf("%d",count);
}

/*Is power of 2 */
void ispower(int number)
{
     if ((number & (number - 1)) == 0 && number != 0) {
       // printf("is power of 2");
    }
    else
    {
        // printf("is not power of 2");

    }

}

/* Reverse a bits in number*/
void reversebits(int number)
{
    int reversed=0;
    int bitcount= sizeof(number)*8;
    int i;
    for(i=0;i<bitcount;i++){
        if(number&(1<<i)){
            reversed |= 1 << ((bitcount - 1) - i);
        }
    }
    //printf("%x", reversed);
}

/* Swap two bits*/
void swap(int *i, int *j)
{
    *i = *i ^ *j;
    *j = *i^*j;
    *i = *i ^ *j;

   // printf("%d,%d", *i, *j);
}

/* Add two numbers*/
void add(int i, int j)
{
    while (j !=0)
    {
        int carry =i&j;
        i = i ^j;
        j = carry <<1;
    }
   // printf("%d", i);
}
/*swap ith and jth bits*/

void swapbits(int number)
{
    int i = 1;
    int j = 2;

    int a = (number >> i)&1;
    int b = (number>>j)&1;
    int bitmask = (1<<i)|(i<<j);
    int num = number ^ bitmask;
    //printf("%d", num);

}
/*Even or odd*/
void evenorodd(int number)
{
    if (number &1 == 1){
        printf("number is odd");}
    else{
           printf("number is even");

    }
}

void main()
{
    uint64_t num = 0xff00f0f0;
    int position = 2;
    int i= 4;
    int j= 11;
    int number = 2;

    //getbit(&num,position);
    //setbit(&num,position);
    //clrbit(&num,position);
    //togglebit(&num,position);
    //getrangebit(&num,i,j);
    //setrangebit(&num,i,j);
    //clrrangebit(&num,i,j);
    //togglerangebit(&num,i,j);
    //countones(&num);
    //ispower(number);
   // reversebits(number);
   //swap(&i,&j);
   //add(i,j);
   //swapbits(number);
   evenorodd(number);

   //printf("%llx", BYTESWAP(value));



}
