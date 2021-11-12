#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do
    {
        height = get_int("Height: "); //Requesting input from user for height.
    }

    while (height < 0 || height > 8); //Limits user input to between 0 and 8.

    for (int rows = 1; rows <= height; rows++)
    {
        for (int spaces = 0; spaces < (height - rows); spaces++) //Based on the row number, there will be a certain amount of spaces. E.g. If the height is 8 and it is row 1, there are 7 spaces.
        {
            printf(" ");
        }

        for (int hashes = 0; hashes < rows; hashes++) //Based on which row it is, the number of hashes printed is equal to the row number. E.g. row 1 has 1 hash.
        {
            printf("#");
        }

        printf("  ");

        for (int hashes = 0; hashes < rows; hashes++) //This prints the right side of the pyramid. No need to print the spaces.
        {
            printf("#");
        }
        printf("\n");
    }