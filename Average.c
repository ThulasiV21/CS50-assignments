#include <cs50.h>
#include <stdio.h>
#include <string.h>

float average();

int main (void)
{
    int m = get_int("Total number of scores: \n");
    const int TOTAL = m;
    int scores[TOTAL];

    for(int i= 0; i<TOTAL ; i++)
    {
        scores[i] = get_int("Score: \n");
    }
    printf("Average: %f\n", average(TOTAL, scores));
}

float average (int length , int score[])
{
    int sum = 0;

    for(int i= 0; i < length ; i++)
    {
        sum = sum + score[i];

    }
   float avg = sum / (float) length;
    return avg;

}
