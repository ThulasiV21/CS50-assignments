void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //Replicating the pixels to a new RGBTRIPLE struct
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //looping through columns
    for (int i = 0; i < height; i++)
    {
        //looping through rows
        for (int j = 0; j < width; j++)
        {
            //looping through one column from the pixel
            for (int h = -1; h < 2; h++)
            {
                //looping through one row form the pixel
                for (int w = -1; w < 2; w++)
                {
                    //looping though the 3 channels of colours
                    for (int m = 0; m <= 2; m++)
                    {
                        int n;
                        //setting colour for each loop of m
                        if (m = 0)
                        {
                            n = rgbtBlue;
                        }
                        else if (m = 1)
                        {
                            n = rgbtGreen;
                        }
                        else
                        {
                            n = rgbtRed;
                        }

                        if ( i + h < 0 || i + h > (height - 1))
                        {
                            continue;
                        }

                        if ( j + w < 0 || j + w > (width - 1))
                        {
                            continue;
                        }

                        //Calculate the Gx values for each channel
                        Sum1 = (-1) * image[i + h][j + w].n + 0 + 1 * image[i + h][j + (w + 2)].n;
                        Sum2 = (-2) * image[i + (h + 1)][j + w].n + 0 + 2 * image[i + (h + 1)][j + (w + 2)].n;
                        Sum3 = (-1) * image[i + (h + 2)][j + w].n + 0 + 1 * image[i + (h + 2)][j + (w + 2)].n;

                        Sum_X = Sum1 + Sum2 + Sum3;

                        //Calculate the Gy values for each channel
                        Sum1 = (-1) * image[i + h][j + w].n + (-2) * image[i + h][j + (w + 1)].n + (-1) * image[i + h][j + (w + 2)].n;
                        Sum2 = 0;
                        Sum3 = 1 * image[i + (h + 2)][j + w].n + 2 * image[i + (h + 2)][j + (w + 1)].n + 1 * image[i + (h + 2)][j + (w + 2)].n;

                        Sum_Y = Sum1 + Sum2 + Sum3;

                        Total_Sum = round ( sqrt ( Sum_X ^ 2) + ( Sum_Y ^ 2));

                        if ( Total_Sum < 0)
                        {
                            Total_Sum = 0;
                        }

                        if ( Total_Sum > 255)
                        {
                            Total_Sum = 255;
                        }

                        image[i][j].n = Total_Sum;
                    }
                }
            }
        }
    }
    return;
}














