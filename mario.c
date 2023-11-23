#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int pyramidHeight;

    // Get the pyramid height from user
    do
    {
        pyramidHeight = get_int("Pyramid Height: ");
    }
    while (pyramidHeight < 1 || pyramidHeight > 8);

    // Building pyramid
    for (int i = 0; i < pyramidHeight; i++)
    {
        // Add space for each row to make pyramid right sided
        for (int j = 0; j < pyramidHeight - i - 1; j++)
        {
            printf(" ");
        }

        // Add hashes to build pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Move to next line
        printf("\n");
    }
    return 0;
}
