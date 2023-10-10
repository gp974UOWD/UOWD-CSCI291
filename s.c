#include<stdio.h>
#include<string.h>

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
    scanf("  %d", &option);

    while (1){
        switch (option) {
            case 1: char product;

                printf("Select which product you want to buy:\nA - 2.50 dhs\nB - 1.25 dhs\nC - 5.00 dhs\n");
                scanf("  %c", &product);

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



            case 2: char passwordInput[100];

                printf("\n\nEnter the admin password: \n");
                scanf(" %s", &passwordInput);

                if (strcmp(passwordInput, "password")==0){
                    int adminInput;

                    printf("\nWelcome admin. Select an option:\n1. Replenish items\n2. Change item prices\n3. Display total sales\n4. Display item availability\n5. Exit\n");
                    scanf(" %d", &adminInput);

                    while (1){
                        switch (adminInput){
                            case 1: printf("s");
                            case 2: printf("s");
                            case 3: printf("s");
                            case 4: printf("s");
                            case 5: printf("s");
                            default: printf ("Invalid input. try again");
                        }
                    
                    }
                else printf("Wrong password. Try again.");
                }
            break;



            case 3: printf("Have a nice day.");
            return 0;



            default: printf("Invalid input. Try again.");
            }
        break;
    }
}