#include <math.h>
#include <stdio.h>

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

            //iterate through one column
            for (int h = -1; h < 2; h++)
            {
                //iterate similarly through one row
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    for (int i=0; i < height ; i++)
    {
        for (int j=0; j < width; j++)
        {
            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                     //if pixel is outside the image (column)
                    if (i + h < 0 || i + h > (height - 1))
                    {
                        continue;
                        /*temp[i + h][j + w].rgbtRed = 0;
                        temp[i + h][j + w].rgbtGreen = 0;
                        temp[i + h][j + w].rgbtBlue = 0; */
                    }
                    //if pixel is outside the image (row)
                    if (j + w  < 0 || j + w > (width - 1))
                    {
                        continue;
                       /* temp[i + h][j + w].rgbtRed = 0;
                        temp[i + h][j + w].rgbtGreen = 0;
                        temp[i + h][j + w].rgbtBlue = 0; */
                    }

                   int Sum1;
                   int Sum2;
                   int Sum3;
                   int Sum_Red_X;
                   int Sum_Green_X;
                   int Sum_Blue_X;
                   int Sum_Red_Y;
                   int Sum_Green_Y;
                   int Sum_Blue_Y;
                   int Total_Sum_Red;
                   int Total_Sum_Green;
                   int Total_Sum_Blue;

                   Sum1 = Sum2 = Sum3 = Sum_Red_X = Sum_Green_X = Sum_Blue_X = Sum_Red_Y = Sum_Green_Y = Sum_Blue_Y = 0;

                   //For corners
                   if ( i + h < 0 || j + w < 0)
                   {
                       //Calculate the Gx pixel values for edges of red channel
                        Sum1 = (-1) * image[i + (h + 1)][j + (w + 1)].rgbtRed + 0;
                        Sum2 = (-2) * image[i + (h + 2)][j + (w + 1)].rgbtRed + 0;

                        Sum_Red_X = Sum1 + Sum2;

                        //Calculate the Gy pixel values for edges of red channel
                        Sum1 = 1 * image[i + (h + 1)][j + (w + 1)].rgbtRed + 2 * image[i + (h + 1)][j + (w + 2)].rgbtRed;
                        Sum2 = 0;

                        Sum_Red_Y = Sum1 + Sum2;

                        //Calculate the total for edges of red channel
                        Total_Sum_Red = round( sqrt( ( Sum_Red_X ^ 2) + (Sum_Red_Y ^ 2) ) );

                        if( Total_Sum_Red < 0 )
                        {
                            Total_Sum_Red = 0;
                        }
                        if( Total_Sum_Red > 255 )
                        {
                            Total_Sum_Red = 255;
                        }

                        //Calculate the Gx pixel values for edges of green channel
                        Sum1 = (-1) * image[i + (h + 1)][j + (w + 1)].rgbtGreen + 0;
                        Sum2 = (-2) * image[i + (h + 2)][j + (w + 1)].rgbtGreen + 0;

                        Sum_Green_X = Sum1 + Sum2;

                        //Calculate the Gy pixel values for edges of green channel
                        Sum1 = 1 * image[i + (h + 1)][j + (w + 1)].rgbtGreen + 2 * image[i + (h + 1)][j + (w + 2)].rgbtGreen;
                        Sum2 = 0;

                        Sum_Green_Y = Sum1 + Sum2;

                        //Calculate the total for edges of green channel
                        Total_Sum_Green = round( sqrt( ( Sum_Red_X ^ 2) + (Sum_Red_Y ^ 2) ) );

                        if( Total_Sum_Green < 0 )
                        {
                            Total_Sum_Green = 0;
                        }
                        if( Total_Sum_Green > 255 )
                        {
                            Total_Sum_Green = 255;
                        }

                        //Calculate the Gx pixel values for edges of blue channel
                        Sum1 = (-1) * image[i + (h + 1)][j + (w + 1)].rgbtBlue + 0;
                        Sum2 = (-2) * image[i + (h + 2)][j + (w + 1)].rgbtBlue + 0;

                        Sum_Blue_X = Sum1 + Sum2;

                        //Calculate the Gy pixel values for edges of blue channel
                        Sum1 = 1 * image[i + (h + 1)][j + (w + 1)].rgbtBlue + 2 * image[i + (h + 1)][j + (w + 2)].rgbtBlue;
                        Sum2 = 0;

                        Sum_Blue_Y = Sum1 + Sum2;

                        //Calculate the total for edges of blue channel
                        Total_Sum_Blue = round( sqrt( ( Sum_Red_X ^ 2) + (Sum_Red_Y ^ 2) ) );

                        if( Total_Sum_Blue < 0 )
                        {
                            Total_Sum_Blue = 0;
                        }
                    if( Total_Sum_Blue > 255 )
                    {
                        Total_Sum_Blue = 255;
                    }

                    //Assign the calculated values to the respective channel for edgeging
                    image[i][j].rgbtRed = Total_Sum_Red;
                    image[i][j].rgbtGreen = Total_Sum_Green;
                    image[i][j].rgbtBlue = Total_Sum_Blue;
                    }

                   //Calculate Gx values for red channel
                   Sum1 = (-1) * image[i + h][j + w].rgbtRed + 0 * image[i + h][j + (w + 1)].rgbtRed + 1 * image[i + h][j + (w + 2)].rgbtRed;
                   Sum2 = (-2) * image[i + (h + 1)][j + w].rgbtRed + 0 * image[i + (h + 1)][j + (w + 1)].rgbtRed + 2 * image[i + (h + 1)][j + (w + 2)].rgbtRed;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtRed + 0 * image[i + (h + 2)][j + (w + 1)].rgbtRed + 1 * image[i + (h + 2)][j + (w + 2)].rgbtRed;

                   Sum_Red_X = Sum1 + Sum2 + Sum3;

                   //Calculate Gy values for red channel
                   Sum1 = 1 * image[i + h][j + w].rgbtRed + 2 * image[i + h][j + (w + 1)].rgbtRed + 1 * image[i + h][j + (w + 2)].rgbtRed;
                   Sum2 = 0;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtRed + (-2) * image[i + (h + 2)][j + (w + 1)].rgbtRed + (-1) * image[i + (h + 2)][j + (w + 2)].rgbtRed;

                   Sum_Red_Y = Sum1 + Sum2 + Sum3;

                   //Calculate the total for red channel
                   Total_Sum_Red = round( sqrt( ( Sum_Red_X ^ 2) + (Sum_Red_Y ^ 2) ) );

                    if( Total_Sum_Red < 0 )
                   {
                       Total_Sum_Red = 0;
                   }

                   if( Total_Sum_Red > 255 )
                   {
                       Total_Sum_Red = 255;
                   }

                   //Calculate the Gx values for green channel
                   Sum1 = (-1) * image[i + h][j + w].rgbtGreen + 0 * image[i + h][j + (w + 1)].rgbtGreen + 1 * image[i + h][j + (w + 2)].rgbtGreen;
                   Sum2 = (-2) * image[i + (h + 1)][j + w].rgbtGreen + 0 * image[i + (h + 1)][j + (w + 1)].rgbtGreen + 2 * image[i + (h + 1)][j + (w + 2)].rgbtGreen;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtGreen + 0 * image[i + (h + 2)][j + (w + 1)].rgbtGreen + 1 * image[i + (h + 2)][j + (w + 2)].rgbtGreen;

                   Sum_Green_X = Sum1 + Sum2 + Sum3;

                   //Calculate the Gy values for green channel
                   Sum1 = 1 * image[i + h][j + w].rgbtGreen + 2 * image[i + h][j + (w + 1)].rgbtGreen + 1 * image[i + h][j + (w + 2)].rgbtGreen;
                   Sum2 = 0;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtGreen + (-2) * image[i + (h + 2)][j + (w + 1)].rgbtGreen + (-1) * image[i + (h + 2)][j + (w + 2)].rgbtGreen;

                   Sum_Green_Y = Sum1 + Sum2 + Sum3;

                   //Calculate the total for green channel
                   Total_Sum_Green = round( sqrt( ( Sum_Green_X ^ 2) + (Sum_Green_Y ^ 2) ) );

                    if( Total_Sum_Green < 0 )
                   {
                       Total_Sum_Green = 0;
                   }

                   if( Total_Sum_Green > 255 )
                   {
                       Total_Sum_Green = 255;
                   }

                    //Calculate the Gx values for blue channel
                   Sum1 = (-1) * image[i + h][j + w].rgbtBlue + 0 * image[i + h][j + (w + 1)].rgbtBlue + 1 * image[i + h][j + (w + 2)].rgbtBlue;
                   Sum2 = (-2) * image[i + (h + 1)][j + w].rgbtBlue + 0 * image[i + (h + 1)][j + (w + 1)].rgbtBlue + 2 * image[i + (h + 1)][j + (w + 2)].rgbtBlue;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtBlue + 0 * image[i + (h + 2)][j + (w + 1)].rgbtBlue + 1 * image[i + (h + 2)][j + (w + 2)].rgbtBlue;

                   Sum_Blue_X = Sum1 + Sum2 + Sum3;

                   //Calculate the Gy values for blue channel
                   Sum1 = 1 * image[i + h][j + w].rgbtBlue + 2 * image[i + h][j + (w + 1)].rgbtBlue + 1 * image[i + h][j + (w + 2)].rgbtBlue;
                   Sum2 = 0;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtBlue + (-2) * image[i + (h + 2)][j + (w + 1)].rgbtBlue + (-1) * image[i + (h + 2)][j + (w + 2)].rgbtBlue;

                   Sum_Blue_Y = Sum1 + Sum2 + Sum3;

                   //Calculate the total for blue channel
                   Total_Sum_Blue = round( sqrt( ( Sum_Blue_X ^ 2) + (Sum_Blue_Y ^ 2) ) );

                    if( Total_Sum_Blue < 0 )
                   {
                       Total_Sum_Blue = 0;
                   }

                   if( Total_Sum_Blue > 255 )
                   {
                       Total_Sum_Blue = 255;
                   }

                   //Assign the calculated values to the respective channel for edgeging
                   image[i][j].rgbtRed = Total_Sum_Red;
                   image[i][j].rgbtGreen = Total_Sum_Green;
                   image[i][j].rgbtBlue = Total_Sum_Blue;

                }
            }
        }
    }
    return;
}
