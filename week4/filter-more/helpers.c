#include "helpers.h"
#include <math.h>

int temp;



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avgValue;
    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            avgValue = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtBlue = avgValue;
            image[i][j].rgbtRed = avgValue;
            image[i][j].rgbtGreen = avgValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0;i<height;i++){
        for(int j =0;j<(width/2);j++){
            // Red
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-1-j].rgbtRed;
            image[i][width-1-j].rgbtRed = temp;
            // Blue
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-1-j].rgbtBlue;
            image[i][width-1-j].rgbtBlue = temp;
            // Green
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtGreen = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];


    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            copy[i][j] = image[i][j];
        }
    }
    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            double inbound = 0.0;
            for(int n = i - 1; n<= i+1;n++){ // inside 3x3 box
                for(int k = j-1;k<=j+1;k++){
                    if(n>=0 && n < height && k>=0 && k<width){
                        sumRed += copy[n][k].rgbtRed;
                        sumGreen += copy[n][k].rgbtGreen;
                        sumBlue += copy[n][k].rgbtBlue;
                        inbound++;
                    }
                }
            }

            image[i][j].rgbtRed = round(sumRed/inbound);
            image[i][j].rgbtGreen = round(sumGreen/inbound);
            image[i][j].rgbtBlue = round(sumBlue/inbound);
        }
    }
}

void weightedSum(int height, int width, RGBTRIPLE image[height][width]){

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            copy[i][j] = image[i][j];
        }
    }

    int kernelX[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int kernelY[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    // sums of the channel's values
    int red; int blue; int green;




    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
             double GxRed = 0, GxGreen = 0, GxBlue = 0;
             double GyRed = 0, GyGreen = 0, GyBlue = 0;
             int icount = 0, jcount = 0;
            for(int n = i-1; n<=i+1;n++){ // inside 3x3 loop
                for(int k = j-1;k<=j+1;k++){
                    if(n>=0 && n < height && k>=0 && k<width){
                        red = copy[n][k].rgbtRed;
                        green = copy[n][k].rgbtGreen;
                        blue = copy[n][k].rgbtBlue;

                        GxRed += kernelX[icount][jcount]*red;
                        GxGreen += kernelX[icount][jcount]*green;
                        GxBlue += kernelX[icount][jcount]*blue;

                        GyRed += kernelY[icount][jcount]*red;
                        GyGreen += kernelY[icount][jcount]*green;
                        GyBlue += kernelY[icount][jcount]*blue;
                    }
                    jcount++;
                    }
                    icount++;
                    jcount=0;
                }


                int rootRed = fmin(round(sqrt(GxRed*GxRed+GyRed*GyRed)),255);
                int rootGreen = fmin(round(sqrt(GxGreen*GxGreen+GyGreen*GyGreen)),255);
                int rootBlue = fmin(round(sqrt(GxBlue*GxBlue+GyBlue*GyBlue)),255);

                image[i][j].rgbtRed = rootRed;
                image[i][j].rgbtGreen = rootGreen;
                image[i][j].rgbtBlue = rootBlue;

        }
    }
    return;
}

