#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string text;
int i, j;
int cc;

int main(int argc, string argv[]){
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }else if(strlen(argv[1]) != 26){
        printf("Key must contain 26 characters. \n");
        return 1;
    }else{
        for(i = 0; i<strlen(argv[1]);i++){
            argv[1][i] = toupper(argv[1][i]);
            if(!(isalpha(argv[1][i]))){
                printf("Key must only contain alphabetic characters. \n");
                return 1;
            }
            for(j = 0;j<strlen(argv[1]);j++){
            if(argv[1][i] == argv[1][j]){
                cc++;
            }
            if(cc>26){
                printf("Error: Duplicate characters.\n");
                return 1;
            }
            }
        }
    }

    // user input to encrypt
    text = get_string("plaintext: ");
    for(i = 0; i < strlen(text); i++){
        if(isupper(text[i])){
            int c = text[i] - 65;
            text[i] = (toupper(argv[1][c]));
        }
        if(islower(text[i])){
            int c = text[i] - 97;
            text[i] = (tolower(argv[1][c]));
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
/*
// argv[1] - 26 caracteres, só letras e aparecem só uma vez


- get key
- validate
- get plaintext
- encipher
- get ciphertext

*/
