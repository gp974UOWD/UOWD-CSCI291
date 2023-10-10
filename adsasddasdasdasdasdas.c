#include<stdio.h>
#include<string.h>

int main(){
    char passwordInput[100];

    printf("Enter the admin password: \n");
    scanf(" %s", &passwordInput);

    if (strcmp(passwordInput, "password")==0){
        int adminInput;

        printf("Welcome admin. Select an option:\n1. Replenish items\n2. Change item prices\n3. Display total sales\n4. Display item availability\n5. Exit\n");
        scanf("%d", &adminInput);
    }else printf("Bad");
   
}