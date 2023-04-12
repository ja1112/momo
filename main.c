#include <stdio.h>
#include <stdlib.h>
#define PIN 1515
void withDraw(float amount);
float requestAmount(void);
void transfer(void);
int authenticate(int pin);
void deposit(void);

float balance=10000.00;

int main(){
 start:
 printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
 static  tries = 0;
 int pin=0;
 scanf("%d", &pin);

 menu:
 if(authenticate(pin) && tries < 4){
 int menu_item;
 printf("Select an option\n1. Check Balance\n2. Withdrawal\n3.Deposit\n4. Transfer\n");
 scanf("%d", &menu_item);
 switch(menu_item){
 case 1: printf("%g\n", balance);
 break;
 case 2: withDraw(requestAmount());
 break;
 case 3: deposit();
 break;
 case 4: transfer();
 }
 }
 else{
 ++tries;
 printf("Invalid pin after %d tries\n",tries);
 if(tries==4)
    exit(1);
 goto start;
 }
 int response;
 printf("Would you like to perform another transaction?\n1. Yes\n2.No\n");
 scanf("%d", &response);
 if(response == 1)
    goto menu;

printf("Thank you for banking with us\n");
return 0;
}

//function declarations

int authenticate(int pin){
return pin==1515;
}

//REQUEST AMOUNT;
float requestAmount(){
printf("How much would you like to request: ");
float amount;
scanf("%f",&amount);
return amount;
}

//WITHDRAW AMOUNT
void withDraw(float amount){
    if(amount>balance){
        printf("Insufficient funds to perform transaction\n");
    }
    else{

    balance=balance-amount;
    }
}
void deposit(){
printf("Please how much would you like to deposit: ");
float depo=0.0;
scanf("%f",&depo);
balance+=depo;
}

void transfer(){
printf("\nPlease Enter the account number: ");
char accountNo[1010];
scanf("%s",accountNo);
fflush(stdin);
printf("\nPlease how much would you like to transfer: ");
float trans=0.0;
scanf("%f",&trans);
if(trans>balance){
    printf("Insufficient funds to perform transaction\n");
}
else{

balance-=trans;
}
}
