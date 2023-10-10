#include<stdio.h>

#define A 2.50
#define B 1.25
#define C 5.00

#define coin1 0.25
#define coin2 0.50
#define coin3 1.00

int purchase(int x, int y);

int main(void){
    int option;
    printf("Select an option:\n1. Purchase an item\n2. ADMIN ONLY\n3. Exit\n");
    scanf("%d", &option);
    while (1){
        switch (option) {
            case 1: char product;
                printf("Select which product you want to buy:\nA - 2.50 dhs\nB - 1.25 dhs\nC - 5.00 dhs\n");
                scanf(" %c", &product);
                while (1){
                    switch (product) {
                        case 'A': printf("Enter 2.50 dhs in coins");
                        break;
                        case 'B': printf("Enter 1.25 dhs in coins");
                        break;
                        case 'C': printf("Enter 5.00 dhs in coins");
                        break;
                        default: printf("Invalid input. try again.");
                    }
                }
            break;
            case 2:
                printf("Enter the admin password: \n");
            break;
            case 3: printf("Have a nice day.");
            return 0;
            default: printf("Invalid input. Try again.");
            }
        break;
    }}