#include <cs50.h>
#include <stdio.h>
#include <math.h>

float Globalc;
int cents;
int Globaln;

float Get_change();
int Calculate_NumberOfCoins(int c);

int main (void)
{
    float dollars = Get_change();

    printf("Number of coins owed: %i\n" , Calculate_NumberOfCoins(cents));
}

float Get_change()          //Promt User for change owed
{
    do
    {
         Globalc = get_float ("Change owed: ");
    }
    while(Globalc < 0.00 );

     cents = round(Globalc * 100);

    return cents;
}

int Calculate_NumberOfCoins(int c)          //Calculate the number of coins required
{
    int n=0;


    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            n++;
        }

        else if (cents >= 10)
        {
            cents = cents - 10;
            n++;
        }

        else if (cents >= 5)
        {
            cents = cents - 5;
            n++;
        }

        else if (cents >= 1)
        {
            cents = cents - 1;
            n++;
        }
    }

    return n;
}