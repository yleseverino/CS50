#include "helpers.h"
#include <math.h>

int myround(double n);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = image[i][j].rgbtBlue;
            average = average + image[i][j].rgbtGreen;
            average = (average + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            temp = image[i][j];

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE final[height][width];
    int counter;
    int sumR;
    int sumB;
    int sumG;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {


            // Finding the number of the pixels
            //if ((i == 0 && j == 0) || (i == 0 && j == width - 1) || (i == height - 1 && j == width - 1) || (i == height - 1 && j == 0)) counter = 4;
            //else if (j - 1 < 0 || i - 1 < 0 || j + 1 > width || i + 1 > height) counter = 5;
            //else counter = 9;

            sumB = image[i][j].rgbtBlue;
            sumG = image[i][j].rgbtGreen;
            sumR = image[i][j].rgbtRed;


            counter = 1;



            if (j > 0)
            {
                sumB += image[i][j - 1].rgbtBlue;
                sumG += image[i][j - 1].rgbtGreen;
                sumR += image[i][j - 1].rgbtRed;
                counter++;
            }

            if (j + 1 < width)
            {
                sumB += image[i][j + 1].rgbtBlue;
                sumG += image[i][j + 1].rgbtGreen;
                sumR += image[i][j + 1].rgbtRed;
                counter++;
            }

            if (i > 0)
            {
                sumB += image[i - 1][j].rgbtBlue;
                sumG += image[i - 1][j].rgbtGreen;
                sumR += image[i - 1][j].rgbtRed;
                counter++;
            }

            if (i + 1 < height)
            {
                sumB += image[i + 1][j].rgbtBlue;
                sumG += image[i + 1][j].rgbtGreen;
                sumR += image[i + 1][j].rgbtRed;
                counter++;
            }

            if (i + 1 < height && j + 1 < width)
            {
                sumB += image[i + 1][j + 1].rgbtBlue;
                sumG += image[i + 1][j + 1].rgbtGreen;
                sumR += image[i + 1][j + 1].rgbtRed;
                counter++;
            }

            if (i + 1 < height && j > 0)
            {
                sumB += image[i + 1][j - 1].rgbtBlue;
                sumG += image[i + 1][j - 1].rgbtGreen;
                sumR += image[i + 1][j - 1].rgbtRed;
                counter++;
            }

            if (i - 1 >= 0 && j > 0)
            {
                sumB += image[i - 1][j - 1].rgbtBlue;
                sumG += image[i - 1][j - 1].rgbtGreen;
                sumR += image[i - 1][j - 1].rgbtRed;
                counter++;
            }

            if (i > 0 && j + 1 < width)
            {
                sumB += image[i - 1][j + 1].rgbtBlue;
                sumG += image[i - 1][j + 1].rgbtGreen;
                sumR += image[i - 1][j + 1].rgbtRed;
                counter++;
            }

            final[i][j].rgbtBlue = round((float) sumB / (float) counter);
            final[i][j].rgbtGreen = round((float) sumG / (float) counter);
            final[i][j].rgbtRed = round((float) sumR / (float) counter);

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = final[i][j];

        }
    }

}


void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE final[height][width];

    int rx, gx, bx, ry, gy, by;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rx = 0;
            gx = 0;
            bx = 0;
            ry = 0;
            gy = 0;
            by = 0;


            // i - 1
            if (i > 0)
            {
                ry += -2 * image[i - 1][j].rgbtRed;
                gy += -2 * image[i - 1][j].rgbtGreen;
                by += -2 * image[i - 1][j].rgbtBlue;
            }

            // i + 1
            if (i < height - 1)
            {

                ry += 2 * image[i + 1][j].rgbtRed;
                gy += 2 * image[i + 1][j].rgbtGreen;
                by += 2 * image[i + 1][j].rgbtBlue;
            }

            // j - 1
            if (j > 0)
            {
                rx += -2 * image[i][j - 1].rgbtRed;
                gx += -2 * image[i][j - 1].rgbtGreen;
                bx += -2 * image[i][j - 1].rgbtBlue;

            }

            // j + 1
            if (j < height - 1)
            {
                rx += 2 * image[i][j + 1].rgbtRed;
                gx += 2 * image[i][j + 1].rgbtGreen;
                bx += 2 * image[i][j + 1].rgbtBlue;

            }

            //i -1 and j -1
            if (i > 0 && j > 0)
            {
                rx += -1 * image[i - 1][j - 1].rgbtRed;
                gx += -1 * image[i - 1][j - 1].rgbtGreen;
                bx += -1 * image[i - 1][j - 1].rgbtBlue;

                ry += -1 * image[i - 1][j - 1].rgbtRed;
                gy += -1 * image[i - 1][j - 1].rgbtGreen;
                by += -1 * image[i - 1][j - 1].rgbtBlue;
            }

            // i - 1 and j + 1
            if (i > 0 && j < width - 1)
            {
                rx += 1 * image[i - 1][j + 1].rgbtRed;
                gx += 1 * image[i - 1][j + 1].rgbtGreen;
                bx += 1 * image[i - 1][j + 1].rgbtBlue;

                ry += -1 * image[i - 1][j + 1].rgbtRed;
                gy += -1 * image[i - 1][j + 1].rgbtGreen;
                by += -1 * image[i - 1][j + 1].rgbtBlue;
            }

            // i + 1 and j + 1
            if (i < height - 1  && j < width - 1)
            {
                rx += 1 * image[i + 1][j + 1].rgbtRed;
                gx += 1 * image[i + 1][j + 1].rgbtGreen;
                bx += 1 * image[i + 1][j + 1].rgbtBlue;

                ry += 1 * image[i + 1][j + 1].rgbtRed;
                gy += 1 * image[i + 1][j + 1].rgbtGreen;
                by += 1 * image[i + 1][j + 1].rgbtBlue;
            }

            // i + 1 and j - 1
            if (i < height - 1  && j > 0)
            {
                rx += -1 * image[i + 1][j - 1].rgbtRed;
                gx += -1 * image[i + 1][j - 1].rgbtGreen;
                bx += -1 * image[i + 1][j - 1].rgbtBlue;

                ry += 1 * image[i + 1][j - 1].rgbtRed;
                gy += 1 * image[i + 1][j - 1].rgbtGreen;
                by += 1 * image[i + 1][j - 1].rgbtBlue;
            }


            //cheking if value is greater than 255
            rx = (round(sqrt((rx * rx) + (ry * ry))) > 255) ? 255 : round(sqrt((rx * rx) + (ry * ry)));
            gx = (round(sqrt((gx * gx) + (gy * gy))) > 255) ? 255 : round(sqrt((gx * gx) + (gy * gy)));
            bx = (round(sqrt((bx * bx) + (by * by))) > 255) ? 255 : round(sqrt((bx * bx) + (by * by)));


            final[i][j].rgbtRed = rx;
            final[i][j].rgbtGreen = gx;
            final[i][j].rgbtBlue = bx;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = final[i][j];
        }
    }


}