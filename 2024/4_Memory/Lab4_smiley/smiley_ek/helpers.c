#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // N.B. doesn't work to set px = image[i][j], because then we're only modifying px,
    // which is a copy of image[i][i], not the image itself.

    // iterate over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // turn black pixels to pink
            // since pixels are either black or white, only need to check one color channel to determine which
            if (image[i][j].rgbtRed == 0)
            {
                image[i][j].rgbtRed = 212;
                image[i][j].rgbtBlue = 106;
                // want green = 0, which is already the case
            }
        }
    }
    // Change all black pixels to a color of your choosing
}
