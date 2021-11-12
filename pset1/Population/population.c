#include <cs50.h>
#include <stdio.h>

int Globalm;
int Globall;
int Globaln;

int Get_StartingLlama_population();
int Get_EndingLlama_population();
int Calculate_numberofyears();


int main(void)
{
    Get_StartingLlama_population();
    Get_EndingLlama_population();
    Calculate_numberofyears();

    printf("Total number of years: %i\n" , Globaln);

    // TODO: Print number of years
}

// TODO: Prompt for start size
int Get_StartingLlama_population()
{
   do
   {
        Globalm = get_int("What is the current popuplation? \n");
   }
    while(Globalm < 9);
    return Globalm;
}

// TODO: Prompt for end size
int Get_EndingLlama_population()
{
    do
   {
       Globall = get_int("What is the future popuplation size? \n");
   }
    while(Globall <= Globalm);
    return Globall;
}

// TODO: Calculate number of years until we reach threshold
int Calculate_numberofyears()
{
    int m = Globalm;
   // printf("m: %i\n" , m);
    int n = Globall;
    //printf("n: %i\n" , n);
    Globaln = 0;

   while (m < n)
   {
       m = m + (m / 3) - (m / 4);
       //printf("loop m: %i\n" , m);

       Globaln++;
       //printf("years: %i\n" , Globaln);
   }
   return Globaln;
    return 1;

}