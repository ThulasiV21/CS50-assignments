#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int GlobalCount;
int GlobalLetters;
int GlobalWords;
int GlobalSent;

int Count_letters(string text);
int Count_words(string text);
int Count_sentences(string text);
void Calculate_Grade(int x, int y, int z);

int main (void)
{
    string text = get_string("Text: \n");

    Count_letters( text);
    Count_words( text);
    Count_sentences( text);
    Calculate_Grade(GlobalLetters, GlobalWords, GlobalSent );

}

int Count_letters(string text)
{
    int space =0;
    int chars =0;
    GlobalCount = strlen(text);
    int count = GlobalCount;


   for (int i=0 ; i< GlobalCount; i++)
   {
       if(text[i] == ' ')
       {
           space += 1;
       }
   }
   //printf("The number of spaces: %i\n", space);

   for (int i=0; i<GlobalCount; i++)
   {
       if(text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' )
       {
           chars += 1;
       }
   }
    //printf("The nnumber of chars is: %i\n", chars);

   GlobalLetters = count - space - chars;

   //printf("Number of letter(s): %i\n", GlobalLetters);

   return GlobalLetters;

}

int Count_words(string text)
{
    int words = 0;
    int space = 0;

    //printf("The Total number of chars is : %i\n", GlobalCount);

    for (int i=0 ; i< GlobalCount; i++)
   {
       if(text[i] == ' ')
       {
           space += 1;
       }
       GlobalWords = space +1;
   }
  //  printf("Number of word(s): %i\n", GlobalWords);
    return GlobalWords;
}

int Count_sentences(string text)
{
    int sent =0;

    for (int i=0; i< GlobalCount; i++)
    {
        if (text[i] == '.' || text[i] == '!')
        {
            sent += 1;
        }
    }

    GlobalSent = sent;
   // printf("Number of sentence(s): %i\n", GlobalSent);
    return GlobalSent;
}

void Calculate_Grade(int x, int y, int z)
{
        float L=0;
        float S=0;
        int index=0;

        L =  ((float)GlobalLetters / (float)GlobalWords ) * 100;

        S =   ((float)GlobalSent / (float)GlobalWords ) * 100;

       // printf("L: %f\n", L);
        //printf("S: %f\n", S);

        index = 0.0588 * L - 0.296 * S - 15.8;
        //printf("Before roundoff,index: %i\n", index);

        index =  round(index);

        //printf("index: %i\n", index);

         if( index > 16)
        {
            printf("Grade is 16+\n");
        }
        else if(index < 1)
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade: %i\n", index);
        }

        //return index;
}