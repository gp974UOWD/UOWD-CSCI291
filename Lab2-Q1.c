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
void flip_array (int arr[], int length);


int main()
{
    int arr[SIZE];
    int arr2d[nRows][nCols];
    // print_matrix(arr2d,nRows);
    //Call to different functions

    //Part 1
    int arrPart1[SIZE];
    set_array (arrPart1, SIZE);
    //print_array(arrPart1, SIZE);

    //Part 2
    int arrPart2[SIZE];
    set_array (arrPart2, SIZE);
    //rem_align (arrPart2, SIZE, 8);

    //Part 3
    int arrPart3[SIZE];
    set_array (arrPart3, SIZE);
    //insert_align (arrPart3, SIZE, 4, 90);

    //Part 4
    int arrPart4[SIZE];
    set_array(arrPart4, SIZE);
    int arr2DPart4[nRows][nCols];
    //reshape (arrPart4, SIZE, arr2DPart4);

    //Part 5
    int arrPart5[nRows][nCols] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12},{13,14,15},{16,17,18},{19,20,21},{22,23,24}};
    //print_trans_matrix(arrPart5);

    //Part 6 not complete but almost
    int arrPart6[5]={1,2,3,4,5};
    int x = found_duplicate(arrPart6,5);
    if (x==1){
        printf("True\n");
    }else printf("False\n");

    //Part 7
    int arrPart7[SIZE];
    set_array(arrPart7,SIZE);
    flip_array(arrPart7, SIZE);
    //print_array (arrPart7, SIZE);
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
        for (int j=pos; j<length; j++){ 
            arr[j] = arr[pos+1];
            pos++;
            arr[length]=arr[length-1];
        }
        for(int i=0; i<length; i++){
            printf("array[%d] = %d\n", i, arr[i]);
        }
    }else printf("Argument pos should be positive.\n");
}

//Part 3
void insert_align(int arr[], int length, int pos, int value){
    if (pos>0){
        int temp;
        int temp2;
        for (int j=pos; j<length; j++){ 
            temp=arr[j];
            arr[j]=temp2;
            temp2=temp;
        }
        arr[pos]=value;
        for(int i=0; i<length; i++){
            printf("array[%d] = %d\n", i, arr[i]);
        }
    }else printf("Argument pos should be positive.\n");
}

//Part 4
void reshape(int arr[], int length, int arr2d[nRows][nCols]){
    if (length==nRows*nCols){
        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                int arrayindex;
                arr2d[i][j] = arr[arrayindex];
                arrayindex++;
            }
        }
        for(int i=0; i<nRows; i++){
            for(int j=0; j<nCols; j++){
                printf("%d  ",arr2d[i][j]);
            }
        printf("\n");
        }
    }else printf("The length of the 1D array should be equal to the rows*columns of the 2D array.\n");
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
            if(arr[j] == arr[i]){
                return true;
            }
        }
    }
}

//Part 7
void flip_array (int arr[], int length){
    int temp;
    for(int i=0; i<length/2; i++){
        temp = arr[i];
        arr[i] = arr[length-i-1];
        arr[length-i-1] = temp;
    }
}
