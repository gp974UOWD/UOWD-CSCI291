#include<stdio.h>

#define SIZE 24

// Function prototypes
void set_array(int arr [], int length);
void print_array(int array[], int length);
void iterativeOddEvenSeparate (int arr [], int length);
void recursiveOddEvenSeparate (int arr [], int length);

int main (void){

    // Iterative algorithm
    int iterativeArray[SIZE];
    set_array(iterativeArray, SIZE);
    iterativeOddEvenSeparate(iterativeArray, SIZE);
    print_array(iterativeArray, SIZE);

    // Recursive algorithm
    int recursiveArray[SIZE];
    set_array(recursiveArray, SIZE);
    recursiveOddEvenSeparate (recursiveArray, SIZE);
    print_array(recursiveArray, SIZE);

    return 0;
}


void iterativeOddEvenSeparate (int arr [], int length){
    for (int i=1; i<=length; i++){
        for(int j=i+1; j<=length; j++) { 
            if (arr[j]%2==0 && arr[i]%2==1){
                int hold = arr[i];
                arr[i] = arr[j];
                arr[j] = hold;
            }
        }
    }
}

void recursiveOddEvenSeparate (int arr [], int length){

}


// Sets each array number as its index 
void set_array(int arr [], int length){
    for(int i=1; i<=length; i++)
        arr[i]=i;
}

// Prints array
void print_array(int array[], int length){
    for(int i=1; i<=length; i++)
        printf("array[%d] = %d\n", i, array[i]);
}