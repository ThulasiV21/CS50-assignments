// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Opening a file to read from dictionary
    FILE *file = fopen(dictionary.h, "r");
    if (file == NULL)
    {
        fclose(file);
        return false;
    }
    //Creating new nodes for all words in dictionary
    char s[LENGTH + 1];
    while(fscanf(file, "%s", s) == EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return true;
        }

        strcpy(n->word, s);
        n->next = NULL;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
