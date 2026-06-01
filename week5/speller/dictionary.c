// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int wordCount = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    node *cursor = table[hash_value];
    // Se palvra no dicionario - true
    while(cursor != NULL){
        if(strcasecmp(cursor->word, word) == 0){
            return true;
        }else{
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for(int i = 0; i<N;i++){
        table[i] = NULL;
    }
    // Abrir o arquivo dicionário
    FILE *source = fopen(dictionary, "r");
    // Checar se deu certo
    if(source == NULL){
        return false;
    }

    char buffer[LENGTH];

    while(fscanf(source, "%s", buffer) != EOF){
        node *n = malloc(sizeof(node));
        int hash_value = hash(buffer);
        strcpy(n->word, buffer);
        n->next = table[hash_value];
        table[hash_value] = n;
        wordCount++;
    }

    // fechar o arquivo dicionario
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0;i<N;i++){
        node *cursor = table[i];
        node *tmp = table[i];
        while(cursor != NULL){
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;

}
