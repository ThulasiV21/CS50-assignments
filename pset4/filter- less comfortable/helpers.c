#include <stdio.h>
#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

     for (int i=0; i< height; i++)
     {
         for(int j=0; j< width; j++)
         {
            int Sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int Avg = round(Sum / 3);

            if (Avg > 255)
            {
                Avg = 255;
            }

            else if (Avg < 0)
            {
                Avg = 0;
            }

             image[i][j].rgbtBlue = Avg;
             image[i][j].rgbtGreen = Avg;
             image[i][j].rgbtRed = Avg;
         }

     }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0; i < height; i++)
    {
        for (int j=0; j< width; j++)
        {
            int sepiaRed = round (.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round (.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round (.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255 || sepiaGreen > 255 || sepiaBlue > 255)
            {
                sepiaRed = 255;
                sepiaGreen = 255;
                sepiaBlue = 255;
            }

            else if (sepiaRed < 0 || sepiaGreen < 0 || sepiaBlue < 0)
            {
                sepiaRed = 0;
                sepiaGreen = 0;
                sepiaBlue = 0;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i=0; i < height; i++)
    {
        for (int j=0; j<= width/2 ; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - ( j + 1 )] = tmp;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image to be blurred
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_blue;
            int sum_green;
            int sum_red;
            float counter;
            sum_blue = sum_green = sum_red = counter = 0;

            //iterate similarly through columns
            for (int h = -1; h < 2; h++)
            {
                //iterate similarly through rows
                for (int w = -1; w < 2; w++)
                {
                    //if pixel is outside the image (column)
                    if (i + h < 0 || i + h > (height - 1))
                    {
                        continue; //skip
                    }
                    //if pixel is outside the image (row)
                    if (j + w  < 0 || j + w > (width - 1))
                    {
                        continue; //skip
                    }
                    //sum up the values of all the pixels
                    sum_blue += image[i + h][j + w].rgbtBlue;
                    sum_red += image[i + h][j + w].rgbtRed;
                    sum_green += image[i + h][j + w].rgbtGreen;
                    counter++;

                    //find average colour value
                    image[i][j].rgbtRed = round(sum_red / counter);
                    image[i][j].rgbtGreen = round(sum_green / counter);
                    image[i][j].rgbtBlue = round(sum_blue / counter);
                }
            }

        }
    }
return;
}
