#include <stdio.h>
#include <cs50.h>

// variables
int cc = 0; // customer cash
int coins = 0;


// coins: 25, 10, 5, 1

void checkcoins(int cash){
    do{
        if(cash>=25){
            cash-=25;
            coins++;
        }else if(cash>=10){
            cash-=10;
            coins++;
        }else if(cash>=5){
            cash-=5;
            coins++;
        }else if(cash>=1){
            cash-=1;
            coins++;
        }
    }while(cash>0);
}

int main(void)
{
    do{
        cc = get_int("Cash: ");
    }while(cc <= 0);
    checkcoins(cc);
    printf("\n");
    printf("Coins: %d",coins);
    printf("\n");

}
