#include<stdio.h> //adds input and output library
#include<string.h> //adds library for manipulating strings
#include<stdlib.h> //adds a general library for different essential functions
#include<time.h> //adds a library that accesses the current time

#define min 3 //the minimum amount to alert the admin if a product falls below it


void payWithCoins(float A); //purchasing function prototype. Datatype void because a value doesnt need to be returned, only the loop function is required
int restockItems(int A); //restocking items prototype. Datatype int because the item amount can only be whole positive integers
float changePrices(int A); //changing prices prototype. Datatype float because the price can have decimal points


float A = 2.50; //product prices are floating values
float B = 1.25;
float C = 5.00;

int productAmountA = 4; //product stock amount are integers
int productAmountB = 4;
int productAmountC = 4;

float newPriceA; //the price after changing are floating values
float newPriceB;
float newPriceC;

float totalSaleA; //the total sales are floating valies
float totalSaleB;
float totalSaleC;


int main(void)
{
    while (1){
        int option;
        printf("\nSelect an option:\n1. Purchase an item\n2. ADMIN ONLY\n3. Exit\n");
        scanf("  %d", &option);

        int saleFactor; //multiplicative factor used for multiplying with the price

        switch (option) {
            case 1: char product; //purchase product

                printf("\nSelect which product you want to buy:\nA - %.2f dhs\nB - %.2f dhs\nC - %.2f dhs\n", A, B, C); //displayed floating values are restricted to 2 decimal points given by %.2f
                scanf("  %c", &product);

                while (1){ //while statement is non-zero to keep it valid and constantly running
                    switch (product){ //used switch-case instead of if-else due to having 3 choices and a fail-safe

                        case 'A': 
                            payWithCoins(A); //encapsulated loop for payment
                            --productAmountA; //reduces the amount of product by 1 everytime it is purchased
                            ++saleFactor; //everytime a product is purchased, the factor is increased by 1
                            totalSaleA=A*saleFactor; //everytime a product is purchased, the price will be multiplied by the sale factor 
                        break; //break statements in a switch-case to prevent all upcoming statements to apply

                        case 'B':
                            payWithCoins(B);
                            --productAmountB;
                            ++saleFactor;
                            totalSaleB=B*saleFactor;
                        break;
                        
                        case 'C':
                            payWithCoins(C);
                            --productAmountC;
                            ++saleFactor;
                            totalSaleC=C*saleFactor;
                        break;
                        
                        default: printf("\nInvalid input. try again.\n");
                            scanf(" %c", &product);
                        break;
                    }
                break;
                }
            break; //break statements in a switch-case to prevent all upcoming statements to apply




            case 2: char passwordInput[100]; //admin menu, and passwordInput is datatype char with 100 columns to support a string

                printf("\nEnter the admin password: \n");
                scanf(" %s", &passwordInput); //passwordInput is assigned a string value

                if (strcmp(passwordInput, "password")==0){ //string compare to validate if the input is an exact word
                    int adminInput;

                    if (productAmountA<=min)
                        printf("\nALERT! Stock of A is low, restock now.\n"); //alert if the product amount is lower than min
                    if (productAmountB<=min)
                        printf("\nALERT! Stock of B is low, restock now.\n");
                    if (productAmountC<=min)
                        printf("\nALERT! Stock of C is low, restock now.\n");

                    printf("\nWelcome admin. Select an option:\n1. Replenish items\n2. Change item prices\n3. Display total sales\n4. Display item availability\n5. Exit\n");

                    scanf("  %d", &adminInput);

                    int adminLoop=1; 

                    while (adminLoop){ //the while statement is an integer value that can be changed to 0 later if the loop needs to be exited
                        switch (adminInput){

                            case 1: char replenishInput;
                                printf("\nChoose which item to replenish:\nA\nB\nC\n");
                                scanf(" %c",&replenishInput);
                               
                                srand(time(NULL)); //reads the current time to allow rand() to generate a random integer every second
                                switch(replenishInput){
                                    case 'A': 
                                        productAmountA=restockItems(productAmountA); //the amount of product is given by the function of restocking
                                    break;
                                    case 'B': 
                                        productAmountB=restockItems(productAmountB);
                                    break;
                                    case 'C': 
                                        productAmountC=restockItems(productAmountC);
                                    break;
                                    default: 
                                        printf("\nInvalid input. Try again.\n");
                                    continue;
                                }
                            break;

                            case 2: char priceChangeInput;
                                printf("\nChoose the item of which price to be changed:\nA\nB\nC\n");
                                scanf(" %c",&priceChangeInput);
                                switch(priceChangeInput){
                                        case 'A': 
                                            A=changePrices(newPriceA); //the new price is given by the function of changing price
                                        break;

                                        case 'B':
                                            B=changePrices(newPriceB);
                                        break;

                                        case 'C':
                                            C=changePrices(newPriceC);
                                        break;    
                                        
                                        default: printf("\nInvalid input. Try again.\n");
                                            continue;
                                }
                            break;

                            case 3: char salesCheckInput;
                                printf("\nChoose the item to check total sales:\nA\nB\nC\n");
                                scanf(" %c",&salesCheckInput);
                                switch(salesCheckInput){
                                    case 'A':
                                        printf("\nThe total sale of A is %.2f\n",totalSaleA); //reads the totalSale amount from the purchasing section
                                        sleep(1);
                                    break;

                                    case 'B':
                                        printf("\nThe total sale of B is %.2f\n",totalSaleB);
                                        sleep(1);
                                    break;

                                    case 'C':
                                        printf("\nThe total sale of C is %.2f\n",totalSaleC);
                                        sleep(1);
                                    break;

                                    default: printf("\nInvalid input. Try again.\n");
                                        continue;
                                }
                            break;

                            case 4: char itemCheckInput;
                                printf("\nChoose the item availability:\nA\nB\nC\n");
                                scanf(" %c",&itemCheckInput);
                                switch(itemCheckInput){
                                        case 'A': 
                                            printf("\nThe amount of A is %d",productAmountA); //reads the product amount stored in the array that is affected by the admin and purchasing
                                            sleep(1);
                                        break;

                                        case 'B':
                                            printf("\nThe amount of B is %d",productAmountB);
                                            sleep(1);
                                        break;

                                        case 'C':
                                            printf("\nThe amount of C is %d",productAmountC);
                                            sleep(1);
                                        break;    
                                        
                                        default: printf("\nInvalid input. Try again.\n");
                                            continue;
                                }
                            break;

                            case 5: adminLoop=0; //exits the admin loop
                            break;

                            default: printf ("\nInvalid input. try again");
                            continue;
                        }
                        break;
                    }
                
                }else printf("\nWrong password. Try again.\n");
            break; //break statements in a switch-case to prevent all upcoming statements to apply




            case 3: printf("\nHave a nice day.");
            return 0; //exits the entire program




            default: printf("\nInvalid input. Try again.\n");
            continue;
            }
    continue;
    }
} //end of main




