#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define A 2.50
#define B 1.25
#define C 5.00

#define min 3

int purchaseCalc(float x, float y);

int main(void){

    int option;
    printf("Select an option:\n1. Purchase an item\n2. ADMIN ONLY\n3. Exit\n");
    scanf("  %d", &option);

    while (1){
        switch (option) {
            case 1: char product;

                printf("\nSelect which product you want to buy:\nA - 2.50 dhs\nB - 1.25 dhs\nC - 5.00 dhs\n");
                scanf("  %c", &product);

                int inPurchase=1;
                while (inPurchase){
                    float coinInput;
                    char returnIfFail;
                    switch (product){

                        case 'A': 
                            int productAmountA;
                            float productPriceA=A;
                            while (productPriceA<=A){
                                printf("\nEnter %0.2f dhs in coins\n", productPriceA);
                                scanf("%f", &coinInput);
                                if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){
                                    productPriceA = productPriceA - coinInput;
                                    if (productPriceA==0){
                                        printf ("\nThank you for your purchase. Check the deposit area.");
                                        productAmountA = productAmountA - 1;
                                        return 0;
                                    }else if (productPriceA<0){
                                        float purchaseRemainderA;
                                        purchaseRemainderA = -productPriceA;
                                        printf ("\nThank you for your purchase. Your change is %.2f. Check the deposit area.",purchaseRemainderA);
                                        return 0;
                                        }
                                }else printf("\nInvalid input. Cancel? y/n\n"); 
                                    scanf("%c", &returnIfFail);
                                    if (returnIfFail=='y'){
                                        inPurchase=0;
                                    }
                            }
                        break;

                        case 'B':
                            int productAmountB=7;
                            float productPriceB=B;
                            while (productPriceB<=B){
                                printf("\nEnter %0.2f dhs in coins\n", productPriceB);
                                scanf("%f", &coinInput);
                                if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){
                                    productPriceB = productPriceB - coinInput;
                                    if (productPriceB==0){
                                        printf ("\nThank you for your purchase. Check the deposit area.");
                                        productAmountB = productAmountB - 1;
                                        return 0;
                                    }else if (productPriceB<0){
                                        float purchaseRemainderB;
                                        purchaseRemainderB = -productPriceB;
                                        printf ("\nThank you for your purchase. Your change is %.2f. Check the deposit area.",purchaseRemainderB);
                                        return 0;
                                        }
                                }else printf("\nInvalid input. Cancel? y/n\n"); 
                                    scanf("%c", &returnIfFail);
                                    if (returnIfFail=='y'){
                                        ;
                                    }
                            }
                        break;
                        
                        case 'C':
                            int productAmountC=7;
                            float productPriceC=C;
                            while (productPriceC<=C){
                                printf("\nEnter %0.2f dhs in coins\n", productPriceC);
                                scanf("%f", &coinInput);
                                if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){
                                    productPriceC = productPriceC - coinInput;
                                    if (productPriceC==0){
                                        printf ("\nThank you for your purchase. Check the deposit area.");
                                        productAmountB = productAmountC - 1;
                                        return 0;
                                    }else if (productPriceC<0){
                                        float purchaseRemainderC;
                                        purchaseRemainderC = -productPriceC;
                                        printf ("\nThank you for your purchase. Your change is %.2f. Check the deposit area.",purchaseRemainderC);
                                        return 0;
                                        }
                                }else printf("\nInvalid input. Cancel? y/n\n"); 
                                    scanf("%c", &returnIfFail);
                                    if (returnIfFail=='y'){
                                        ;
                                    }
                            }
                        break;
                        
                        default: printf("Invalid input. try again.");
                    }
                }
            break;



            case 2: char passwordInput[100];

                printf("\n\nEnter the admin password: \n");
                scanf("%s", &passwordInput);

                if (strcmp(passwordInput, "password")==0){
                    int adminInput;

                    printf("\nWelcome admin. Select an option:\n1. Replenish items\n2. Change item prices\n3. Display total sales\n4. Display item availability\n5. Exit\n");
                    scanf("  %d", &adminInput);

                    while (10000){
                        switch (adminInput){

                            case 1: char replenishInput;
                                printf("\nChoose which item to replenish:\nA\nB\nC\n");
                                scanf(" %c",&replenishInput);
                                int productAmountA;
                                int productAmountB;
                                int productAmountC;
                                srand(time(NULL));
                                switch(replenishInput){
                                    case 'A': productAmountA = rand() % (20+1-1)+1;
                                        printf("\nThe amount of A is now %d",productAmountA);
                                    break;
                                    case 'B': productAmountB = rand() % (20+1-1)+1;
                                        printf("\nThe amount of B is now %d",productAmountB);
                                    break;
                                    case 'C': productAmountC = rand() % (20+1-1)+1;
                                        printf("\nThe amount of C is now %d",productAmountC);
                                    break;
                                    default: printf("\nInvalid input. Try again.");
                                }
                                return 0;
                            break;

                            case 2: printf("s");
                            break;
                            case 3: printf("s");
                            break;
                            case 4: printf("s");
                            break;
                            case 5: printf("s");
                            break;
                            default: printf ("\nInvalid input. try again");
                        }
                        break;
                    }
                
                }else printf("Wrong password. Try again.");
            break;



            case 3: printf("Have a nice day.");
            return 0;



            default: printf("Invalid input. Try again.");
            }
        break;
    }
}



/*int purchaseCalc(float x, float y)
{
    float productPrice=2.50;
    while (productPrice<=A){
        printf("Enter %0.2f dhs in coins\n", productPrice);
        scanf("%f", &coinInput);
        if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){
            productPrice = productPrice - coinInput;
            if (productPrice==0){
                printf ("Thank you for your purchase. Check the deposit area.");
                return 0;
            }
        }else printf("Invalid input.\n");                              
    } 
    return productPrice;
}*/