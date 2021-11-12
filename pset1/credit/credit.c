#include <cs50.h>
#include <stdio.h>

long Globalnumber;

long Get_Creditcard();
string Card_Validation (long number);
string Determin_TypeOfCard(long number);

int main(void)
{
     Get_Creditcard();
     Card_Validation ( Globalnumber);
     Determin_TypeOfCard( Globalnumber);
}

long Get_Creditcard()
{
     Globalnumber = get_long("Credit card number: ");

    // Calculate length of Credit card
    int i = 0;
    long cc = Globalnumber;

    while (cc > 0)
    {
        cc = cc / 10;
        i++;
    }

    //Check credit card number length validity
    if (i != 13 && i != 15 && i != 16)
    {
        printf ("Credit card number Invalid \n");
        return 0;
    }

    return Globalnumber;
}


string Card_Validation (long number)
{
  // Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = Globalnumber;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);

    total = sum1 + sum2;

    // Next check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("Credit card Invalid \n");
        return 0;
    }
    return false;
}

string Determin_TypeOfCard(long number)
{
    //Get starting digits
    long start = Globalnumber;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }

    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }

    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

    return false;
}