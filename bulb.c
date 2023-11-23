#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function prototype
void printBulb(int bit);

int main(void)
{
    // Get message from user
    string message = get_string("Please Enter Your Message: ");

    // Loop through each char
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        // Get the ASCII value of char
        int ascii_value = (int) message[i];
        // Convert the ASCII value to an 8-bit binary
        for (int j = 7; j >= 0; j--)
        {
            // Extract the j-th bit of the ASCII value
            int bit = (ascii_value >> j) & 1;

            // Print the bulb emoji for each bit. If the bit is 0 it is print dark other way it is print light bulb.
            printBulb(bit);
        }

        // Print a newline after each 8-bit
        printf("\n");
    }

    return 0;
}

// Function to print the bulb emoji based on the bit value
void printBulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
