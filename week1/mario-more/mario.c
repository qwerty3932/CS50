#include <cs50.h>
#include <stdio.h>

void piramide(int height){
    for(int i = 0;i<height;i++){
        for(int j = 0;j<height - i -1;j++){
            printf(" ");
        }
        for (int j = 0; j<=i;j++){
            printf("#");
        }
        printf("  ");
        for (int j = 0; j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
}

int h;
int main(void){
    do {
        h = get_int("Height: ");
    }while(h < 1 || h>8);
    piramide(h);
}




/*

      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
*/
