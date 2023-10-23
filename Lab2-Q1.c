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

    //Part 2
    int arrPart2[SIZE];
    set_array (arrPart2, SIZE);
    rem_align (arrPart2, SIZE, -4);
    print_array (arrPart2, SIZE);

    //Part 3


    //Part 4


    //Part 5
    int arrPart5[nRows][nCols] = {{1,2,3},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{7,8,9}};
    // print_trans_matrix(arrPart5);

    //Part 6 not complete but almost
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

//Part 2
void rem_align(int arr[], int length, int pos){
    if (pos>0){
        for(int i=0; i<length; i++){
            for (int j=pos; j<length; j++){
                arr[j] = arr[j+i];
            }
        }
    }else printf("Number should be positive.\n");
}

//Part 3
void insert_align(int arr[], int length, int pos, int value){
    
}

//Part 4
void reshape(int arr[], int length, int arr2d[nRows][nCols]){

}


//Part 5
void print_trans_matrix(int arr2d[nRows][nCols]){
    int transpose[100][100];
    for(int i=0; i<nRows; i++){
        for(int j=0; j<nCols; j++){
            transpose[j][i]=arr2d[i][j];
        }
    }
    for(int i=0; i<nCols; i++){
        for(int j=0; j<nRows; j++){
            printf("%d  ",transpose[i][j]);
        }
    printf("\n");
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
