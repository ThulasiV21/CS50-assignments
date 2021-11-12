
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int Globalk;
string GlobalPlain;

int ConvertToPositive(int k);
int Rotate_Algorithm(string text);

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        if (isalpha(*argv[1]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

    else
    {
        printf("Missing command-line arguments\n");
        return 1;
    }

    GlobalPlain = get_string("Plaintext: ");
    printf("Ciphertext: ");

    int k = atoi(argv[1]);

    ConvertToPositive( k);
    Rotate_Algorithm( GlobalPlain);

}

int ConvertToPositive(int k)
{
    if( k < 0)
    {
        Globalk = k * (-1);
    }
    else
    {
        Globalk = k;
    }
    return Globalk;
}


int Rotate_Algorithm(string text)
{
    for (int i=0, n= strlen(GlobalPlain); i < n; i++)
    {
       if islower(GlobalPlain[i])
            printf("%c", (((GlobalPlain[i] + Globalk) - 97) % 26) + 97);
        else if isupper(GlobalPlain[i])
            printf("%c", (((GlobalPlain[i] + Globalk) - 65) % 26) + 65);
        else
            printf("%c", GlobalPlain[i]);
    }
    printf("\n");

    return 0;
}


/*
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{


// check there is only 1 arguments and it is a number else returns instructions
    if (argc == 2 && isdigit(*argv[1]))

    {
      int k = atoi(argv[1]); // get the ceasar KEY value convert into integar

        string s = get_string("plaintext: "); // get text
        printf("ciphertext: "); // print out cipher

// iterate through plain text letter by letter
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            // checking if it is lowercase 97 = a to 112 = z and if it + 13 characters along.
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a'); // print out lowercase with key
            } // if it it between uppercase A and C
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); // print out uppercase with key
            }

            else

            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar k\n");
        return 1;

    }

}
*/