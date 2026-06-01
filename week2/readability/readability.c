#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float index(float  l,float  w, float  s);

int i = 0;

int main(void){
    // prompt
    string text = get_string("Write a text: ");
    // count l, w and s
    int l = 0, w = 1,s = 0;
    for(i = 0;i<strlen(text);i++){
        if(isalpha(text[i])){
            l++;
        }else if(text[i] == ' '){
            w++;
        }else if(text[i]== '!' || text[i]== '.' || text[i]== '?'){
            s++;
        }
    }
    // calculate index
    int grade = index(l,w,s);
    // print grade level
    if(grade<0){
        printf("Before Grade 1\n");
    }else if(grade>16){
        printf("Grade 16+\n");
    }else{
        printf("Grade %d\n", grade);
    }
}
float index(float l,float w, float s){
    int index = (int) round(0.0588 * l/w * 100 - 0.296 * s/w * 100 - 15.8);
    return index;
}
/*

index = 0.0588 * L - 0.296 * S - 15.8
 0.0588 * L - 0.296 * S - 15.8
L = average number of l per 100 w
S = average number of s per 100 w

- sentence
will contain at least one word;
will not start or end with a space; and
will not have multiple spaces in a row.
*/
