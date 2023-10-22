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

    //Part 5
    int arrPart5[nRows][nCols];
    print_trans_matrix(arrPart5[nRows][nCols]);

    //Part 6
    int arrPart6[SIZE]={1,2,5,4,9,10,6,8,4};
    int x = found_duplicate(arrPart6,SIZE);
    if (x==1){
        printf("True\n");
    }else printf("False\n");

    //Part 7
    int arrPart7[SIZE];
    set_array(arrPart7,SIZE);
    flip_array(arrPart7, SIZE);
    // print_array (arrPart7, SIZE);
}



void print_array(int array[], int length){
   for(int i=0; i<length; i++)
      printf("array[%d] = %d\n", i, array[i]);
}

void print_matrix(int mat[][nCols], int rows){
   for(int i=0; i<rows; i++){
    for(int j=0; j<nCols; j++)
         printf("mat[%d][%d] = %d\n", i,j, mat[i][j]);
    puts("");     
   }     
}

//Part 1
void set_array(int arr [], int length){
    for(int i=0; i<length; i++)
        arr[i]=i;
}

/*
void rem_align(int arr[], int length, int pos){
    int x;
    for(int i=0; i<length; i++){
        
    }
}



void insert_align(int arr[], int length, int pos, int value){

}

void reshape(int arr[], int length, int arr2d[nRows][nCols]){

}
*/

//Part 5
void print_trans_matrix(int arr2d[nRows][nCols]){
    int trans[][];
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            trans[j][i]=arr2d[i][j];
            printf("%d ",trans[i][j]);
        }
    }
}

//Part 6
bool found_duplicate(int arr[], int length){
    for(int i=0; i<length; i++) {    
        for(int j=i+1; j<length; j++) {    
            if(arr[i] == arr[j]){
                return true;
            }else return false;
        }
    }
}

//Part 7
int flip_array (int arr[], int length){
    int x;
    for(int i=0; i<length/2; i++){
        x = arr[i];
        arr[i] = arr[length-i-1];
        arr[length-i-1] = x;
    }
}
