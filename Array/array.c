#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define SIZE 15

void printarr(int *arr, int size);
void reversearray(int *arr, int size);
void maxmin(int *arr, int size);
void arrsum(int *arr, int size);
int removeduplicates(int *arr, int size);
void bubblesort(int *arr, int size);
void secondlargest(int *arr,int size);
void countevenodd(int *arr, int size);
void movezerotoend(int *arr, int size);
int insertelementbeg(int *arr, int size, int value);
int insertelementend(int *arr, int size, int value);
int insertatposiotion(int *arr, int size, int position , int value);
int deleteatbeg(int *arr, int size);
int deleteatend(int *arr, int size);
int deleteatpos(int *arr, int size, int position );
void linearsearch(int *arr,int size, int target);
void binarysearch(int *arr, int size, int target);



/*print an array*/
void printarr(int *arr, int size)
{
    int i=0;
    while(i  <size)
    {
        printf("%d", arr[i]);
        i++;
    }
    printf("\n");
}
/*Reverse an array*/

void reversearray(int *arr, int size)
{
    int start = 0;
    int end = size-1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
    printarr(arr, size);
}


/*Max min element in an array*/
void maxmin(int *arr, int size)
{
    int max = arr[0];
    int min = arr[0];

    for (int i=0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }

    }
    printf("%d,%d", max, min);
}

/*sum of arry*/
void arrsum(int *arr, int size)
{
    int sum=0;
    for (int i=0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    printf("%d", sum);
}

/*remove duplicates from an array*/

int removeduplicates(int *arr, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; ) {
            if (arr[i] == arr[j]) {

                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }
    return size;
}

/*Sorting of an array*/
void bubblesort(int *arr, int size)
{
    for(int i=0;i<size;i++){
        for(int j=0;j < size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printarr(arr, size);
}


/*Second largest element in an array*/
void secondlargest(int *arr,int size)
{
    int largest, second;
    if(arr[0]>arr[1]){
        largest = arr[0];
        second = arr[1];

    }else{
        largest = arr[1];
        second = arr[0];
    }

    for(int i=2; i<size ;i++){
        if(arr[i]> largest){
            second = largest;
            largest = arr[i];
        }else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    printf("%d", second);
}

/* count even and odd in an array*/
void countevenodd(int *arr, int size)
{
    int even=0;
    int odd =0;
    for (int i=0; i<size; i++){
        if (arr[i]%2==0){
            even++;
        }else
        odd++;

        }
printf("%d, %d", even ,odd);
    }

/*move all zero to end in an array*/
void movezerotoend(int *arr, int size)
{
    int temp[SIZE];
    int j=0;
    for(int i=0;i< size;i++)
    {
        if(arr[i]!=0){
            temp[j++]=arr[i];
        }
    }
    while (temp < size){
        temp[j++]=0;
    }
    for(int k=0;k< size;k++)
    {
        arr[k]=temp[k];
    }

    printarr(arr,size);
}

/*insert element at begining of an array*/
int insertelementbeg(int *arr, int size, int value)
{
    for(int i=size; i>=0; i--)
    {
        arr[i]=arr[i-1];

    }
    arr[0]=value;
    size++;
    return size;
}

/*insert element at end of an array*/
int insertelementend(int *arr, int size, int value)
{
    arr[size]=value;
    size++;
    return size;
}

/*insert element at given position of an array*/

int insertatposiotion(int *arr, int size, int position , int value)
{
    for(int i= size; i> position; i--)
    {
        arr[i] = arr [i-1];
    }
    arr[position]= value;
    size++;
    return size;
}

/*Delete an element at begining of an array*/

int deleteatbeg(int *arr, int size)
{
    for (int i=0; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}

/*Delete an element at end of an array*/
int deleteatend(int *arr, int size)
{
    size--;
    return size;
}


/*delete element at given position from an array*/
int deleteatpos(int *arr, int size, int position )
{
    for(int i= position; i< size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    return size;
}

/*Linear search in an array*/
void linearsearch(int *arr, int size, int target)
{
    int found = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target){
            printf("Target found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Target not present in array\n");
    }
}

/*Binary search in an array*/
void binarysearch(int *arr, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int found = 0;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            printf("Target found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (!found)
    {
        printf("Target not present in array\n");
    }
}


int main()
{
    int arr[SIZE]={1,0,4,5,6,8,3,2,0,4,8,10};
    int value =9;
    int position =2;
    int size = sizeof(arr)/sizeof(arr[0]);
    //printf("%d", size);

    //reversearray(arr, size);
    //maxmin(arr, size);
    //arrsum(arr,size);
    //size = removeduplicates(arr, size);
    //printarr(arr, size);
   // bubblesort(arr,size);
   //secondlargest(arr,size);
   //countevenodd(arr,size);
   //movezerotoend(arr,size);
   //size = insertelementbeg(arr,size, value);
   //printarr(arr,size);

   //size = insertelementend(arr,size, value);
   //printarr(arr,size);

   //size = insertatposiotion(arr,size,position, value);
   //printarr(arr,size);

   //size= deleteatbeg(arr, size);
   //printarr(arr,size);

   //size= deleteatend(arr, size);
   //printarr(arr,size);

   //size= deleteatpos(arr, size, position);
   //printarr(arr,size);

   //linearsearch(arr,size,66);

    binarysearch(arr,size,66);



    return 0;
}
