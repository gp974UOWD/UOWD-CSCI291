#include<stdio.h> 
#include <stdbool.h>

#define SIZE 24
#define nRows 8
#define nCols 3


// PROTOTYPES
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void set_array(int arr [], int length);
void rem_align(int arr[], int length, int pos);
void insert_align(int arr[], int length, int pos, int value);
void reshape(int arr[], int length, int arr2d[nRows][nCols]);
void print_trans_matrix(int arr2d[nRows][nCols]);
bool found_duplicate(int arr[], int length);
int flip_array (int arr[], int length);


int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];
    // print_matrix(arr2d,nRows);
    //Call to different functions

    //Part 1
    int arrPart1[SIZE];
    set_array (arrPart1, SIZE);
    // print_array(arrPart1, SIZE);



    //Part 7
    int arrPart7[SIZE];
    set_array(arrPart7,SIZE);
    flip_array(arrPart7, SIZE);
    print_array (arrPart7, SIZE);
}



void print_array(int array[], int length){
   for(int i=0; i<length; i++)
      printf("array[%d] = %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0; i<rows; i++){
    for(int j=0;j<nCols; j++)
         printf("mat[%d][%d] = %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

void set_array(int arr [], int length){
    for(int i=0; i<length; i++)
        arr[i]=i;
}

/*
void rem_align(int arr[], int length, int pos){
    for(int i=0; i<length; i++){

    }
}


void insert_align(int arr[], int length, int pos, int value){

}

void reshape(int arr[], int length, int arr2d[nRows][nCols]){

}

void print_trans_matrix(int arr2d[nRows][nCols]){
    for(int i=0; i<nRows; i++){
        for(int j=0;j<nCols; j++)
            printf("");
}

bool found_duplicate(int arr[], int length){

}
*/
int flip_array (int arr[], int length){
    int x;
    for(int i=0; i<length/2; i++){
        x = arr[i];
        arr[i] = arr[length-i-1];
        arr[length-i-1] = x;
    }
}