//printf("I am in edges");

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

                   //Calculate Gx values for red channel
                   Sum1 = (-1) * image[i + h][j + w].rgbtRed + 0 * image[i + h][j + (w + 1)].rgbtRed + 1 * image[i + h][j + (w + 2)].rgbtRed;
                   Sum2 = (-2) * image[i + (h + 1)][j + w].rgbtRed + 0 * image[i + (h + 1)][j + (w + 1)].rgbtRed + 2 * image[i + (h + 1)][j + (w + 2)].rgbtRed;
                   Sum3 = (-1) * image[i + (h + 2)][j + w].rgbtRed + 0 * image[i + (h + 2)][j + (w + 1)].rgbtRed + 1 * image[i + (h + 2)][j + (w + 2)].rgbtRed;

                   Sum_Red_X = Sum1 + Sum2 + Sum3;

                   //Calculate Gy values for red channel
                   Sum1 = (-1) * image[i + h][j + w].rgbtRed + (-2) * image[i + h][j + (w + 1)].rgbtRed + (-1) * image[i + h][j + (w + 2)].rgbtRed;
                   Sum2 = 0;
                   Sum3 = 1 * image[i + (h + 2)][j + w].rgbtRed + 2 * image[i + (h + 2)][j + (w + 1)].rgbtRed + 1 * image[i + (h + 2)][j + (w + 2)].rgbtRed;

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
                   Sum1 = (-1) * image[i + h][j + w].rgbtGreen + (-2) * image[i + h][j + (w + 1)].rgbtGreen + (-1) * image[i + h][j + (w + 2)].rgbtGreen;
                   Sum2 = 0;
                   Sum3 = 1 * image[i + (h + 2)][j + w].rgbtGreen + 2 * image[i + (h + 2)][j + (w + 1)].rgbtGreen + 1 * image[i + (h + 2)][j + (w + 2)].rgbtGreen;

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
                   Sum1 = (-1) * image[i + h][j + w].rgbtBlue + (-2) * image[i + h][j + (w + 1)].rgbtBlue + (-1) * image[i + h][j + (w + 2)].rgbtBlue;
                   Sum2 = 0;
                   Sum3 = 1 * image[i + (h + 2)][j + w].rgbtBlue + 2 * image[i + (h + 2)][j + (w + 1)].rgbtBlue + 1 * image[i + (h + 2)][j + (w + 2)].rgbtBlue;

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

          /*  int sum_Xred;
            int sum_Xblue;
            int sum_Xgreen;
            int sum_Yred;
            int sum_Ygreen;
            int sum_Yblue;
            int Total_SumRed;
            int Total_SumGreen;
            int Total_SumBlue;

            sum_Xred = sum_Xblue = sum_Xgreen = sum_Yred = sum_Ygreen = sum_Yblue = Total_SumRed = Total_SumGreen = Total_SumBlue = 0;

            //Calculate the values for corners
            if ( i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
            {
               sum_Xred = 0 * image[i][j].rgbtRed + 1 * image[i + 1][j].rgbtRed + 0 * image[i + 1][j + 1].rgbtRed + 2 * image[i + 2][j + 1].rgbtRed;
               sum_Xgreen = 0 * image[i][j].rgbtGreen + 1 * image[i + 1][j].rgbtGreen + 0 * image[i + 1][j + 1].rgbtGreen + 2 * image[i + 2][j + 1].rgbtGreen;
               sum_Xblue = 0 * image[i][j].rgbtBlue + 1 * image[i + 1][j].rgbtBlue + 0 * image[i + 1][j + 1].rgbtBlue + 2 * image[i + 2][j + 1].rgbtBlue;

               //total_sumx = sum_red + sum_green + sum_blue;

               sum_Yred = (-2) * image[i][j].rgbtRed + (-1) * image[i][j].rgbtRed + 0 * image[i + 1][j + 1].rgbtRed + 0 * image[i + 2][j + 1].rgbtRed;
               sum_Ygreen = (-2) * image[i][j].rgbtGreen + (-1) * image[i][j].rgbtGreen + 0 * image[i + 1][j + 1].rgbtGreen + 0 * image[i + 2][j + 1].rgbtGreen;
               sum_Yblue = (-2) * image[i][j].rgbtBlue + (-1) * image[i][j].rgbtBlue + 0 * image[i + 1][j + 1].rgbtBlue + 0 * image[i + 2][j + 1].rgbtBlue;

               //total_sum = sum_red + sum_green + sum_blue;

               Total_SumRed = round (sqrt( sum_Xred ^ 2 + sum_Yred ^ 2));
               Total_SumGreen = round (sqrt( sum_Xgreen ^ 2 + sum_Ygreen ^ 2));
               Total_SumBlue = round (sqrt( sum_Xblue ^ 2 + sum_Yblue ^ 2));

               if (Total_SumRed < 0 || Total_SumGreen < 0 || Total_SumBlue < 0)
               {
                   Total_SumRed = 0;
                   Total_SumGreen = 0;
                   Total_SumBlue = 0;
               }

               else if (Total_SumRed > 255 || Total_SumGreen > 255 || Total_SumBlue > 255)
               {
                   Total_SumRed = 255;
                   Total_SumGreen = 255;
                   Total_SumBlue = 255;
               }

               image[i][j].rgbtRed = Total_SumRed;
               image[i][j].rgbtGreen = Total_SumGreen;
               image[i][j].rgbtBlue = Total_SumBlue;

            } */
        }

    }



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
        Total_Sum_Red = round( sqrt( ( Sum_Red_X ^ 2) + (Sum_Red_Y ^ 2) ) );

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