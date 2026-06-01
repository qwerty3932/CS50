#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc!=2){
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *img = NULL;
    FILE *card = fopen(argv[1], "r");
    char filename[8];
    uint8_t buffer[512];

    if(card == NULL){
        printf("Could not open.\n");
        return 1;
    }
    //ler memory card
    while (fread(buffer, 1, 512, card) == 512){
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3]&0xf0) == 0xe0){
            // criar um novo arquivo
            if(i != 0){
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", i);
            i++;
            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);
        }else if(i != 0){
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(card);

}
