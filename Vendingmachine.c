#include<stdio.h> //adds input and output library
#include<string.h> //adds library for manipulating strings
#include<stdlib.h> //adds a general library for different essential functions
#include<time.h> //adds a library that accesses the current time




#define min 3 //the minimum amount to alert the admin if a product falls below it

void payWithCoins(float A); //purchasing function prototype
int restockItems(int A); //restocking items prototype
float changePrices(int A); //changing prices prototype

int inPurchase=1;

int main(void)
{
    while (1){
        int option;
        printf("\nSelect an option:\n1. Purchase an item\n2. ADMIN ONLY\n3. Exit\n");
        scanf("  %d", &option);

        float A = 2.50;
        float B = 1.25;
        float C = 5.00;

        int productAmountA;
        int productAmountB;
        int productAmountC;

        float newPriceA;
        float newPriceB;
        float newPriceC;

        float totalSaleA;
        float totalSaleB;
        float totalSaleC;

        switch (option) {
            case 1: char product; //purchase product

                printf("\nSelect which product you want to buy:\nA - %.2f dhs\nB - %.2f dhs\nC - %.2f dhs\n", A, B, C);
                scanf("  %c", &product);

                while (inPurchase){
                int saleFactor; //multiplicative factor
                    switch (product){ //used switch-case instead of if-else due to having 3 choices

                        case 'A': 
                            payWithCoins(A); //encapsulated loop for payment
                            --productAmountA;
                            ++saleFactor; //everytime a product is purchased, the factor is increased by 1
                            totalSaleA=A*saleFactor; //everytime a product is purchased, the price will be multiplied by the sale factor 
                        break;

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
            break;



            case 2: char passwordInput[100]; //admin menu

                printf("\n\nEnter the admin password: \n");
                scanf(" %s", &passwordInput);

                if (strcmp(passwordInput, "password")==0){
                    int adminInput;

                    printf("\nWelcome admin. Select an option:\n1. Replenish items\n2. Change item prices\n3. Display total sales\n4. Display item availability\n5. Exit\n");
                    if (productAmountA<=min)
                        printf("\nALERT! Stock of A is low, restock now.\n");
                    if (productAmountB<=min)
                        printf("\nALERT! Stock of B is low, restock now.\n");
                    if (productAmountC<=min)
                        printf("\nALERT! Stock of C is low, restock now.\n");

                    scanf("  %d", &adminInput);

                    int adminLoop=1;

                    while (adminLoop){
                        switch (adminInput){

                            case 1: char replenishInput;
                                printf("\nChoose which item to replenish:\nA\nB\nC\n");
                                scanf(" %c",&replenishInput);
                               
                                srand(time(NULL));
                                switch(replenishInput){
                                    case 'A': 
                                        productAmountA=restockItems(productAmountA);
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
                                            A=changePrices(newPriceA);
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
                                        printf("\nThe total sale of A is %.2f",totalSaleA);
                                    break;

                                    case 'B':
                                        printf("\nThe total sale of B is %.2f",totalSaleB);
                                    break;

                                    case 'C':
                                        printf("\nThe total sale of C is %.2f",totalSaleC);
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
                                            printf("\nThe amount of A is %d",productAmountA);
                                        break;

                                        case 'B':
                                            printf("\nThe amount of B is %d",productAmountB);
                                        break;

                                        case 'C':
                                            printf("\nThe amount of C is %d",productAmountC);
                                        break;    
                                        
                                        default: printf("\nInvalid input. Try again.\n");
                                            continue;
                                }
                            break;

                            case 5: adminLoop=0;
                            break;

                            default: printf ("\nInvalid input. try again");
                            continue;
                        }
                        break;
                    }
                
                }else printf("\nWrong password. Try again.\n");
            break;



            case 3: printf("\nHave a nice day.");
            return 0;



            default: printf("\nInvalid input. Try again.\n");
            continue;
            }
    continue;}
}




void payWithCoins(float A) //purchasing function
{
    float coinInput;
    char returnIfFail;
    float productPriceA=A;

    int coinPaymentLoop=1;
    
    while (coinPaymentLoop){
        printf("\nEnter %0.2f dhs in coins\n", productPriceA);
        scanf("%f", &coinInput);
        if (coinInput==0.25 || coinInput==0.50 || coinInput==1.00){ //check valid coins
            productPriceA = productPriceA - coinInput;
            if (productPriceA==0){
                printf ("\nThank you for your purchase. Check the deposit area.");
                sleep(1);
                coinPaymentLoop=0;
            }else if (productPriceA<0){ //display change
                float purchaseRemainderA;
                purchaseRemainderA = -productPriceA;
                printf ("\nThank you for your purchase. Your change is %.2f. Check the deposit area.\n",purchaseRemainderA);
                sleep(1);
                coinPaymentLoop=0;
            }
        }else printf("\nInvalid input. Cancel? y/n\n"); 
        scanf("%c", &returnIfFail);
        if (returnIfFail=='y'){
            coinPaymentLoop=0;
        }
    }
}


int restockItems(int A) //restocks items randomly
{
    int productAmount;

    productAmount = rand() % (20+1-1)+1;
    printf("\nThe product amount is now %d.\n", productAmount);
    sleep(1);

    return productAmount;
}



float changePrices(int A) //changes the price of the items
{
    float newPrice; 

    printf("\nWhat will the new price be?\n");
    scanf(" %f", &newPrice);
    printf("\nThe new price is %.2f.\n", newPrice);
    sleep(1);

    return newPrice;
}