void payWithCoins(float A) //purchasing function
{
    float coinInput;
    char returnIfFail;
    float productPriceA=A;

    int coinPaymentLoop=1;
    
    while (coinPaymentLoop){ //the while statement is an integer value that can be changed to 0 later if the loop needs to be exited
        printf("\nEnter %0.2f dhs in coins\n", productPriceA); //displayed floating values are restricted to 2 decimal points given by %.2f
        scanf("%f", &coinInput);
        if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){ //conditional statement to check for valid coins
            productPriceA = productPriceA - coinInput;
            if (productPriceA==0){
                printf ("\nThank you for your purchase. Check the deposit area.\n");
                sleep(1);
                coinPaymentLoop=0; //sets the while statement to 0 so the loop exits
            }else if (productPriceA<0){ //display change
                float purchaseRemainderA;
                purchaseRemainderA = -productPriceA; //the change is the negative value of the product price after getting deducted
                printf ("\nThank you for your purchase. Your change is %.2f. Check the deposit area.\n",purchaseRemainderA);
                sleep(1);
                coinPaymentLoop=0;
            }
        }else printf("\nInvalid input. Cancel? y/n\n"); //if the input does not match a valid coin, use a conditional statement to exit the loop
        scanf("%c", &returnIfFail);
        if (returnIfFail=='y'){
            coinPaymentLoop=0;
        }
    }
}




int restockItems(int A) //restocks items randomly
{
    int productAmount;

    productAmount = rand() % (20+1-1)+1; //random value from 1 to 20
    printf("\nThe product amount is now %d.\n", productAmount);
    sleep(1);

    return productAmount;
}




float changePrices(int A) //changes the price of the items
{
    float newPrice; 

    printf("\nWhat will the new price be?\n");
    scanf(" %f", &newPrice);
    printf("\nThe new price is %.2f.\n", newPrice); //displayed floating values are restricted to 2 decimal points given by %.2f
    sleep(1);

    return newPrice;
}
