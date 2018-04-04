#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get User Input

    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);

    // Print Pyramid

    for (int i = 0; i < height; i++)
    {
        // Print left side
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (int k = height - i; k <= height; k++)
        {
            printf("#");
        }

        // Print gap
        printf("  ");

        // Print right side
        for (int k = height - i; k <= height; k++)
        {
            printf("#");
        }

        // New line
        printf("\n");
    }
}